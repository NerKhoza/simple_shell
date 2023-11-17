#include "shell.h"

/**
 * _myhistory - a function that displays the history list
 * @info: function parameter
 *  Return: 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
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
	return (ret);
}

/**
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
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
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
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - a function that mimics the alias builtin
 * @info: function parameter
 *  Return: 0
 */
int _myalias(info_t *info)
{
	int x = 0;
	char *t = NULL;
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
	for (x = 1; info->argv[x]; x++)
	{
		t = _strchr(info->argv[x], '=');
		if (t)
			set_alias(info, info->argv[x]);
		else
			print_alias(node_starts_with(info->alias, info->argv[x], '='));
	}

	return (0);
}

