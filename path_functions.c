#include "main.h"

/**
  * create_paths - create a linked list of all paths in env
  * @path: pointer to node of path
  * Return: 0 on success
  */
int create_paths(path_link *path)
{
	unsigned int i = 0;
	char *env_token = strtok(environ[i], "="), *path_found;

	/* Find PATH in environ */
	while (strcmp(env_token, "PATH") != 0)
		env_token = strtok(environ[++i], "=");
	
	path_found = strtok(NULL, ":\n");
	while (path_found)
	{
		if (add_path(path_found, path))
		{
			free_paths(path);
			return (1);
		}
		path_found = strtok(NULL, ":\n");
	}

	return (0);
}


/**
  * free_paths - frees a linked list of all paths
  * @path: pointer to head of paths linked list
  */
void free_paths(path_link *path)
{
	if (!path)
		return;
	if (path->next)
		free_paths(path->next);
	free(path);
}

/**
  * add_paths - add a pathto a path_link linked list
  * @path: string of path found
  * @head: pointer to head of path
  * Return: 0 on success
  */
int add_path(char *path, path_link *head)
{
	path_link *new = malloc(sizeof(path_link));

	if (!new)
		return (1);

	new->dir = path;
	new->next = head;
	head = new;

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
	path_link *tmp;
	char *dir_check;
	
	/* No need to check if arg is null, previously handled by other functions */
	/* Check if full path is already given */
	if (_strstr(args[0], "/"))
			return (access(args[0], F_OK | X_OK));

	/* Find full path if not given */
	for (tmp = path; (!tmp); tmp = tmp->next)
	{
		dir_check = _dircat(tmp->dir, args[0]);
		if (!access(dir_check, F_OK | X_OK))
		{
			args[0] = dir_check;
			return (0);
		}
	}
	
	return (1);
}