#include "shell.h"

/**
 * _strlen - a function that returns the length of a string
 * @s: function parameter 
 * Return: integer
 */
int _strlen(char *s)
{
	int x = 0;

	if (!s)
		return (0);

	while (*s++)
		x++;
	return (x);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @s1: paramter 1
 * @s2: parameter 2
 * Return: integer
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - a function that checks if needle starts with haystack
 * @haystack: parameter 1
 * @needle: parameter 2
 * Return: address or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - a function that concatenates two strings
 * @dest: parameter 1
 * @src: parameter 2
 * Return: pointer
 */
char *_strcat(char *dest, char *src)
{
	char *rt = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (rt);
}

