#include "main.h"

/**
 * _cd - Change the current working directory.
 * @args: Array of args containing the new directory
 * Return: 0 on success
 */
int _cd(char **args)
{
	char *new_dir, *cwd;

	new_dir = set_dir(args[1]);
	cwd = getcwd(NULL, 0);
	if (cwd == NULL)
	{
		perror("getcwd");
		free(new_dir);
		return (1);
	}
	if (chdir(new_dir) != 0)
	{
		_printerr("cd: can't cd to ", new_dir, "\n", NULL);
		free(cwd);
		free(new_dir);
		return (1);
	}
	else
	{
		_setenv("OLDPWD", cwd);
		free(cwd);
		cwd = getcwd(NULL, 0);
		_setenv("PWD", cwd);
	}
	free(cwd);
	free(new_dir);
	return (0);
}

/**
 * set_dir - Set the directory to change to
 * @dir: The directory to change to
 * Return: The directory to change to, or NULL on failure
 */
char *set_dir(char *dir)
{
	char *new_dir;

	if (dir == NULL || _strcmp(dir, "~") == 0)
	{
		new_dir = _getenv("HOME");
		if (new_dir == NULL)
			new_dir = _getenv("PWD");
	}
	else if (_strcmp(dir, "-") == 0)
	{
		new_dir = _getenv("OLDPWD");
		if (new_dir == NULL)
			new_dir = _getenv("PWD");
		_print(new_dir);
		_printchar('\n');
	}
	else
	{
		new_dir = _strdup(dir);
		if (new_dir == NULL)
		{
			_printerr("Error", ": malloc for new_dir failed", NULL);
			return (NULL);
		}
	}

	return (new_dir);
}
