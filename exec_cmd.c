#include "main.h"

/**
 * exec_cmd - Execute a command with args.
 * @args: Array of tokenized args.
 * @path: pointer to head of path list.
 * @last_exit_status: Pointer to the last exit status.
 *
 * Return: 0 on success, 1 otherwise.
 */

int exec_cmd(char **args, path_link *path, int *last_exit_status)
{
int i;

	if (args == NULL || args[0] == NULL)
	{
		perror("Null arguments provided\n");
		return (1);
	}
	for (i = 0; args[i] != NULL; i++)
	{
		switch_vars(args, last_exit_status);

		if (_operator(args, i) == 0)
		{
			continue;
		}
		if (_builtin(args[0]))
		{
			ExecBuiltinArgs builtin_args;

			builtin_args.args = args;
			builtin_args.path = path;

			if (_strcmp(args[0], "setenv") == 0 || _strcmp(args[0], "unsetenv") == 0)
			{
				builtin_args.var = args[i + 1];
				builtin_args.value = args[i + 2];
			}
			exec_builtin(&builtin_args);
		}
		else
		{
			if (!find_path(args + i, path))
				fork_exec(args + i);
			else
				perror("Could not access file or directory");
		}
	}
	return (0);
}

/**
  * fork_exec - create a fork and execute command
  * @args: commands passed
  * Return: 0 on success
  */

int fork_exec(char **args)
{
		pid_t child = fork();

		if (child == -1)
		{
			perror("fork");
			return (-1);
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
			wait(NULL);
		}
		return (0);
}

/**
  * exit_state - exit shell in a specified state
  * @args: commands passed
  * @path: linked list of paths
  * @code: exit code given
  */

void exit_state(char **args, path_link *path, int code)
{
	free_paths(&path);
	free_tokenargs(args);
	exit(code);
}

