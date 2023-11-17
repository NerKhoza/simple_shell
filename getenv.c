#include "shell.h"

/**
<<<<<<< HEAD
 * get_environ - a function that returns the string array copy of our environ
 * @info: function parameter
 * Return: 0
=======
 * get_environ - returns the string array copy of our environ.
 * @info: Structure containing potential arguments. Used to maintain.
 * Used to maintain constant function prototype.
 * Return: Always 0
>>>>>>> origin/master
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
<<<<<<< HEAD
 * _unsetenv - a function that removes an environment variable
 * @info: parameter 1
 * @var: parameter 2
 *  Return: 1 or 0
=======
 * _unsetenv - Remove an environment variable.
 * @info: Structure containing potential arguments. Used to maintain
 * Used to maintain constant function prototype.
 * Return: 1 on delete, 0 otherwise.
 * @var: the string env var property.
>>>>>>> origin/master
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
<<<<<<< HEAD
	size_t x = 0;
	char *t;
=======
	size_t i = 0;
	char *p;
>>>>>>> origin/master

	if (!node || !var)
		return (0);

	while (node)
	{
<<<<<<< HEAD
		t = starts_with(node->str, var);
		if (t && *t == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), x);
			x = 0;
=======
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), i);
			i = 0;
>>>>>>> origin/master
			node = info->env;
			continue;
		}
		node = node->next;
<<<<<<< HEAD
		x++;
=======
		i++;
>>>>>>> origin/master
	}
	return (info->env_changed);
}

/**
<<<<<<< HEAD
 * _setenv - a function Initialize a new environment variable,
 *             or modify an existing one
 * @info: parameter 1
 * @var: parameter 2
 * @value: parameter 3
 *  Return: 0
=======
 * _setenv - Initialize a new environment variable,
 * or modify an existing one.
 * @info: Structure containing potential arguments.
 * Used to maintain constant function prototype.
 * @var: the string env var property.
 * @value: the string env var value.
 *  Return: Always 0
>>>>>>> origin/master
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
<<<<<<< HEAD
	char *t;
=======
	char *p;
>>>>>>> origin/master

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
<<<<<<< HEAD
		t = starts_with(node->str, var);
		if (t && *t == '=')
=======
		p = starts_with(node->str, var);
		if (p && *p == '=')
>>>>>>> origin/master
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}

