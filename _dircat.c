#include "main.h"

/**
  * _dircat - concatenate a directory pathname to a given filename
  * @dir: directory path
  * @filename: filename given
  * Return: a new pointer to the resulting string
  */
char *_dircat(char *dir, char *filename)
{
	int t, i, slash = 1;
	char *new;

	for (t = 0; dir[t] != '\0'; t++)
	;
	for (i = 0; filename[i] != '\0'; i++)
	;

	/* Check and add a middle slash if necessary */
	if (dir[t - 1] != '/')
		slash = 0;

	new = malloc(sizeof(char) * (i + t - slash));

	for (t = 0; dir[t] != '\0'; t++)
		new[t] = dir[t];

	if (slash == 0)
		new[t++] = '/';

	for (i = 0; filename[i] != '\0'; i++, t++)
		new[t] = filename[i];

	new[t] = '\0';

	return (new);
}
