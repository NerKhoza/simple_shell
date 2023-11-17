#include "shell.h"

/**
 * bfree - a function that frees a pointer and NULLs the address
 * @ptr: parameter 1
 * Return: 1 or 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
