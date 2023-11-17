#include "shell.h"

/**
 * is_chain - a function that test if current char in buffer
 * @info: parameter 1
 * @buf: parameter 2
 * @p: parameter 3
 * Return: 1 and 0
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t t = *p;

	if (buf[t] == '|' && buf[t + 1] == '|')
	{
		buf[t] = 0;
		t++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[t] == '&' && buf[t + 1] == '&')
	{
		buf[t] = 0;
		t++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[t] == ';')
	{
		buf[t] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = t;
	return (1);
}

/**
 * check_chain - a function that checks we should continue chaining
 * @info: parameter 1
 * @buf: parameter 2
 * @p: parameter 3
 * @i: parameter 4
 * @len: parameter 5
 */

void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}

/**
 * replace_alias - a function that replaces an aliases in the tokenized string
 * @info: parameter 1
 * Return: 1 and 0
 */
int replace_alias(info_t *info)
{
	int x;
	list_t *node;
	char *t;

	for (x = 0; x < 10; x++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		t = _strchr(node->str, '=');
		if (!t)
			return (0);
		t = _strdup(t + 1);
		if (!t)
			return (0);
		info->argv[0] = t;
	}
	return (1);
}

/**
 * replace_vars - a function that replaces vars in the tokenized string
 * @info: the parameter struct
 * Return: 1 and 0
 */
int replace_vars(info_t *info)
{
	int x = 0;
	list_t *node;

	for (x = 0; info->argv[x]; x++)
	{
		if (info->argv[x][0] != '$' || !info->argv[x][1])
			continue;

		if (!_strcmp(info->argv[x], "$?"))
		{
			replace_string(&(info->argv[x]),
				_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[x], "$$"))
		{
			replace_string(&(info->argv[x]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[x][1], '=');
		if (node)
		{
			replace_string(&(info->argv[x]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[x], _strdup(""));
	}
	return (0);
}

/**
 * replace_string - a function that replaces a string
 * @old: parameter 1
 * @new: parameter 2
 * Return: 1 and 0
 */

int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}

