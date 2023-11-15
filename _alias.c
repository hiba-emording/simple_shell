#include "main.h"

/**
 * _alias - Parse alias command.
 * @alias: Pointer to the head of the linked list of aliases.
 * @args: Array of arguments.
 * Return: 0 for success, 1 for failure.
 */
int _alias(Alias **alias, char **args)
{
	int i, check;
	char *name = NULL, *value = NULL;

	if (args[1] == NULL)
	{
		print_alias_all(*alias);
		return (0);
	}

	for (i = 1; args[i] != NULL; i++)
	{
		check = _cpycustom(args[i], &name, &value);
		if (check == 0)
		{
			define_alias(alias, name, value);
			free(name);
			free(value);
			name = NULL;
			value = NULL;
		}
		else if (check == 1)
			return (1);
		else if (check == -1)
			print_alias_one(*alias, args[i]);
	}
	return (0);
}
