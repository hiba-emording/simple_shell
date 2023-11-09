#include "main.h"

/**
  * _getline - reads an entire line from stream,
  * storing the address of the buffer containing the text into *lineptr
  * @lineptr: pointer to the buffer containing the read bytes
  * @n: number of bytes read and stored in *lineptr
  * @stream: source to read from
  * Return: number of characters read including the delimiting character,
  * but not including the terminating null byte
  */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int fd;
	size_t count = 0, size = 100;
	char *tmp, *buf, *c = malloc(sizeof(char));

	if (!lineptr || !n || !stream || !c)
		return (-1);

	fd = fileno(stream);
	if (!(*lineptr))
	{
		if (*n > size)
			size = *n;
		tmp = realloc((*lineptr), (sizeof(char) * size));
		if (!tmp)
			return (-1);
		*lineptr = tmp;
		*n = size;
	}

	buf = *lineptr;
	while(read(fd, c, 1) > 0)
	{
		*buf = *c;
		count++;
		if (count >= size)
		{
			size *= 2;
			tmp = realloc((*lineptr), (sizeof(char) * size));
			if (!tmp)
				return (-1);
			*n = size;
			*lineptr = tmp;
		}
		buf = (*lineptr + count);

		if (*c == '\n')
			break;
	}

	*buf = '\0';
	count++;
	*n = count;
	free(c);

	return (count);
}
