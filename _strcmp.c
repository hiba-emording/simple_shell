#include "main.h"

/**
 * _strcmp - Compare two strings.
 * @str1: The first string.
 * @str2: The second string.
 *
 * Return: 0 if str1 is equal to str2, -1 if str1 is less than str2,
 * and +1 if str1 is greater than str2.
 */

int _strcmp(char *str1, char *str2)
{

	while (*str1 && *str2)
	{
		if (*str1 != *str2)
		{
			if (*str1 < *str2)
			{
				return (-1);
			}
			else
			{
				return (1);
			}
		}
		str1++;
		str2++;
	}

	if (*str1 == *str2)
	{
		return (0);
	}
	else
	{
		if (*str1 < *str2)
		{
			return (-1);
		}
		else
		{
			return (1);
		}
	}
}
