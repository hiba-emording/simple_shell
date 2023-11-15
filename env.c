#include "main.h"

/**
 * print_env - Print environment variables.
 *
 */
void print_env(void)
{
unsigned int i = 0;

	while (environ[i])
	{
		_print(environ[i]);
		_printchar('\n');
		i++;
	}
}

/**
 * _setenv - Set a new env variable or modify.
 * @var: Name of the env variable.
 * @value: Value to set for the env variable.
 * Return: 0 on success, or 1 on failure.
 */
int _setenv(const char *var, const char *value)
{
	int code = 0;

	if (var == NULL || value == NULL)
	{
		return (1);
	}

	if (setenv(var, value, 1) == 0)
	{
		return (code);
	}
	else
	{
		_printerr("setenv", "Failed to set environment variable");
		return (1);
	}
}

/**
 * _unsetenv - Remove env variable.
 * @var: Name of the env variable.
 * Return: 0 on success, or 1 on failure.
 */

int _unsetenv(const char *var)
{
	int code = 0;

	if (unsetenv(var) == 0)
	{
		return (code);
	}
	else
	{
		perror("Failed to unset environment variable");
		return (1);
	}
}
