#include "main.h"

#define MAX_ARGS 1024 /* This can be edited */

void free_tokenargs(char **args, int count);

/**
 * tokenize - Tokenize a string into separate args.
 * @input: The string to tokenize.
 *
 * Return: A pointer to an array of tokenized args or NULL on failure.
 */

char **tokenize(char *input)
{
	/* allocate arguments in aray - +1 to count terminator */
char **args = malloc(MAX_ARGS + 1);
int count = 0;
char *token;

/* just checking if allocation succed */
	if (args == NULL)
	{
		return (NULL);
	}

	/* for now handling 3 common seperators */
	token = strtok(input, " \t\n");

	while (token != NULL && count < MAX_ARGS)
	{
		args[count] = _strdup(token);

		/* check if memory aloocation succed */
		if (args[count] == NULL)
		{
			free_tokenargs(args, count);
			return (NULL);
		}
		count++;

		/* find next token */
		token = strtok(NULL, " \t\n");
	}
	/* end of the file */
	args[count] = NULL;
	return (args);
}

/**
 * free_tokenargs - Free memory allocated for tokenized args.
 * @args: The array of tokenized args.
 * @count: Number of tokenized args.
 */

void free_tokenargs(char **args, int count)
{
int i;

	for (i = 0; i < count; i++)
	{
		free(args[i]);
	}

	free(args);
}
