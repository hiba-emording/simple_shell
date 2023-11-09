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

	if (create_paths(&path))
	{
		perror("Error creating paths");
		return (1);
	}
	while (1)
	{
		display_prompt();
		input = reader(input);

		if (input == NULL)
		{
			perror("Error reading input");
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
	if (input)
		free(input);
	if (path)
		free_paths(&path);

	return (0);
}
