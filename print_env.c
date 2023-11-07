#include "main.h"

/**
 * print_env - Print environment variables.
 *
 */

void print_env(void)
{
unsigned int i = 0;

	while (environ[i])
	{
		_printer(environ[i]);
		_printchar('\n');
		i++;
	}
}
