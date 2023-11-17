#include "shell.h"

/**
<<<<<<< HEAD
 * _strlen - a function that returns the length of a string
 * @s: function parameter 
 * Return: integer
 */
int _strlen(char *s)
{
	int x = 0;
=======
 * _strlen - returns the length of a string.
 * @s: the string whose length to check.
 *
 * Return: integer length of string.
 */
int _strlen(char *s)
{
	int i = 0;
>>>>>>> origin/master

	if (!s)
		return (0);

	while (*s++)
<<<<<<< HEAD
		x++;
	return (x);
=======
		i++;
	return (i);
>>>>>>> origin/master
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
<<<<<<< HEAD
 * @s1: paramter 1
 * @s2: parameter 2
 * Return: integer
=======
 * @s1: the first strang.
 * @s2: the second strang.
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
>>>>>>> origin/master
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
<<<<<<< HEAD
 * starts_with - a function that checks if needle starts with haystack
 * @haystack: parameter 1
 * @needle: parameter 2
 * Return: address or NULL
=======
 * starts_with - checks if needle starts with haystack.
 * @haystack: string to search.
 * @needle: the substring to find.
 *
 * Return: address of next char of haystack or NULL.
>>>>>>> origin/master
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
<<<<<<< HEAD
 * _strcat - a function that concatenates two strings
 * @dest: parameter 1
 * @src: parameter 2
 * Return: pointer
 */
char *_strcat(char *dest, char *src)
{
	char *rt = dest;
=======
 * _strcat - concatenates two strings.
 * @dest: the destination buffer.
 * @src: the source buffer.
 *
 * Return: pointer to destination buffer.
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;
>>>>>>> origin/master

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
<<<<<<< HEAD
	return (rt);
=======
	return (ret);
>>>>>>> origin/master
}

