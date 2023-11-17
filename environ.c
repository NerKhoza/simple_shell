#include "shell.h"

/**
 * _myenv - a function that prints the current environment
 * @info: function parameter
 * Return: 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - a function that gets the value of an environ variable
 * @info: parameter 1
 * @name: parameter 2
 * Return: value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *t;

	while (node)
	{
		t = starts_with(node->str, name);
		if (t && *t)
			return (t);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - a function that Initialize a new environment variable,
 *             or modify an existing one
 * @info: function parameter
 *  Return: 0
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
 * _myunsetenv - a function that removes an environment variable
 * @info: function parameter
 *  Return: 0
 */
int _myunsetenv(info_t *info)
{
	int x;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (x = 1; x <= info->argc; x++)
		_unsetenv(info, info->argv[x]);
	return (0);
}

/**
 * populate_env_list - a function that populates env linked list
 * @info: function parameter
 * Return: 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t x;

	for (x = 0; environ[x]; x++)
		add_node_end(&node, environ[x], 0);
	info->env = node;
	return (0);
}

