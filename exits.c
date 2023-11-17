#include "shell.h"

/**
 **_strncpy - a function that copies a string
 *@dest: parameter 1
 *@src: parameter 2
 *@n: parameter 3
 *Return: string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int x, j;
	char *s = dest;

	x = 0;
	while (src[x] != '\0' && x < n - 1)
	{
		dest[x] = src[x];
		x++;
	}
	if (x < n)
	{
		j = x;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - a function that concatenates two strings
 *@dest: parameter 1
 *@src: parameter 2
 *@n: parameter 3
 *Return: string
 */
char *_strncat(char *dest, char *src, int n)
{
	int x, j;
	char *s = dest;

	x = 0;
	j = 0;
	while (dest[x] != '\0')
		x++;
	while (src[j] != '\0' && j < n)
	{
		dest[x] = src[j];
		x++;
		j++;
	}
	if (j < n)
		dest[x] = '\0';
	return (s);
}

/**
 **_strchr - a function thar locates a character in a string
 *@s: parameter 1
 *@c: parameter 2
 *Return: a pointer
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

