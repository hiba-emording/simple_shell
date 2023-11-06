#include "main.h"

/**
 * _strdup - Duplicates a string.
 * @src: A pointer to the source string.
 * Return: A pointer to the duplicated string or NULL in case of an error.
 */

char *_strdup(const char *src)
{
	size_t len = _strlen(src) + 1;
	char *dest = (char *)malloc(len);

	if (src == NULL)
	{
		return (NULL);
	}

	if (dest != NULL)
	{
		_strcpy(dest, src);
	}

	return (dest);
}
