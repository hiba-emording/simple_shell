#include "main.h"

/**
 * exec_cmd - Execute a command with args.
 * @args: Array of tokenized args.
 * @path: pointer to head of path list
 */

void exec_cmd(char **args, path_link *path)
{
int stat;

	if (args == NULL || args[0] == NULL)
	{
		return;
	}

	if (_strcmp(args[0], "exit") == 0)
	{
		if (args[1] != NULL)
		{
			stat = _atoi(args[1]);
			exit(stat);
		}
		else
		{
			exit(0);
		}
	}

	else if (_strcmp(args[0], "env") == 0)
	{
		/* handle printing env like normal sh */
		print_env();
	}

	else if (_strcmp(args[0], "_setenv") == 0)
	{
		_setenv(args[1], args[2]);
	}
	else if (_strcmp(args[0], "_unsetenv") == 0)
	{
		_unsetenv(args[1]);
	}
	else if (_strcmp(args[0], "cd") == 0)
	{
		_cd(args);
	}

	else
	{
		if (!find_path(args, path))
			fork_exec(args);
		else
			_printer("Could not access file or directory\n");
	}
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
			printf("Couldn't create process\n");
			exit(1);
		}

		if (child == 0)
		{
			if (execve(args[0], args, NULL) == -1)
				printf("Couldn't execute command\n");
			exit(0);
		}
		else
		{
			wait(NULL);
		}
}
