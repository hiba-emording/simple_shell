#include "main.h"

/**
 * main - Entry point.
 * @argc: argument counter
 * @argv: argument vector
 * Return: Always 0 for success.
 */
int main(int argc, char *argv[])
{
	cmd_link *cmds = NULL;
	Alias *aliases = NULL;
	char *line = NULL;
	int code = 0, last_exit_status = 0, len = 0;

	if (argc > 1)
	{
		cmds = parse_vector(argv);
		if (!cmds)
		{
			perror("Error parsing commands");
			clean_quit(1, &aliases);
		}
		code = execute(&cmds, &aliases, &last_exit_status);
	}
	else
	{
		while (1)
		{
			signal(SIGINT, sigint_handler);
			len = display_prompt(&line);
			if (len == -1)
			{
				if (!isatty(fileno(stdin)))
					return (code);
				_printchar('\n');
				clean_quit(0, &aliases);
			}
			else if (len == 0)
				continue;
			cmds = parse_commands(line);
			code = execute(&cmds, &aliases, &last_exit_status);
		}
	}
	clean_quit(code, &aliases);
	return (code);
}

/**
 * sigint_handler - handles the SIGINT signal
 * @sig: the signal number
 */
void sigint_handler(__attribute__((unused))int sig)
{
	_printchar('\n');
	if (isatty(fileno(stdin)))
		_print("$ ");
	fflush(stdout);
}

/**
 * clean_quit - frees memory and exits
 * @status: exit status
 * @aliases: pointer to aliases linked list
 */
void clean_quit(int status, Alias **aliases)
{
	free_aliases(aliases);
	exit(status);
}
