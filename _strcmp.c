#include "main.h"

/**
 * _strcmp - Compare two strings.
 * @str1: The first string.
 * @str2: The second string.
 *
 * Return: 0 if str1 is equal to str2, -1 if str1 is less than str2,
 * and +1 if str1 is greater than str2.
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
