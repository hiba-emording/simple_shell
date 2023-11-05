#include "main.h"

/**
  * _strstr - locates a substring
  * @haystack: string to search
  * @needle: substring to find
  * Return: pointer to the beginning of the located bytes
  */
char *_strstr(char *haystack, char *needle)
{
	char *result = haystack, *fneedle = needle;

	while (*haystack)
	{
		while (*needle)
		{
			if (*haystack++ != *needle++)
			{
				break;
			}
		}
		if (!*needle)
		{
			return (result);
		}
		needle = fneedle;
		result++;
		haystack = result;
	}
	return (NULL);
}