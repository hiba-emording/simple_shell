#include "main.h"

/**
 * _operator - Handles shell operators &&, ||, and ;
 * @args: Array of tokenized command-line arguments
 * @i: Index of the current arg in the 'args' array
 *
 * Return: 0 for success, 1 otherwise
 */

int _operator(char **args, int i)
{
int result;

	if (_strcmp(args[i], "&&") == 0)
	{
		result = fork_exec(args + i - 1);

		if (result == 0)
		{
			return (0);
		}
		return (1);
	}

	else if (_strcmp(args[i], "||") == 0)
	{
		result = fork_exec(args + i - 1);

		if (result != 0)
		{
			return (0);
		}
		return (1);
	}

	else if (_strcmp(args[i], ";") == 0)
	{
		fork_exec(args + i - 1);
		return (0);
	}

	return (1);
}
