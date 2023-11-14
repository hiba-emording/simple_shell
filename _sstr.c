#include "main.h"

/**
 * _sstr - switches 2 strings
 * @dest: address of the string to be replaced
 * @src: string to replace the old one
 *
 * Return: 0 on success, 1 on failure
 */
int _sstr(char **dest, char *src)
{
	if (!dest || !src)
		return (1);

	if (*dest)
		free(*dest);
	
	*dest = src;

	return (0);
}
