#include "main.h"

/**
 * _strtok - Custom string tokenizer function
 * @s: The input string to be tokenized
 * @d: A string containing delimiter characters
 *
 * Return: A pointer to the next token in the string,
 * or NULL if no more tokens are found.
 */

char *_strtok(char *s, const char *d)
{
	static char *next;
	char *start;
	char *dcp;

	if (d == NULL || *d == '\0')
		return (NULL);

	dcp = _strdup(d);
	if (dcp == NULL)
	{
		_printerr("_strtok", "Failed to allocate memory", NULL);
		return (NULL);
	}

	if (s != NULL)
		next = s;

	while (next != NULL && *next && _strchr(dcp, *next))
		next++;

	if (next == NULL || *next == '\0')
	{
		free(dcp);
		return (NULL);
	}
	start = next;

	while (*next && _strchr(dcp, *next) == NULL)
		next++;

	if (*next)
	{
		*next = '\0';
		next++;
	}

	free(dcp);
	return (start);
}
