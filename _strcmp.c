#include "main.h"

/**
 * _strcmp - Compare two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: 0 if s1 is equal to s2, -1 if s1 is less than s2,
 * and +1 if s1 is greater than s2.
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	if (s1 == NULL || s2 == NULL)
		return (-1);

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}



/**
 * _cstrcmp - Compares two strings.
 * @str1: The first string.
 * @str2: The second string.
 *
 * Return: 0 if the strings are equal, a negative value if str1 < str2,
 * or a positive value if str1 > str2.
 */

int _cstrcmp(const char *str1, const char *str2)
{
int i;

	for (i = 0; str1[i] != '\0'; i++)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
	}

	return (0);
}
