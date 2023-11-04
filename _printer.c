#include "main.h"

/**
 * _printer - Print a string to standard output.
 * @str: The string to be printed.
 */

void _printer(const char *str)
{
int len = _strlen(str);

	if (len > 0)
	{
		write(STDOUT_FILENO, str, len);
	}
}
