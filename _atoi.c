#include "main.h"

/**
 * _atoi - Converts a string to an integer.
 * @s: Pointer to the string to be converted.
 *
 * Return: The integer value of the string, or 0 if no valid integer is found.
 */

int _atoi(char *s)
{

unsigned int n = 0;
int sign = 1;

while (*s)

{
if (*s == '-')
{
	sign *= -1;
}
else if (*s >= '0' && *s <= '9')
{
n = (n * 10) + (*s - '0');
}
else if (n > 0)
{
	break;
}
s++;
}

return (n *sign);
}
