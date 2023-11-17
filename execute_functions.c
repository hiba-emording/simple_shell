#include "main.h"

/**
   * execute - Execute a linked list of commands
   * @cmd: The linked list of commands
   * @aliases: The linked list of aliases
   * @last_exit_status: The exit status of the last command
   * Return: The exit status of the last command
   */
int execute(cmd_link **cmd, Alias **aliases, int *last_exit_status)
{
	int code = 0, strict;
	cmd_link *tmp;

	while (*cmd)
	{
		if (!(*cmd)->command || !(*cmd)->command[0])
		{
			tmp = *cmd;
			*cmd = (*cmd)->next;
			tmp->next = NULL;
			free_commands(&tmp);
			continue;
		}
		code = exec_cmd(*cmd, aliases, last_exit_status);
		*last_exit_status = code;
		strict = (*cmd)->strict;

		tmp = *cmd;
		*cmd = (*cmd)->next;
		tmp->next = NULL;
		free_commands(&tmp);

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
		free_commands(cmd);
	return (*last_exit_status);
}

/**
 * exec_cmd - Execute a command with args
 * @cmd: Array of tokenized cmds
 * @aliases: pointer to aliases linked list
 * @last_exit_status: pointer to last exit status
 * Return: 0 on success, 1 otherwise
 */
int exec_cmd(cmd_link *cmd, Alias **aliases, int *last_exit_status)
{
	int code;

	if (cmd->command == NULL)
		return (1);

	switch_vars(cmd->command, last_exit_status);

	code = exec_builtin(cmd, aliases, last_exit_status);
	if (code != -1)
	{
		*last_exit_status = code;
		return (*last_exit_status);
	}
	if (find_path(cmd->command) == 0)
	{
		*last_exit_status = fork_exec(cmd->command);
		return (*last_exit_status);
	}
	if ((access(cmd->command[0], F_OK | R_OK) == 0) &&
		(access(cmd->command[0], X_OK) == -1))
	{
		*last_exit_status = exec_file(cmd->command[0], aliases, last_exit_status);
		return (*last_exit_status);
	}

	_printerr(cmd->command[0], ": not found", "\n", NULL);
	return (127);
}

/**
  * exec_builtin - execute builtin commands
  * @cmd: command passed
  * @aliases: pointer to aliases linked list
  * @last_exit_status: pointer to last exit status
  * Return: 0 on success
  */
int exec_builtin(cmd_link *cmd, Alias **aliases, int *last_exit_status)
{
	if (_strcmp(cmd->command[0], "exit") == 0)
	{
		return (exit_state(cmd, aliases, last_exit_status));
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
	if (_strcmp(cmd->command[0], "alias") == 0)
	{
		return (_alias(aliases, cmd->command));
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
  * @aliases: pointer to aliases linked list
  * @last_exit_status: pointer to last exit status
  * Return: if exit is successful, exit code, otherwise 2
  */
int exit_state(cmd_link *cmd, Alias **aliases, int *last_exit_status)
{
	int code;

	if (cmd->command[1] == NULL)
	{
		code = *last_exit_status;
	}
	else if (!_atoi(cmd->command[1], &code) || code < 0)
	{
		_printerr("exit: Illegal number: ", cmd->command[1], "\n", NULL);
		return (2);
	}

	free_commands(&cmd);
	free_aliases(aliases);
	exit(code);
}
