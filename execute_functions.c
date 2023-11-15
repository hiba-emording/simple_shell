#include "main.h"

/**
   * execute - Execute a linked list of commands
   * @cmd: The linked list of commands
   * @path: The linked list of paths
   * @last_exit_status: The exit status of the last command
   * Return: The exit status of the last command
   */
int execute(cmd_link **cmd, path_link **path, int *last_exit_status)
{
	int code = 0, strict;
	cmd_link *tmp;

	while (*cmd)
	{
		if (!(*cmd)->command || !(*cmd)->command[0])
			break;

		code = exec_cmd(*cmd, path, last_exit_status);
		*last_exit_status = code;
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
	return (*last_exit_status);
}

/**
 * exec_cmd - Execute a command with args
 * @cmd: Array of tokenized cmds
 * @path: pointer to head of path list
 * @last_exit_status: pointer to last exit status
 * Return: 0 on success, 1 otherwise
 */
int exec_cmd(cmd_link *cmd, path_link **path, int *last_exit_status)
{
	int code;

	if (cmd->command == NULL)
		return (1);

	switch_vars(cmd->command, last_exit_status);

	code = exec_builtin(cmd, path);
	if (code != -1)
	{
		*last_exit_status = code;
		return (*last_exit_status);
	}
	if (!find_path(cmd->command, *path))
	{
		*last_exit_status = fork_exec(cmd->command);
		return (*last_exit_status);
	}
	/* file input to be done here using file descriptor */
	code = open(cmd->command[0], O_RDONLY);
	if (code != -1)
	{
		*last_exit_status = exec_file(cmd->command, path, last_exit_status);
		return (*last_exit_status);
	}

	perror(cmd->command[0]);
	return (127);
}

/**
  * exec_builtin - execute builtin commands
  * @cmd: command passed
  * @path: linked list of paths
  * Return: 0 on success
  */
int exec_builtin(cmd_link *cmd, path_link **path)
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
		return (_setenv(cmd->command[1], cmd->command[2], path));
	}
	if (_strcmp(cmd->command[0], "unsetenv") == 0)
	{
		return (_unsetenv(cmd->command[1], path));
	}
	if (_strcmp(cmd->command[0], "cd") == 0)
	{
		return (_cd(cmd->command, path));
	}


	return (-1);
}

/**
  * fork_exec - create a fork and execute command
  * @args: commands passed
  * Return: exit status
  */
int fork_exec(char **args)
{
	int status = 0;
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
			exit(1);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}

	return (1);
}

/**
  * exit_state - exit shell in a specified state
  * @cmd: commands linked list
  * @path: linked list of paths
  */
void exit_state(cmd_link *cmd, path_link **path)
{
	int code =  (cmd->command[1]) ? _atoi(cmd->command[1]) : 0;

	free_paths(path);
	free_commands(cmd);

	if (code < 0)
	{
		perror("Illegal number");
	}
	exit(code);
}
