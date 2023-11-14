#include "main.h"

/**
   * execute - Execute a linked list of commands
   * @cmd: The linked list of commands
   * @path: The linked list of paths
   * @last_exit_status: The exit status of the last command
   * Return: The exit status of the last command
   */
int execute(cmd_link **cmd, path_link *path, int *last_exit_status)
{
    int code = 0, strict;
    cmd_link *tmp;

    while (*cmd)
    {
        code = exec_cmd(*cmd, path, last_exit_status);
		strict = (*cmd)->strict;

        /* free the executed command node and move head to next */
        tmp = *cmd;
        *cmd = (*cmd)->next;
        tmp->next = NULL;
        free_commands(tmp);

        if (code != 0 && *cmd)
        {
            if (strict == 4)
                break;
        }
        else if (*cmd)
        {
            if (strict == 3)
                break;
        }

        if (*cmd && strict == 1)
            break;
    }

	if (*cmd)
		free_commands(*cmd);

    return (code);
}

/**
 * exec_cmd - Execute a command with args
 * @args: Array of tokenized args
 * @path: pointer to head of path list
 * @last_exit_status: pointer to last exit status
 * Return: 0 on success, 1 otherwise
 */
int exec_cmd(cmd_link *cmd, path_link *path, int *last_exit_status)
{
	int code;

    if (cmd->command == NULL) 
        return (1);

    switch_vars(cmd->command, last_exit_status);

    if ((code = exec_builtin(cmd, path)) != -1) 
    {
        *last_exit_status = code;
        return (*last_exit_status);
    }
    else if (!find_path(cmd->command, path))
    {
		*last_exit_status = fork_exec(cmd->command);
		return (*last_exit_status);
    }
    else if (access(cmd->command[0], F_OK | R_OK) != -1) 
    {
        *last_exit_status = exec_file(cmd->command, path, last_exit_status);
        return (*last_exit_status);
    }

    return (1);
}

/**
  * exec_builtin - execute builtin commands
  * @cmd: command passed
  * @path: linked list of paths
  * Return: 0 on success
  */
int exec_builtin(cmd_link *cmd, path_link *path)
{
	if (_strcmp(cmd->command[0], "exit") == 0)
	{
		exit_state(cmd, path);
	}
	if (_strcmp(cmd->command[0], "env") == 0)
	{
		print_env();
		return (0);
	}
	if (_strcmp(cmd->command[0], "setenv") == 0)
	{
		return (_setenv(cmd->command[1], cmd->command[2]));
	}
	if (_strcmp(cmd->command[0], "unsetenv") == 0)
	{
		return (_unsetenv(cmd->command[1]));
	}
	if (_strcmp(cmd->command[0], "cd") == 0)
	{
		return (_cd(cmd->command));
	}

	return (-1);
}

/**
  * exec_file - execute commands in a file
  * @args: commands passed
  * @path: linked list of paths
  * @last_exit_status - last exit status
  * Return: 0 on success
  */
int exec_file(char **args, path_link *path, int *last_exit_status)
{
	char *line = NULL;
	cmd_link *command;
	ssize_t read;
	int fd;

	fd = open(args[0], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (-1);
	}

	while ((read = _fgetline(&line, fd)) != -1)
	{
		command = parse_commands(line);
		if (command == NULL)
		{
			*last_exit_status = -1;
			break;
		}
		*last_exit_status = execute(&command, path, last_exit_status);
		free(command);
		if (*last_exit_status != 0)
			break;
	}

	free(line);
	close(fd);
	return (*last_exit_status);
}

/**
  * _fgetline - reads an entire line from file descriptor
  * @lineptr: pointer to the buffer containing the read bytes
  * @fd: file descriptor to read from
  * Return: number of characters read including the delimiting character
  * but not including the terminating null byte
  */
ssize_t _fgetline(char **lineptr, int fd)
{
	int count = 0, size = 100;
	char *tmp, *buf, *c = malloc(sizeof(char));

	if (!lineptr || !c)
		return (-1);
	if (!(*lineptr))
	{
		tmp = realloc((*lineptr), (sizeof(char) * size));
		if (!tmp)
			return (-1);
		*lineptr = tmp;
	}
	buf = *lineptr;
	while (read(fd, c, 1) > 0)
	{
		buf[count++] = *c;
		if (count >= size)
		{
			size *= 2;
			tmp = realloc((*lineptr), (sizeof(char) * size));
			if (!tmp)
				return (-1);
			*lineptr = tmp;
		}
		buf = *lineptr;
		if (*c == '\n')
			break;
	}

	buf[count++] = '\0';
	free(c);

	return (count);
}


/**
  * fork_exec - create a fork and execute command
  * @args: commands passed
  */
int fork_exec(char **args)
{
		pid_t child = fork();

		if (child == -1)
		{
			perror("fork");
			return (1);
		}

		if (child == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("execve");
				exit(0);
			}
		}
		else
		{
			wait(NULL);
		}

	return (0);
}

/**
  * exit_state - exit shell in a specified state
  * @cmd: commands linked list
  * @path: linked list of paths
  */
void exit_state(cmd_link *cmd, path_link *path)
{
	int code =  (cmd->command[1]) ? _atoi(cmd->command[1]) : 0;

	free_paths(&path);
	free_commands(cmd);
	exit(code);
}
