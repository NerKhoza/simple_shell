#include "shell.h"

/**
 **_memset - a function fills memory with a constant byte
 *@s: parameter 1
 *@b: parameter 2
 *@n: parameter 3
 *Return: pointer
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int x;

	for (x = 0; x < n; x++)
		s[x] = b;
	return (s);
}

/**
 * ffree - a function that frees a string of strings
 * @pp: function paramter
 */
void ffree(char **pp)
{
	char **b = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(b);
}

/**
 * _realloc - a function reallocates a block of memory
 * @ptr: parameter 1
 * @old_size: parameter 2
 * @new_size: parameter 3
 * Return: pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *t;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	t = malloc(new_size);
	if (!t)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		t[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (t);
}

