#include "main.h"

/**
 * exec_builtin - Execute built-in commands.
 * @builtin_args: Pointer to structure holding command arguments.
 *
 */

void exec_builtin(ExecBuiltinArgs *builtin_args)
{
char *builtin = builtin_args->args[0];

	if (_strcmp(builtin, "exit") == 0)
	{
		exits(builtin_args->args, builtin_args->path);
	}

	else if (_strcmp(builtin, "env") == 0)
	{
		print_env();
	}

	else if (_strcmp(builtin, "setenv") == 0)
	{
		_setenv(builtin_args->var, builtin_args->value);
	}

	else if (_strcmp(builtin, "unsetenv") == 0)
	{
		_unsetenv(builtin_args->var);
	}

	else if (_strcmp(builtin, "cd") == 0)
	{
		_cd(builtin_args->args);
	}
}


/**
 * _builtin - Check if a command is a built-in.
 * @cmd: The command to check.
 *
 * Return: 1 for success, 0 otherwise.
 */

int _builtin(char *cmd)
{
char *builtins[] = {"exit", "env", "setenv", "unsetenv", "cd", NULL};
int i;

	for (i = 0; builtins[i] != NULL; i++)
	{
		if (_strcmp(cmd, builtins[i]) == 0)
		{
			return (1);
		}
	}

	return (0);
}
