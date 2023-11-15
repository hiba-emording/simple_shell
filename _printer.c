#include "main.h"

/**
 * _print - Print a string to standard output.
 * @str: The string to be printed.
 */

void _print(const char *str)
{
int len = _strlen(str);

	if (len > 0)
	{
		write(STDOUT_FILENO, str, len);
	}
}

/**
 * _printerr - Print a string to standard error
 * @str: The string to be printed.
 * @suffix: The string to be appended to the end of str.
 */
void _printerr(const char *str, char *suffix)
{
	int len = _strlen(str);
	static int err = 1;
	char *prefix;
	char *err_str, *mix = ": ";

	if (len > 0)
	{
		prefix = _getenv("_");
		err_str = _itoa(err++, 10, 0);
		write(STDERR_FILENO, prefix, _strlen(prefix));
		write(STDERR_FILENO, mix, _strlen(mix));
		write(STDERR_FILENO, err_str, _strlen(err_str));
		write(STDERR_FILENO, mix, _strlen(mix));
		write(STDERR_FILENO, str, len);
		if (suffix)
			write(STDERR_FILENO, suffix, _strlen(suffix));
		free(prefix);
		free(err_str);
	}
}
