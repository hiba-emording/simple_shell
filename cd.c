#include "main.h"

/**
 * _cd - Change the current working directory.
 * @args: Array of args containing the new directory.
 * Return: 0 on success
 */

int _cd(char **args)
{
	char *new_dir;
	char *cwd;

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
	{
		new_dir = args[1];
	}

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
		_setenv("OLDPWD", cwd);
		_setenv("PWD", getcwd(NULL, 0));
	}

	free(cwd);
	return (0);
}
