#include "main.h"

/**
 * _cd - Change the current working directory.
 * @args: Array of args containing the new directory.
 * @path: Pointer to the head of the path linked list.
 * Return: 0 on success
 */

int _cd(char **args, path_link **path)
{
	char *new_dir, *cwd;

	if (args[1] == NULL || _strcmp(args[1], "~") == 0)
	{
		new_dir = _getenv("HOME");
		if (new_dir == NULL)
		{
			perror("Error: HOME environment variable not set");
			return (1);
		}
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		new_dir = _getenv("OLDPWD");
		if (new_dir == NULL)
			return (1);
	}
	else
		new_dir = args[1];

	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		perror("getcwd");
		return (1);
	}
	if (chdir(new_dir) != 0)
	{
		perror("chdir");
		free(cwd);
		return (1);
	}
	else
	{
		_setenv("OLDPWD", cwd, path);
		_setenv("PWD", getcwd(NULL, 0), path);
	}

	free(cwd);
	return (0);
}
