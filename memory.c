#include "shell.h"

/**
<<<<<<< HEAD
 * bfree - a function that frees a pointer and NULLs the address
 * @ptr: parameter 1
 * Return: 1 or 0.
=======
 * bfree - frees a pointer and the NULL of the address.
 * @ptr: address of the pointer to free.
 *
 * Return: 1 if freed, otherwise 0.
>>>>>>> origin/master
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
<<<<<<< HEAD
=======

>>>>>>> origin/master
