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
	int code = 0, last_exit_status = 0, len = 0;

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
	}
	else
	{
		while (1)
		{
			if (isatty(fileno(stdin)))
				_printer("$ ");
			if ((len = reader(&line)) == -1)
			{
				if (!isatty(fileno(stdin)))
					return (0);
				perror("Error reading input");
				free_paths(&path);
				return (1);
			}
			else if (len == 0)
				continue;
			cmds = parse_commands(line);
			free(line);
			if (!cmds || !cmds->command || !cmds->command[0])
			{
				if (cmds)
					free_commands(cmds);
				continue;
			}
			code = execute(&cmds, path, &last_exit_status);
		}
	}

	free_paths(&path);
	return (code);
}
