#include "main.h"

/**
 * _strchr - Locates a character in a string.
 * @s: Pointer to the string where we want to find the character.
 * @c: The character we're looking for.
 *
 * Return: A pointer to the first occurrence of the character 'c' in the
 * string 's', or NULL if the character is not found.
 */

char *_strchr(char *s, char c)
{
	char *p = s;

	while (*p != '\0')
	{
		if (*p == c)
		{
			return (p);
		}
		p++;
	}

	if (*p == c)
	{
		return (p);
	}

	return (NULL);
}
