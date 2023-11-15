#include "main.h"

/**
 * find_separator - Find the next command separator in a string.
 * @line: The string to search.
 * Return: flag of the corresponding separator, or 0 if none found.
 */
int find_separator(char **line)
{
	char *tmp = *line;

	if (!(*tmp))
		return (0);

	while (*tmp)
	{
		if (*tmp == ';' || *tmp == '\n' || *tmp == '\0')
		{
			*tmp = '\0';
			*line = tmp + 1;
			return (2);
		}
		if (*tmp == '|' && *(tmp + 1) == '|')
		{
			*tmp = '\0';
			*(tmp + 1) = '\0';
			*line = tmp + 2;
			return (3);
		}
		if (*tmp == '&' && *(tmp + 1) == '&')
		{
			*tmp = '\0';
			*(tmp + 1) = '\0';
			*line = tmp + 2;
			return (4);
		}
		tmp++;
	}

	return (0);
}
