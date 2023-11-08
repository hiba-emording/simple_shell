#include "main.h"

/**
 * cd - Change the current working directory.
 * @args: Array of args containing the new directory.
 */

void _cd(char **args)
{
char *new_dir;
char *cwd;

	if (args[1] == NULL || _strcmp(args[1], "~") == 0)
	{
		new_dir = _getenv("HOME");
	}

	else if (_strcmp(args[1], "-") == 0)
	{
		new_dir = _getenv("OLDPWD");
	}

	else
	{
		new_dir = args[1];
	}

	cwd = getcwd(NULL, 0);

	if (cwd == NULL)
	{
		perror("getcwd");
		return;
	}

	if (chdir(new_dir) != 0)
	{
		perror("chdir");
	}

	else
	{
		_setenv("OLDPWD", cwd);
		_setenv("PWD", getcwd(NULL, 0));
	}

	free(cwd);
}
