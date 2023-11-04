#include "main.h"

/**
 * main - Entry point.
 *
 * Return: Always 0 for success.
 */

int main(void)
{
char *input, **args;

	while (1)
	{
		display_prompt();
		input = reader(input);

		/* Handle EOF */
		if (input == NULL)
		{
			_printchar('\n');
			exit(0);
		}

		/* Return to displaying prompt by hitting enter*/
		if (_strlen(input) == 0)
		{
			free(input);
			continue;
		}

		args = tokenize(input);
		if (args != NULL)
		{
		exec_cmd(args);
		free(args);
		}
	}
	free(input);

	return (0);
}
