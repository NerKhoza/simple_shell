#include "shell.h"

/**
<<<<<<< HEAD
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
=======
 **_memset - fills memory with a constant byte.
 *@s: the pointer to the memory area.
 *@b: the byte to fill *s with.
 *@n: the amount of bytes to be filled.
 *Return: (s) a pointer to the memory area s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
>>>>>>> origin/master
	return (s);
}

/**
<<<<<<< HEAD
 * ffree - a function that frees a string of strings
 * @pp: function paramter
 */
void ffree(char **pp)
{
	char **b = pp;
=======
 * ffree - frees a string of a strings.
 * @pp: string of the strings.
 */
void ffree(char **pp)
{
	char **a = pp;
>>>>>>> origin/master

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
<<<<<<< HEAD
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
=======
	free(a);
}

/**
 * _realloc - reallocates a block of memory.
 * @ptr: pointer to previous malloc'ated block.
 * @old_size: byte size of previous block.
 * @new_size: byte size of new block.
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;
>>>>>>> origin/master

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

<<<<<<< HEAD
	t = malloc(new_size);
	if (!t)
=======
	p = malloc(new_size);
	if (!p)
>>>>>>> origin/master
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
<<<<<<< HEAD
		t[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (t);
}

=======
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
>>>>>>> origin/master
