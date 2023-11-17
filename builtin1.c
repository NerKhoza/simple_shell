#include "shell.h"

/**
<<<<<<< HEAD
 * _myhistory - a function that displays the history list
 * @info: function parameter
 *  Return: 0
=======
 * _myhistory - displays the history of the list,only one command by line.
 * preceded with the line numbers, starting at 0.
 * @info: Structure containing potential arguments.
 * Used to maintain constant function prototype.
 * Return: Always 0
>>>>>>> origin/master
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
<<<<<<< HEAD
 * unset_alias - a function that sets alias to string
 * @info: parameter 1
 * @str: parameter 2
 * Return: 0 or 1
 */
int unset_alias(info_t *info, char *str)
{
	char *t, c;
	int ret;

	t = _strchr(str, '=');
	if (!t)
		return (1);
	c = *t;
	*t = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*t = c;
=======
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
>>>>>>> origin/master
	return (ret);
}

/**
<<<<<<< HEAD
 * set_alias - a function that sets alias to string
 * @info: parameter 1
 * @str: parameter 2
 * Return:  0 or 1
 */
int set_alias(info_t *info, char *str)
{
	char *t;

	t = _strchr(str, '=');
	if (!t)
		return (1);
	if (!*++t)
=======
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
>>>>>>> origin/master
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
<<<<<<< HEAD
 * print_alias - a function that prints an alias string
 * @node: function parameter
 * Return: 0 aor 1
 */
int print_alias(list_t *node)
{
	char *t = NULL, *b = NULL;

	if (node)
	{
		t = _strchr(node->str, '=');
		for (b = node->str; b <= t; b++)
			_putchar(*b);
		_putchar('\'');
		_puts(t + 1);
=======
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
>>>>>>> origin/master
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
<<<<<<< HEAD
 * _myalias - a function that mimics the alias builtin
 * @info: function parameter
 *  Return: 0
 */
int _myalias(info_t *info)
{
	int x = 0;
	char *t = NULL;
=======
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure containing the potential arguments. Used to maintain.
 * constant function prototype.
 * Return: Always 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
>>>>>>> origin/master
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
<<<<<<< HEAD
	for (x = 1; info->argv[x]; x++)
	{
		t = _strchr(info->argv[x], '=');
		if (t)
			set_alias(info, info->argv[x]);
		else
			print_alias(node_starts_with(info->alias, info->argv[x], '='));
=======
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
>>>>>>> origin/master
	}

	return (0);
}

