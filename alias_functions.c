#include "main.h"

/**
 * print_alias_all - Print all aliases to stdout.
 * @alias: The head of the linked list of aliases.
 */
void print_alias_all(Alias *alias)
{
	while (alias != NULL)
	{
		_print(alias->name);
		_printchar('=');
		_print("'");
		_print(alias->value);
		_print("'\n");
		alias = alias->next;
	}
}

/**
 * print_alias_one - Print specific aliases to stdout.
 * @alias: The head of the linked list of aliases.
 * @name: alias name to print.
 */
void print_alias_one(Alias *alias, char *name)
{
	while (alias != NULL)
	{
		if (_cstrcmp(alias->name, name) == 0)
		{
			_print(alias->name);
			_printchar('=');
			_print("'");
			_print(alias->value);
			_print("'\n");
			return;
		}
		alias = alias->next;
	}

	_printerr("alias: ", name, ": not found\n", NULL);
}

/**
 * define_alias - Define or update alias.
 * @alias: Pointer to the head of the linked list of aliases.
 * @name: Name of the alias.
 * @value: Value associated with the alias.
 */
void define_alias(Alias **alias, const char *name, const char *value)
{
	Alias *temp = *alias, *new = NULL;

	while (temp != NULL)
	{
		if (_cstrcmp(temp->name, name) == 0)
		{
			if (temp->value != NULL)
				free(temp->value);
			temp->value = _strdup(value);
			return;
		}
		temp = temp->next;
	}

	new = malloc(sizeof(Alias));
	new->name = _strdup(name);
	new->value = _strdup(value);
	new->next = *alias;
	*alias = new;
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
	Alias *temp, *head, *prev;

	if (*alias == NULL)
		return (1);

	head = *alias;
	prev = NULL;

	while (head != NULL)
	{
		if (_cstrcmp(head->name, name) == 0)
		{
			temp = head;
			head = head->next;
			if (prev != NULL)
				prev->next = head;

			free(temp->name);
			free(temp->value);
			free(temp);

			return (0);
		}
		prev = head;
		head = head->next;
	}

	return (1);
}


/**
 * free_aliases - Free allocated memory for aliases.
 * @alias: Pointer to the head of the linked list of aliases.
 */
void free_aliases(Alias **alias)
{
	Alias *temp;

	while (*alias != NULL)
	{
		temp = *alias;
		*alias = (*alias)->next;
		free(temp->name);
		free(temp->value);
		free(temp);
	}
}
