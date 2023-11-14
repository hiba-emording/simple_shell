#include "main.h"

/**
 * _itoa - Converts an integer to a string
 * @n: The integer to be converted
 * @base: The base for conversion
 * @uppercase: Flag to handle upper and lower case
 * Return: Pointer to the resulting string
 */
char *_itoa(int n, int base, int uppercase)
{
	int digits[64], i = 0, j, k, remains;
	char digit, *str;

	str = malloc(64);
	if (!str)
		return (NULL);

	if (n == 0)
	{
		str[i++] = '0';
	}
	else
	{
		if (n < 0)
		{
			str[i++] = '-';
			n = -n;
		}
		while (n > 0)
		{
			remains = n % base;

			if (remains < 10)
			{
				digit = remains + '0';
			}
			else
			{
				digit = (uppercase) ? (remains - 10 + 'A') : (remains - 10 + 'a');
			}
			digits[i++] = digit;
			n /= base;
		}
	}

	for (j = i - 1, k = 0; j >= 0; j--, k++)
	{
		str[k] = digits[j];
	}
	str[i] = '\0';

	return (str);
}