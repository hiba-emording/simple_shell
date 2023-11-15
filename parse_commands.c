#include "main.h"

/**
 * parse_commands - Parse a line into a linked list of commands.
 * @line: The line to parse.
 * Return: A pointer to the first command in the linked list.
 */
cmd_link *parse_commands(char *line)
{
	cmd_link *cmds = NULL;
	char *current = line, *ref = line;
	int strict = 0;

	while ((strict = find_separator(&line)) != 0)
	{
		cmds = create_command(current, strict, cmds);
		if (!cmds)
		{
			free_commands(cmds);
			free(ref);
			return (NULL);
		}
		current = line;
		if (strict == 1)
			break;
	}

	if (strict == 0)
	{
		cmds = create_command(current, strict, cmds);
		if (!cmds)
		{
			free_commands(cmds);
			free(ref);
			return (NULL);
		}
	}

	free(ref);
	return (cmds);
}

/**
 * parse_vector - Parse a vector of commands into a linked list of commands
 * @argv: The vector of arguments
 * Return: A pointer to the first command in the linked list
 */
cmd_link *parse_vector(char **argv)
{
	cmd_link *cmds = NULL;
	int i = 1;
	char *line = malloc(1);
	char *tmp;

	if (!line)
		return (NULL);
	*line = '\0';

	/* convert argv to a string */
	for (; argv[i] != NULL; i++)
	{
		tmp = realloc(line, (_strlen(line) + _strlen(argv[i]) + 1));
		if (!tmp)
		{
			free(line);
			return (NULL);
		}
		line = tmp;
		line = _strcat(line, argv[i]);
		line = _strcat(line, " ");
	}

	/* parse the string */
	cmds = parse_commands(line);
	free(line);
	if (!cmds)
		return (NULL);

	return (cmds);
}

/**
 * create_command - create a command and add to linked list of commands
 * @line: The command string
 * @strict: flag for strict mode
 * @cmds: The linked list to add to
 * Return: pointer to header
 */
cmd_link *create_command(char *line, int strict, cmd_link *cmds)
{
	cmd_link *new = malloc(sizeof(cmd_link)), *tmp;

	if (!new)
		return (NULL);

	new->command = tokenize(line);
	if (!new->command)
	{
		free(new);
		return (NULL);
	}
	new->strict = strict;
	new->next = NULL;

	tmp = add_command(new, cmds);
	if (!tmp)
	{
		free_commands(new);
		return (NULL);
	}

	return (tmp);
}

/**
 * add_command - add a command to a linked list of commands
 * @new: The command to add
 * @cmds: The linked list to add to
 * Return: pointer to header
 */
cmd_link *add_command(cmd_link *new, cmd_link *cmds)
{
	cmd_link *tmp = cmds;

	if (!cmds)
		return (new);

	while (tmp->next)
		tmp = tmp->next;

	tmp->next = new;
	return (cmds);
}

/**
 * free_commands - Free a linked list of commands.
 * @cmd: pointer to the linked list
 */
void free_commands(cmd_link *cmd)
{
	if (!cmd)
		return;

	if (cmd->next)
		free_commands(cmd->next);

	free_tokenargs(cmd->command);
	free(cmd);
	cmd = NULL;
}

