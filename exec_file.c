#include "main.h"

/**
 * exec_file - execute commands in a file
 * @file: the file to read commands from
 * @aliases: pointer to aliases linked list
 * @last_exit_status: pointer to last exit status
 * Return: last exit status
 */
int exec_file(char *file, Alias **aliases, int *last_exit_status)
{
	char *line = NULL;
	size_t len = 0;
	cmd_link *cmds = NULL;
	int fp, code = 0;

	fp = open(file, O_RDONLY);
	if (fp == -1)
	{
		perror("Error opening file");
		return (127);
	}

	line = read_file(fp, &len);
	cmds = parse_commands(line);
	if (!cmds)
		return (0);
	code = execute(&cmds, aliases, last_exit_status);

	close(fp);
	return (code);
}

/**
  * read_file - read all input from a file
  * @fp: file pointer
  * @len: number of bytes read
  * Return: pointer to line
  */
char *read_file(int fp, size_t *len)
{
	size_t n = 1, i = 0, j = 0;
	char *line = malloc(n), buf[BUFFER_SIZE] = {0}, *tmp = NULL;

	if (!line)
		return (NULL);
	*line = '\0';
	while ((j = read(fp, &buf, BUFFER_SIZE)) > 0)
	{
		if (i + j >= n)
		{
			n += j;
			tmp = realloc(line, n);
			if (!tmp)
			{
				free(line);
				return (0);
			}
			line = tmp;
		}
		_strcpy(line + i, buf);
		i += j;
	}
	*len = i;
	return (line);
}
