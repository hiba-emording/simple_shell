#include "main.h"

/**
 * tokenize - Tokenize a string into separate args dynamically
 * @input: The string to tokenize.
 *
 * Return: A pointer to an array of tokenized args or NULL on failure.
 */

char **tokenize(char *input)
{
	int count = 0, size = 10;
	char *token, *comment;
	char **args = malloc(sizeof(char *) * size), **tmp;

	if (args == NULL)
		return (NULL);

	args[0] = NULL;
	token = _strtok(input, " \t");
	while (token != NULL)
	{
		comment = _strchr(token, '#');
		if (comment)
			*comment = '\0';
		if (!args[count + 1])
		{
			size += 10;
			tmp = realloc(args, size);
			if (!tmp)
			{
				free_tokenargs(args);
				return (NULL);
			}
			args = tmp;
		}
		args[count] = _strdup(token);
		if (args[count] == NULL)
		{
			free_tokenargs(args);
			return (NULL);
		}

		args[++count] = NULL;
		token = _strtok(NULL, " \t\n");
	}
	return (args);
}

/**
 * free_tokenargs - Free memory allocated for tokenized args
 * @args: The array of tokenized args
 */

void free_tokenargs(char **args)
{
	int i = 0;

	while (args[i])
		free(args[i++]);

	if (args)
		free(args);
}
