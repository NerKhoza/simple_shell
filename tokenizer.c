#include "shell.h"

/**
<<<<<<< HEAD
 * **strtow - splits a string into words
 * @str: parameter 1
 * @d: parameter 2
 * Return: pointer or NULL
=======
 * **strtow - splits a string into words.
 * Repeat delimiters are ignored.
 * @str: the input string.
 * @d: the delimeter string.
 * Return: a pointer to an array of strings,
 * or NULL on failure.
>>>>>>> origin/master
 */

char **strtow(char *str, char *d)
{
<<<<<<< HEAD
	int x, j, k, m, numwords = 0;
=======
	int i, j, k, m, numwords = 0;
>>>>>>> origin/master
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
<<<<<<< HEAD
	for (x = 0; str[x] != '\0'; x++)
		if (!is_delim(str[x], d) && (is_delim(str[x + 1], d) || !str[x + 1]))
=======
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
>>>>>>> origin/master
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
<<<<<<< HEAD
	for (x = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(str[x], d))
			x++;
		k = 0;
		while (!is_delim(str[x + k], d) && str[x + k])
=======
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(str[i], d))
			i++;
		k = 0;
		while (!is_delim(str[i + k], d) && str[i + k])
>>>>>>> origin/master
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
<<<<<<< HEAD
			s[j][m] = str[x++];
=======
			s[j][m] = str[i++];
>>>>>>> origin/master
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
<<<<<<< HEAD
 * **strtow2 - a function that splits a string into words
 * @str: parameter 1
 * @d: parameter 2
 * Return: pointer or NULL
 */
char **strtow2(char *str, char d)
{
	int x, j, k, m, numwords = 0;
=======
 * **strtow2 - splits a string into words.
 * @str: the input string.
 * @d: the delimeter.
 * Return: a pointer to an array of strings,
 * or NULL on failure.
 */
char **strtow2(char *str, char d)
{
	int i, j, k, m, numwords = 0;
>>>>>>> origin/master
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
<<<<<<< HEAD
	for (x = 0; str[x] != '\0'; x++)
		if ((str[x] != d && str[x + 1] == d) ||
		    (str[x] != d && !str[x + 1]) || str[x + 1] == d)
=======
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
		    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
>>>>>>> origin/master
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
<<<<<<< HEAD
	for (x = 0, j = 0; j < numwords; j++)
	{
		while (str[x] == d && str[x] != d)
			x++;
		k = 0;
		while (str[x + k] != d && str[x + k] && str[x + k] != d)
=======
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
>>>>>>> origin/master
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
<<<<<<< HEAD
			s[j][m] = str[x++];
=======
			s[j][m] = str[i++];
>>>>>>> origin/master
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

