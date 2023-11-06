#include "main.h"

/**
 * _getenv - Get the value of an environment variable.
 * @name: The name of the environment variable to retrieve.
 *
 * Return: The value of the environment variable, or NULL if not found.
 */

char *_getenv(const char *name)
{
int i = 0;
char *value;

	if (name == NULL)
	{
		return (NULL);
	}

	while (environ[i] != NULL)
	{
		if (_strncmp(environ[i], name, _strlen(name)) == 0)
		{
			value = _strchr(environ[i], '=');

			if (value != NULL)
			{
				if (value[1] != '\0')
				{
					return (value + 1);
				}
			}
		}
		i++;
	}
	return (NULL);
}
