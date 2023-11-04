#include "main.h"

/**
 * _strncmp - Compare 'n' characters of two strings or until \0.
 * @s1: First string to compare.
 * @s2: Second string to compare.
 * @n: Maximum number of characters to compare.
 *
 * Return:
 *   0 if first 'n' characters are equal.
 *   Negative if 's1' is less than 's2'.
 *   Positive if 's1' is greater than 's2'.
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}

		if (s1[i] == '\0')
		{
			return (0);
		}
	}

	return (0);
}
