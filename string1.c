#include "shell.h"

/**
<<<<<<< HEAD
 * _strcpy - a function that copies a string
 * @dest: parameter 1
 * @src: parameter 2
 * Return: pointer
 */
char *_strcpy(char *dest, char *src)
{
	int x = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[x])
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = 0;
=======
 * _strcpy - copies a string.
 * @dest: the destination.
 * @src: the source.
 *
 * Return: pointer to destination.
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
>>>>>>> origin/master
	return (dest);
}

/**
<<<<<<< HEAD
 * _strdup - a function that duplicates a string
 * @str: function parameter
 * Return: pointer
=======
 * _strdup - duplicates a string.
 * @str: the string to duplicate.
 *
 * Return: pointer to the duplicated string.
>>>>>>> origin/master
 */
char *_strdup(const char *str)
{
	int length = 0;
<<<<<<< HEAD
	char *rt;
=======
	char *ret;
>>>>>>> origin/master

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
<<<<<<< HEAD
	rt = malloc(sizeof(char) * (length + 1));
	if (!rt)
		return (NULL);
	for (length++; length--;)
		rt[length] = *--str;
	return (rt);
}

/**
 *_puts - a function prints an input string
 *@str: function parameter
 * Return: Nothing
 */
void _puts(char *str)
{
	int x = 0;

	if (!str)
		return;
	while (str[x] != '\0')
	{
		_putchar(str[x]);
		x++;
=======
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 *_puts - prints an input string.
 *@str: the string to be printed.
 *
 * Return: Nothing.
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
>>>>>>> origin/master
	}
}

/**
<<<<<<< HEAD
 * _putchar - a function writes the character c to stdout
 * @c: parameter 1
 * Return: 1
 */
int _putchar(char c)
{
	static int x;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(1, buf, x);
		x = 0;
	}
	if (c != BUF_FLUSH)
		buf[x++] = c;
=======
 * _putchar - writes the character c to stdout.
 * @c: The character to print.
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
>>>>>>> origin/master
	return (1);
}

