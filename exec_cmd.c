#include "main.h"

/**
 * exec_cmd - Execute a command with args.
 * @args: Array of tokenized args.
 * @path: pointer to head of path list
 *
 * Return: 1 if an exit is requested, 0 otherwise (on failure too)
 */

int exec_cmd(char **args, path_link *path)
{

	if (args == NULL || args[0] == NULL)
		return (0);

	if (_strcmp(args[0], "exit") == 0)
		return (1);
	else if (_strcmp(args[0], "env") == 0)
		print_env();
	else if (_strcmp(args[0], "_setenv") == 0)
		_setenv(args[1], args[2]);
	else if (_strcmp(args[0], "_unsetenv") == 0)
		_unsetenv(args[1]);
	else if (_strcmp(args[0], "cd") == 0)
		_cd(args);
	else
	{
		if (!find_path(args, path))
			fork_exec(args);
		else
			 perror("Could not access file or directory");
	}

	return (0);
}

/**
  * fork_exec - create a fork and execute command
  * @args: commands passed
  */

void fork_exec(char **args)
{
		pid_t child = fork();

		if (child == -1)
		{
			perror("fork");
			exit(1);
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
}
