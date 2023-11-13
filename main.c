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
	cmd_link *cmds = NULL;
	char *line = NULL;
	int code = 0, last_exit_status = 0;

	if (create_paths(&path))
		return (1);

	if (argc > 1)
	{
		cmds = parse_vector(argv);
		if (!cmds)
		{
			perror("Error parsing commands");
			free_paths(&path);
			return (1);
		}
		code = execute(&cmds, path, &last_exit_status);
		free_commands(cmds);
	}
	else
	{
		while (1)
		{
			if (isatty(fileno(stdin)))
				_printer("$ ");
			line = reader(line);
			if (!line)
			{
				perror("Error reading input");
				free_paths(&path);
				return (1);
			}
			cmds = parse_commands(line);
			free(line);
			if (!cmds)
			{
				perror("Error parsing commands");
				free_paths(&path);
				return (1);
			}
			code = execute(&cmds, path, &last_exit_status);
			if (cmds)
				free_commands(cmds);
			if (!isatty(fileno(stdin)))
				break;
		}
	}

	free_paths(&path);
	return (code);
}
