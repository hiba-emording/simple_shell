#include "main.h"

/**
 * reader - Read user input and remove newline.
 * @input: A pointer to the input buffer.
 *
 * Return: A pointer to the modified input buffer or NULL in case of an error.
 */

char *reader(char *input)
{
size_t len = 0, i = 0;
ssize_t cmd = getline(&input, &len, stdin);

	if (cmd == -1)
	{
		free(input);
		return (NULL);
	}

	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == '\n')
		{
			input[i] = '\0';
			break;
		}
	}

	return (input);
}
