#include "main.h"

/**
 * _strcat - Concatenate two strings.
 *
 * @dest: Destination string, where the result is stored.
 * @src: Source string to append to dest.
 *
 * Return: A pointer to the resulting string dest.
 */

char *_strcat(char *dest, char *src)
{
	char *dest_ptr = dest;

	if (dest == NULL || src == NULL)
		return (NULL);

	while (*dest_ptr != '\0')
	{
		dest_ptr++;
	}

	while (*src != '\0')
	{
		*dest_ptr = *src;
		dest_ptr++;
		src++;
	}

	*dest_ptr = '\0';

	return (dest);
}
