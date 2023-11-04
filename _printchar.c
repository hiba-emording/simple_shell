#include "main.h"

/**
 * _printchar - Prints a character.
 * @c: The character to be printed.
 *
 * Return: Always 1 (success).
 */

int _printchar(char c)

{
return (write(1, &c, 1));
}
