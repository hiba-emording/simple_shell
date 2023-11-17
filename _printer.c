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
 * @str: The string to be printed
 */
void _printerr(const char *str, ...)
{
	va_list args;
	static int errnum = 1;
	const char *arg;
	char *tmp, *num;

	if (str == NULL)
		return;

	tmp = "./hsh";
	num = _itoa(errnum++, 10, 0);
	write(STDERR_FILENO, tmp, strlen(tmp));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, num, strlen(num));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, str, strlen(str));

	va_start(args, str);
	while ((arg = va_arg(args, const char *)) != NULL)
		write(STDERR_FILENO, arg, strlen(arg));

	va_end(args);
	free(num);
}
