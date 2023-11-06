#include "main.h"

/**
 * print_env - Print environment variables.
 *
 */

void print_env(void)
{
char **env = environ;

	while (*env)
	{
		_printer(*env);
		_printchar('=');
		_printer(_getenv(*env));
		_printchar('\n');
		env++;
	}
}
