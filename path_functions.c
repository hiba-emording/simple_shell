#include "main.h"

/**
  * create_paths - create a linked list of all paths in env
  * @path: pointer to node of path
  * Return: 0 on success
  */
int create_paths(path_link **path)
{
    unsigned int i = 0;
    char *tmp = _strdup(environ[i]);
    char *path_found;
    char *env_token;

    if (!tmp)
    {
        perror("Error: Unable to duplicate environment variable");
        return (1);
    }

    env_token = _strtok(tmp, "=");

    // Find PATH in environ
    while (_strcmp(env_token, "PATH") != 0)
    {
        free(tmp);
        tmp = _strdup(environ[++i]);
        if (!tmp)
        {
            perror("Error: Unable to duplicate environment variable");
            return (1);
        }
        env_token = _strtok(tmp, "=");
    }

    path_found = _strtok(NULL, ":\n");
    while (path_found)
    {
        char *path_copy = _strdup(path_found);
        if (!path_copy)
        {
            perror("Error: Unable to duplicate path");
            free_paths(path);
            free(tmp);
            return (1);
        }

        if (add_path(path_copy, path))
        {
            free_paths(path);
            free(tmp);
            free(path_copy);
            return (1);
        }

        path_found = _strtok(NULL, ":\n");
    }

    free(tmp);
    return (0);
}


/**
  * free_paths - frees a linked list of all paths
  * @path: pointer to head of paths linked list
  */
void free_paths(path_link **path)
{
    if (!(*path))
    {
        return;
    }

    if ((*path)->next)
    {
        free_paths(&((*path)->next));
    }

    free((*path)->dir);
    free((*path));

    *path = NULL;
}

/**
  * add_path - add a pathto a path_link linked list
  * @path: string of path found
  * @head: pointer to head of path
  * Return: 0 on success
  */
int add_path(char *path, path_link **head)
{
	path_link *new = malloc(sizeof(path_link));

	if (!new)
	{
		perror("Error: Unable to allocate memory");
		return (1);
	}

	new->dir = path;
	new->next = (*head);
	(*head) = new;

	return (0);
}

/**
  * find_path - check the PATH for first argument
  * @args: pointer to parsed args
  * @path: pointer to head of paths linked list
  * Return: 0 on success
  */
int find_path(char **args, path_link *path)
{
	path_link *tmp = path;
	char *dir_check;

	/* Check if full path is already given */
	if (!_strstr(args[0], "/"))
		return (access(args[0], F_OK | X_OK));

	/* Find full path if not given */
	for (; tmp; tmp = tmp->next)
	{
		dir_check = _dircat(tmp->dir, args[0]);

		if (!access(dir_check, F_OK | X_OK))
		{
			args[0] = dir_check;
			return (0);
		}
	}

	perror("Error: Unable to concatenate directory");
	return (1);
}
