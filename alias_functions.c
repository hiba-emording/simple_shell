#include "main.h"

/**
 * print_all - Print all aliases to stdout.
 * @alias: The head of the linked list of aliases.
 */
void print_all(Alias *alias)
{
	while (alias != NULL)
	{
		_printer(alias->name);
		_printchar('=');
		_printer("'");
		_printer(alias->value);
		_printer("'\n");
		alias = alias->next;
	}
}

/**
 * print_spec - Print specific aliases to stdout.
 * @alias: The head of the linked list of aliases.
 * @alias_names: Array of alias names to print.
 */

void print_spec(Alias *alias, char *alias_names[])
{
int i;

	while (alias != NULL)
	{
		for (i = 0; alias_names[i] != NULL; i++)
		{
			if (_strcmp(alias_names[i], alias->name) == 0)
			{
				_printer(alias->name);
				_printchar('=');
				_printer("'");
				_printer(alias->value);
				_printer("'\n");
				break;
			}
		}
		alias = alias->next;
	}
}

/**
 * define_alias - Define or update alias.
 * @alias: Pointer to the head of the linked list of aliases.
 * @name: Name of the alias.
 * @value: Value associated with the alias.
 */

void define_alias(Alias **alias, const char *name, const char *value)
{

	while (*alias != NULL)
	{
		if (_cstrcmp((*alias)->name, name) == 0)
		{
			free((*alias)->value);
			(*alias)->value = _strdup(value);
			return;
		}
		alias = &(*alias)->next;
	}

	*alias = malloc(sizeof(Alias));
	(*alias)->name = _strdup(name);
	(*alias)->value = _strdup(value);
	(*alias)->next = NULL;
}


/**
 * unset_alias - Unset an alias.
 * @alias: Pointer to the head of the linked list of aliases.
 * @name: Name of the alias to unset.
 *
 * Return: 0 for success, 1 if alias is not found.
 */

int unset_alias(Alias **alias, const char *name)
{
	while (*alias != NULL)
	{
		if (_cstrcmp((*alias)->name, name) == 0)
		{
			Alias *temp = *alias;
			*alias = (*alias)->next;
			free(temp->name);
			free(temp->value);
			free(temp);

			return (0);
		}

		alias = &(*alias)->next;
	}

	return (1);
}


/**
 * free_aliases - Free allocated memory for aliases.
 * @alias: Pointer to the head of the linked list of aliases.
 */

void free_aliases(Alias *alias)
{
	Alias *temp;

	while (alias != NULL)
	{
		temp = alias;
		alias = alias->next;
		free(temp->name);
		free(temp->value);
		free(temp);
	}
}
