#include "main.h"

/**
 * _setenv - Set a new env variable or modify.
 * @var: Name of the env variable.
 * @value: Value to set for the env variable.
 *
 * Return: 0 on success, or 1 on failure.
 */


int _setenv(const char *var, const char *value)
{

	if (setenv(var, value, 1) == 0)
	{
		return (0);
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
 *
 * Return: 0 on success, or 1 on failure.
 */

int _unsetenv(const char *var)
{

	if (unsetenv(var) == 0)
	{
		return (0);
	}
	else
	{
		perror("Failed to unset environment variable");
		return (1);
	}
}
