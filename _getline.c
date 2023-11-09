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
ssize_t _getline(char **lineptr, size_t *n, FILE * stream)
{
	int fd;
	size_t capacity, i;
	char *buffer, *temp, c;
	ssize_t bytesRead;

    if (!lineptr || !n)
		return (-1);

    fd = fileno(stream);

    capacity = *n;
    if (*lineptr == NULL || capacity == 0)
    {
        capacity = 128;
        *lineptr = (char *)malloc(capacity);
        if (*lineptr == NULL)
            return (-1);
        *n = capacity;
    }

    buffer = *lineptr;
    i = 0;

    while ((bytesRead = read(fd, &c, 1)) > 0)
    {
        if (i >= capacity - 1)
        {
            capacity *= 2;
            temp = (char *)realloc(buffer, capacity);
            if (temp == NULL)
                return (-1);
            buffer = temp;
            *lineptr = buffer;
            *n = capacity;
        }
        buffer[i++] = c;

        if (c == '\n')
            break;
    }
    if (i == 0 && bytesRead == 0)
        return (-1);

    buffer[i] = '\0';
    return (i);
}
