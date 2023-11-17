#include "shell.h"

/**
<<<<<<< HEAD
 * interactive - a function that returns true 
 * 		if shell is interactive mode
 * @info: function parameter
 * Return: 1 or 0
=======
 * interactive - returns true if the shell is the interactive mode.
 * @info: struct address
 *
 * Return: 1 if shell is in the interactive mode, 0 otherwise
>>>>>>> origin/master
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
<<<<<<< HEAD
 * is_delim - a function that checks if character is a delimeter
 * @c: parameter 1
 * @delim: parameter 2
 * Return: 1, 0 
=======
 * is_delim - checks if the character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
>>>>>>> origin/master
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
<<<<<<< HEAD
 *_isalpha - a function that checks for alphabetic character
 *@c: function parameter
 *Return: 1 or 0
=======
 *_isalpha - checks for any alphabetic character
 *@c: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
>>>>>>> origin/master
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
<<<<<<< HEAD
 *_atoi - a function that converts a string to an integer
 *@s: function parameter
 *Return: 0 or converted number otherwise
=======
 *_atoi - converts a string to an integer
 *@s: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
>>>>>>> origin/master
 */

int _atoi(char *s)
{
<<<<<<< HEAD
	int x, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (x = 0;  s[x] != '\0' && flag != 2; x++)
	{
		if (s[x] == '-')
			sign *= -1;

		if (s[x] >= '0' && s[x] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[x] - '0');
=======
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
>>>>>>> origin/master
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

