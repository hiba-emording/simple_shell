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
		_printer(environ[i]);
		_printchar('\n');
		i++;
	}
}

/**
 * _setenv - Set a new env variable or modify.
 * @var: Name of the env variable.
 * @value: Value to set for the env variable.
 * @path: Pointer to the head of the path linked list.
 * Return: 0 on success, or 1 on failure.
 */


int _setenv(const char *var, const char *value, path_link **path)
{
	int code = 0;

	if (setenv(var, value, 1) == 0)
	{
		if (var[0] == 'P' && var[1] == 'A' && var[2] == 'T' && var[3] == 'H')
			code = update_path(path);
		return (code);
	}
	else
	{
		perror("Failed to set environment variable");
		return (1);
	}
}

/**
 * _unsetenv - Remove env variable.
 * @var: Name of the env variable.
 * @path: Pointer to the head of the path linked list.
 * Return: 0 on success, or 1 on failure.
 */

int _unsetenv(const char *var, path_link **path)
{
	int code = 0;

	if (unsetenv(var) == 0)
	{
		if (var[0] == 'P' && var[1] == 'A' && var[2] == 'T' && var[3] == 'H')
			code = update_path(path);
		return (code);
	}
	else
	{
		perror("Failed to unset environment variable");
		return (1);
	}
}

/**
 * update_path - Update the path linked list.
 * @path: Pointer to the head of the path linked list.
 *
 * Return: 0 on success, or 1 on failure.
 */
int update_path(path_link **path)
{
	free_paths(path);
	*path = NULL;
	if (create_paths(path))
	{
		return (1);
	}
	return (0);
}
