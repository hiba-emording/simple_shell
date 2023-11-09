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
static char *next = NULL;
char *start;
char *dcp;

	dcp = malloc(_strlen(d) + 1);

	if (dcp == NULL)
	{
		perror("Failed to allocate memory in _strtok");
		return (NULL);
	}

	_strcpy(dcp, d);

	if (s != NULL)
	{	
		next = s;
	}

	while (*next && _strchr(dcp, *next))
	{
		next++;
	}

	if (*next == '\0')
	{
		free(dcp);
		return (NULL);
	}

	start = next;

	while (*next && _strchr(dcp, *next) == NULL)
	{
		next++;
	}

	if (*next)
	{
		*next = '\0';
		next++;
	}

	free(dcp);

	return (start);
}
