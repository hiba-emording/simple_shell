#include "main.h"

/**
 * switch_vars - switches vars in the tokenized string.
 * @args: Array of tokenized command-line args.
 * @last_exit_status: Pointer to the last exit status variable.
 *
 * Return: 1 if replaced, 0 otherwise.
 */
int switch_vars(char **args, int *last_exit_status)
{
	int i = 0;
	char *value;

	for (i = 0; args[i]; i++)
	{
		if (args[i][0] == '$' && args[i][1] != '\0')
		{
			if (args[i][1] == '?')
				_sstr(&(args[i]), _itoa(*last_exit_status, 10, 0));

			else if (args[i][1] == '$')
				_sstr(&(args[i]), _itoa(getpid(), 10, 0));

			else
			{
				value = _getenv(args[i] + 1);

				if (value)
					_sstr(&(args[i]), value);
				else
					_sstr(&(args[i]), _strdup(""));
			}
		}
	}

	return (0);
}

/**
 * _sstr - switches 2 strings
 * @dest: address of the string to be replaced
 * @src: string to replace the old one
 *
 * Return: 0 on success, 1 on failure
 */
int _sstr(char **dest, char *src)
{
	if (!dest || !src)
		return (1);

	if (*dest)
		free(*dest);
	
	*dest = src;

	return (0);
}

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
