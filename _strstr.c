#include "main.h"

/**
* _strstr - locates a substring
* @haystack: string to search
* @needle: substring to find
* Return: pointer to beginning of substring or NULL if not found
*/
char *_strstr(const char *haystack, const char *needle)
{
	const char *h = haystack;
	const char *n = needle;
	int track;

	if (haystack == NULL || needle == NULL)
		return (NULL);

	while (*h != '\0')
	{
		track = 0;
		while (*n != '\0' && *h == *n)
		{
			h++;
			n++;
			track++;
		}

		if (*n == '\0')
			return ((char *)(h - track));

		h = ++haystack;
		n = needle;
	}

	return (NULL);
}
