#include "main.h"

/**
 * exec_cmd - Execute a command with args.
 * @args: Array of tokenized args.
 *
 */

void exec_cmd(char **args)
{

	if (args == NULL || args[0] == NULL)
	{
		return;
	}

	if (_strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}

	else if (_strcmp(args[0], "env") == 0)
	{
		handle_env();
	}

	else
	{

		/* get command path function here */

		_printer("We have no exec commands yet");
		_printchar('\n');
	}
}
