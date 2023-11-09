#include "main.h"

/**
 * main - Entry point.
 *
 * Return: Always 0 for success.
 */

int main(void)
{
	char *input, **args;
	path_link *path = NULL;

	/* Create linked list for paths in environ */
	if (create_paths(&path))
	{
		perror("Error creating paths");
		return (1);
	}

	while (1)
	{
		display_prompt();
		input = reader(input);
		/* Handle EOF */
		if (input == NULL)
		{
			 perror("Error reading input");
			_printchar('\n');
			break;
		}

		args = tokenize(input);
		if (args == NULL)
		{
			perror("Error tokenizing input");
			free(input);
			break;
		}
		else
		{
			exec_cmd(args, path);
			free(args);
		}
	}

	/* Free all dynamically-allocated memory */
	if (input)
		free(input);
	if (path)
		free_paths(&path);

	return (0);
}
