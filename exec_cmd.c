#include "main.h"

/**
 * exec_cmd - Execute a command with args.
 * @args: Array of tokenized args.
 *
 */

void exec_cmd(char **args, path_link *path)
{
	if (args == NULL || args[0] == NULL)
	{
		return;
	}

	if (_strcmp(args[0], "exit") == 0)
	{
		/* handle special exit statuses */
		exit(0);
	}

	else if (_strcmp(args[0], "env") == 0)
	{
		/* handle printing env like normal sh */
		handle_env();
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
  * @args: commands passed */
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
			if(execve(args[0], args, NULL) == -1)
				printf("Couldn't execute command\n");
			exit(0);
		}
		else
		{
			wait(NULL);
		}
}
