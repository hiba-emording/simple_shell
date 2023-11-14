#include "main.h"

/**
 * reader - Read user input and remove newline
 * @input: A pointer to the input buffer
 *
 * Return: number of bytes read, -1 on failure
 */

int reader(char **input)
{
size_t len = 0;
ssize_t cmd = getline(input, &len, stdin);

	if (cmd == -1)
	{
		if (*input)
			free(*input);
		return (-1);
	}
	if (cmd > 0 && (*input)[cmd - 1] == '\n')
		(*input)[cmd - 1] = '\0';

	cmd = _strlen(*input);
	if (cmd == 0)
	{
		free(*input);
		return (0);
	}
	return (cmd);
}
