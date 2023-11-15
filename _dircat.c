#include "main.h"

/**
  * _dircat - concatenate a directory pathname to a given filename
  * @dir: directory path
  * @filename: filename given
  * Return: a new pointer to the resulting string
  */
char *_dircat(char *dir, char *filename)
{
	size_t dir_len = _strlen(dir);
	size_t filename_len = _strlen(filename);
	int slash = 0;
	char *result;

    /* Check and add a middle slash if necessary */
	if (dir_len > 0 && dir[dir_len - 1] != '/')
		slash = 1;

	result = malloc(dir_len + filename_len + 1 + slash);

	if (result == NULL)
		return (NULL);

	_strcpy(result, dir);

	if (slash == 1)
		_strcat(result, "/");

	_strcat(result, filename);

	free(dir);
	return (result);
}
