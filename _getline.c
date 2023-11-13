#include "main.h"
#define BUFFER_SIZE 1024

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
size_t count = 0, size = 100, i = 0, bytesRead;
char *tmp, *buf;
char buffer[BUFFER_SIZE];

	if (!lineptr || !n || !stream)
		return (-1);

	if (!(*lineptr))
	{
		if (*n > size)
			size = *n;
	
		tmp = realloc(*lineptr, sizeof(char) * size);

		if (!tmp)
		{
			return (-1);
		}
		*lineptr = tmp;
		*n = size;
	}

	fd = fileno(stream);
	buf = *lineptr;

	while ((bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		for (i = 0; i < bytesRead; i++)
		{
			buf[count++] = buffer[i];

			if (count >= *n)
			{
				size *= 2;
				tmp = realloc(*lineptr, sizeof(char) * size);

				if (!tmp)
				{
					return (-1);
				}
				*lineptr = tmp;
				buf = *lineptr;
				*n = size;
			}
			if (buffer[i] == '\n')
				break;
		}

		if (buffer[i] == '\n')
			break;
	}

	buf[count++] = '\0';
	*n = count;

return (count);
}
