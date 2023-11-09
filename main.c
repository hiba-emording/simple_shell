#include "main.h"

/**
 * main - Entry point.
 *
 * Return: Always 0 for success.
 */
int main(void)
{
	char *input = NULL, **args;
	path_link *path = NULL;
	int exit_state = 0;

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
			break;
		}
		else
		{
			exit_state = exec_cmd(args, path);
			if (exit_state)
			{
				exit_state = (args[1]) ? _atoi(args[1]) : 0;
				free_tokenargs(args);
				break;
			}
			free_tokenargs(args);
		}
	}
	if (input)
		free(input);
	free_paths(&path);
	return (exit_state);
}
