#include "main.h"

/**
 * _strcpy - Copy a string from source to destination.
 * @dest: The destination string.
 * @src: The source string to copy from.
 *
 * Return: A pointer to the destination string.
 */

char *_strcpy(char *dest, const char *src)
{
int i = 0;

	if (dest == src || src == NULL)
	{
		return (dest);
	}

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';

	return (dest);
}
