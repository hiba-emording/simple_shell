#include "main.h"

/**
  * exec_file - execute commands in a file
  * @args: commands passed
  * @path: linked list of paths
  * @last_exit_status: last exit status
  * Return: 0 on success
  */
int exec_file(char **args, path_link **path, int *last_exit_status)
{
	char *line = NULL;
	cmd_link *command;
	ssize_t read;
	int fd;

	fd = open(args[0], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (-1);
	}

	while ((read = _fgetline(&line, fd)) != -1)
	{
		command = parse_commands(line);
		if (command == NULL)
		{
			*last_exit_status = -1;
			break;
		}
		*last_exit_status = execute(&command, path, last_exit_status);
		free(command);
		if (*last_exit_status != 0)
			break;
	}

	free(line);
	close(fd);
	return (*last_exit_status);
}
