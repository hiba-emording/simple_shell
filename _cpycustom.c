#include "main.h"

/**
  * _cpycustom - Copy a string, for use in _alias
  * @args: The string to copy
  * @name: name of alias
  * @value: value of alias
  * Return: 0 on success, 1 on failure, -1 if no '=' is found
  */
int _cpycustom(char *args, char **name, char **value)
{
	int j, k;

	for (j = 0; args[j] != '\0'; j++)
	{
		if (args[j] == '=')
		{
			(*name) = malloc(sizeof(char) * (j + 1));
			if ((*name) == NULL)
				return (1);
			for (k = 0; k < j; k++)
			{
				if (args[k] == '"')
				{
					k--;
					continue;
				}
				(*name)[k] = args[k];
			}
			(*name)[k] = '\0';
			(*value) = malloc(sizeof(char) * (_strlen(args) - j));
			if ((*value) == NULL)
			{
				free((*name));
				return (1);
			}
			for (k = 0; args[j + 1] != '\0'; j++, k++)
			{
				if (args[j + 1] == '"')
				{
					k--;
					continue;
				}
				(*value)[k] = args[j + 1];
			}
			(*value)[k] = '\0';
			return (0);
		}
	}
	return (-1);
}
