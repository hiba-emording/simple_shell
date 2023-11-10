#include "main.h"

/**
 * main - Entry point.
 * @argc: argument counter
 * @argv: argument vector
 * Return: Always 0 for success.
 */
int main(int argc, char *argv[])
{
	path_link *path = NULL;
	char **args = NULL;
	int code = 0;

	if (create_paths(&path))
	{
		perror("Error creating paths");
		return (1);
	}
	if (argc > 1)
	{
		args = run_non(argv);
		code = exec_cmd(args, path);
		free_tokenargs(args);
	}
	else
	{
		while (1)
		{
			if (isatty(fileno(stdin)))
				display_prompt();
			args = run_pipe();
			if (!args)
				break;
			code = exec_cmd(args, path);
			free_tokenargs(args);
			if (!isatty(fileno(stdin)))
				break;
		}
	}

	free_paths(&path);
	return (code);
}

/**
  * run_non - aids main to run shell in non-interactive mode
  * @argv: argument vector
  * Return: pointer to tokenized arguments
  */
char **run_non(char **argv)
{
	int i, size = 1;
	char **args, *input = (char *) malloc(size), *tmp;

	if (!input)
	{
		perror("Allocation failed");
		return (NULL);
	}
	*input = '\0';

	for (i = 1; argv[i] != NULL; i++)
	{
		size += _strlen(argv[i]) + 1;
		tmp = (char *) realloc(input, size);
		if (!tmp)
		{
			perror("Allocation failed");
			return (NULL);
		}
		input = tmp;
		_strcat(input, argv[i]);
		_strcat(input, " ");
	}

	args = tokenize(input);
	if (args == NULL)
	{
		perror("Error tokenizing input");
		free(input);
		return (NULL);
	}

	free(input);
	return (args);
}

/**
  * run_pipe - aids main to run shell (interactive and pipe)
  * Return: pointer to tokenized arguments
  */
char **run_pipe(void)
{
	char *input = NULL, **args;

	input = reader(input);
	if (input == NULL)
	{
		perror("Error reading input");
		return (NULL);
	}

	args = tokenize(input);
	free(input);
	if (args == NULL)
	{
		perror("Error tokenizing input");
		free_tokenargs(args);
		return (NULL);
	}

	return (args);
}
