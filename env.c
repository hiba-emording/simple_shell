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
		_printerr("setenv: Failed to set environment variable", NULL);
		return (1);
	}
}

#include "main.h"

/**
 * _getenv - Get the value of an environment variable.
 * @name: The name of the environment variable to retrieve.
 *
 * Return: The value of the environment variable, or NULL if not found.
 */
char *_getenv(const char *name)
{
unsigned int i = 0;
char *value;

	while (environ[i] != NULL)
	{
		if (_strncmp(environ[i], name, _strlen(name)) == 0)
		{
			value = _strchr(environ[i], '=');

			if (value != NULL)
				return (_strdup(value + 1));
		}
		i++;
	}
	return (NULL);
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
