#include "main.h"

/**
 * display_prompt - a function to display $ and read user input
 * @line: a pointer to a string to store user input
 * Return: the length of the string read
 */
int display_prompt(char **line)
{
	if (isatty(fileno(stdin)))
		_print("$ ");

	return (reader(line));
}
