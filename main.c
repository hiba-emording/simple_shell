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
			break;
		}

		/* Return to displaying prompt by hitting enter*/
		if (_strlen(input) == 0)
			continue;

		args = tokenize(input);
		if (args != NULL)
		{
			exec_cmd(args);
			free(args);
		}
	}

	/* Free all dynamically-allocated memory */
	free(input);

	return (0);
}
