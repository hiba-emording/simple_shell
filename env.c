#include "main.h"

/**
 * handle_env - Print environment variables.
 *
 */

void handle_env(void)
{
char **env = environ;

	while (*env)
	{
		_printer(*env);
		_printchar('\n');
		env++;
	}
}
