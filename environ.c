#include "shell.h"

/**
<<<<<<< HEAD
 * _myenv - a function that prints the current environment
 * @info: function parameter
 * Return: 0
=======
 * _myenv - prints the current environment
 * @info: Structure containing the potential arguments.
 * Used to maintain the constant function prototype.
 * Return: Always 0
>>>>>>> origin/master
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
<<<<<<< HEAD
 * _getenv - a function that gets the value of an environ variable
 * @info: parameter 1
 * @name: parameter 2
 * Return: value
=======
 * _getenv - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
>>>>>>> origin/master
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
<<<<<<< HEAD
	char *t;

	while (node)
	{
		t = starts_with(node->str, name);
		if (t && *t)
			return (t);
=======
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
>>>>>>> origin/master
		node = node->next;
	}
	return (NULL);
}

/**
<<<<<<< HEAD
 * _mysetenv - a function that Initialize a new environment variable,
 *             or modify an existing one
 * @info: function parameter
 *  Return: 0
=======
 * _mysetenv - Initialize a new environment variable,
 * or modify an existing one
 * @info: Structure containing potential arguments.
 * Used to maintain constant function prototype.
 * Return: Always 0
>>>>>>> origin/master
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
<<<<<<< HEAD
 * _myunsetenv - a function that removes an environment variable
 * @info: function parameter
 *  Return: 0
 */
int _myunsetenv(info_t *info)
{
	int x;
=======
 * _myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments.
 * Used to maintain constant function prototype.
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int i;
>>>>>>> origin/master

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
<<<<<<< HEAD
	for (x = 1; x <= info->argc; x++)
		_unsetenv(info, info->argv[x]);
=======
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);
>>>>>>> origin/master

	return (0);
}

/**
<<<<<<< HEAD
 * populate_env_list - a function that populates env linked list
 * @info: function parameter
 * Return: 0
=======
 * populate_env_list - populates env linked list
 * @info: Structure containing potential arguments.
 * Used to maintain constant function prototype.
 * Return: Always 0
>>>>>>> origin/master
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
<<<<<<< HEAD
	size_t x;

	for (x = 0; environ[x]; x++)
		add_node_end(&node, environ[x], 0);
=======
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
>>>>>>> origin/master
	info->env = node;
	return (0);
}

