#include "main.h"

/**
  * _strstr - locates a substring
  * @haystack: string to search
  * @needle: substring to find
  * Return: 0 if found, 1 otherwise
  */
int _strstr(const char *haystack, const char *needle)
{
    const char *h = haystack;
    const char *n = needle;

    while (*h != '\0')
    {
        while (*n != '\0' && *h == *n)
        {
            h++;
            n++;
        }

        if (*n == '\0')
            return 0;

        h = ++haystack;
        n = needle;
    }

    return 1;
}
