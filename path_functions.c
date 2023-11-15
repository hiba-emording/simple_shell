#include "main.h"

/**
  * find_path - check the PATH for first argument
  * @args: pointer to parsed args
  * Return: 0 on success
  */
int find_path(char **args)
{
	char *dir_check, *dir_token, *tmp;
	int path_index = path_env();

	/* Check if full path is already given */
	if (_strstr(args[0], "/"))
		return (access(args[0], F_OK | X_OK));

	/* Check if command is in PATH */
	if (path_index != -1)
	{
		tmp = _strdup(environ[path_index]);
		if (!tmp)
			return (-1);
		dir_token = _strtok(tmp, "=");
		dir_token = _strtok(NULL, ":\n");
		while (dir_token)
		{
			dir_check = _strdup(dir_token);
			if (!dir_check)
			{
				free(tmp);
				return (-1);
			}
			dir_check = _dircat(dir_check, args[0]);
			if (access(dir_check, F_OK | X_OK) == 0)
			{
				free(args[0]);
				args[0] = dir_check;
				free(tmp);
				return (0);
			}
			free(dir_check);
			dir_token = _strtok(NULL, ":\n");
		}
		free(tmp);
	}

	return (1);
}

/**
  * path_env - check for PATH in env
  * Return: index of PATH in env, -1 if not found
  */
int path_env(void)
{
	unsigned int i = 0;
	char *tmp = NULL, *env_token;

	while (environ[i])
	{
		tmp = _strdup(environ[i++]);
		if (!tmp)
			return (-1);
		env_token = _strtok(tmp, "=");
		if (_strcmp(env_token, "PATH") == 0)
			break;
		free(tmp);
		tmp = NULL;
		env_token = NULL;
	}
	if (_strcmp(env_token, "PATH") != 0)
	{
		free(tmp);
		return (-1);
	}
	free(tmp);
	return (i - 1);
}
