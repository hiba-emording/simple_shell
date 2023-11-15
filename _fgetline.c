#include "main.h"

/**
  * _fgetline - reads an entire line from file descriptor
  * @lineptr: pointer to the buffer containing the read bytes
  * @fd: file descriptor to read from
  * Return: number of characters read including the delimiting character
  * but not including the terminating null byte
  */
ssize_t _fgetline(char **lineptr, int fd)
{
	int count = 0, size = 100;
	char *tmp, *buf, *c = malloc(sizeof(char));

	if (!lineptr || !c)
		return (-1);
	if (!(*lineptr))
	{
		tmp = realloc((*lineptr), (sizeof(char) * size));
		if (!tmp)
			return (-1);
		*lineptr = tmp;
	}
	buf = *lineptr;
	while (read(fd, c, 1) > 0)
	{
		buf[count++] = *c;
		if (count >= size)
		{
			size *= 2;
			tmp = realloc((*lineptr), (sizeof(char) * size));
			if (!tmp)
				return (-1);
			*lineptr = tmp;
		}
		buf = *lineptr;
		if (*c == '\n')
			break;
	}

	buf[count++] = '\0';
	free(c);

	return (count);
}
