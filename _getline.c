#include "main.h"

#define BUF_SIZE 1024

/**
 * read_buf - Reads input characters into a buffer.
 * @buf: Buffer to store read characters.
 * @pos: Current position in the buffer.
 *
 * Return: Num of chars read or -1 on failure.
 */

ssize_t read_buf(char *buf, size_t *pos)
{
ssize_t count = 0;

if (*pos > 0)
	return (0);

count = read(STDIN_FILENO, buf, BUF_SIZE);
if (count >= 0)
	*pos = count;

return (count);
}

/**
 * _getline - Reads input line by line from stdin.
 * @line: Pointer to the input line.
 * @len: Length of the input line.
 *
 * Return: Length of the line read or -1 on failure.
 */

int _getline(char **line, size_t *len)
{
static char buffer[BUF_SIZE];
static size_t pos, bytes_read;
size_t line_len;
ssize_t read_count = 0, total_len = 0;
char *curr_line = NULL, *new_line = NULL, *ptr;

curr_line = *line;
if (curr_line && len)
	line_len = *len;
if (pos == bytes_read)
	pos = bytes_read = 0;

read_count = read_buf(buffer, &bytes_read);
if (read_count == -1 || (read_count == 0 && bytes_read == 0))
	return (-1);

ptr = _strchr(buffer + pos, '\n');
line_len = ptr ? 1 + (unsigned int)(ptr - buffer) : bytes_read;
new_line = realloc(curr_line, line_len ? line_len + line_len : line_len + 1);
if (!new_line) /* MALLOC FAILURE! */
	return (curr_line ? free(curr_line), -1 : -1);

if (line_len)
	_strncat(new_line, buffer + pos, line_len - pos);
else
	_strncpy(new_line, buffer + pos, line_len - pos + 1);

total_len += line_len - pos;
pos = line_len;
curr_line = new_line;

if (total_len > 0 && curr_line[total_len - 1] == '\n')
{
	curr_line[total_len - 1] = '\0';
	total_len--;
}
if (len)
{
	*len = total_len;
}
*line = curr_line;
return (total_len);
}
