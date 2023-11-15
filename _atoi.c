#include "main.h"

/**
 * _atoi - Converts a string to an integer.
 * @p: Pointer to the string to be converted.
 * @out: Pointer to the integer to be filled
 * Return:0 if no valid integer is found, 1 if valid.
 */

int _atoi(char *p, int *out)
{
	char *s = p;
	unsigned int n = 0;
	int sign = 1;
	int found_digit = 0;

	while (*s)
	{
		if (*s == '-')
		{
			sign *= -1;
		}
		else if (*s >= '0' && *s <= '9')
		{
			n = (n * 10) + (*s - '0');
			found_digit = 1;
		}
		s++;
	}

	if (out)
	{
		*out = sign * n;
	}

	return (found_digit);
}
