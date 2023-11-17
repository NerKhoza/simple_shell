#include "shell.h"

/**
<<<<<<< HEAD
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
=======
 * *_strncpy - copies a string.
 * @dest: the destination string to be copied to.
 * @src: the source string.
 * @n: the amount of characters to be copied.
 * Return: the concatenated string.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
>>>>>>> origin/master
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
<<<<<<< HEAD
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
=======
 * *_strncat - concatenates two strings.
 * @dest: the first string.
 * @src: the second string.
 * @n: the amount of bytes to be maximally used.
 * Return: the concatenated string.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
>>>>>>> origin/master
	return (s);
}

/**
<<<<<<< HEAD
 **_strchr - a function thar locates a character in a string
 *@s: parameter 1
 *@c: parameter 2
 *Return: a pointer
=======
 * *_strchr - locates a character in a string.
 * @s: the string to be parsed.
 * @c: the character to look for.
 * Return: (s) a pointer to the memory area s.
>>>>>>> origin/master
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

