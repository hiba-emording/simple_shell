#include "main.h"

/**
 * tokenize - Tokenize a string into separate args dynamically
 * @input: The string to tokenize.
 *
 * Return: A pointer to an array of tokenized args or NULL on failure.
 */

char **tokenize(char *input)
{
	/* Allocate arguments in array args*/
	int count = 0, size = 10;
	char *token;
	char **args = malloc(sizeof(char *) * size), **tmp;

	if (args == NULL)
	{
		return (NULL);
	}

	/* Make first arg null in case token is null  */
	args[0] = NULL;

	/* Tokenize handling 3 common seperators */
	token = strtok(input, " \t\n");

	while (token != NULL)
	{
		/* Allocate memory as needed to accomodate the null terminator */
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

		/* Presumed end of the command */
		args[++count] = NULL;
		token = strtok(NULL, " \t\n");
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

	free(args);
}
