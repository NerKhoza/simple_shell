#include "shell.h"

/**
<<<<<<< HEAD
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
=======
 * is_chain - test if current char in buffer is a chain delimeter.
 * @info: the parameter struct.
 * @buf: the char buffer.
 * @p: address of current position in buf.
 *
 * Return: 1 if chain delimeter, 0 otherwise.
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';') /* found end of this command */
	{
		buf[j] = 0; /* replace semicolon with null */
>>>>>>> origin/master
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
<<<<<<< HEAD
	*p = t;
=======
	*p = j;
>>>>>>> origin/master
	return (1);
}

/**
<<<<<<< HEAD
 * check_chain - a function that checks we should continue chaining
 * @info: parameter 1
 * @buf: parameter 2
 * @p: parameter 3
 * @i: parameter 4
 * @len: parameter 5
=======
 * check_chain - checks we should continue chaining based on last status.
 * @info: the parameter struct.
 * @buf: the char buffer.
 * @p: address of current position in buf.
 * @i: starting position in buf.
 * @len: length of buf.
 *
>>>>>>> origin/master
 * Return: Void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
<<<<<<< HEAD
	size_t f = *p;
=======
	size_t j = *p;
>>>>>>> origin/master

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
<<<<<<< HEAD
			f = len;
=======
			j = len;
>>>>>>> origin/master
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
<<<<<<< HEAD
			f = len;
		}
	}

	*p = f;
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
=======
			j = len;
		}
	}

	*p = j;
}

/**
 * replace_alias - replaces an aliases in the tokenized string.
 * @info: the parameter struct.
 *
 * Return: 1 if replaced, 0 otherwise.
 */
int replace_alias(info_t *info)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
>>>>>>> origin/master
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
<<<<<<< HEAD
		t = _strchr(node->str, '=');
		if (!t)
			return (0);
		t = _strdup(t + 1);
		if (!t)
			return (0);
		info->argv[0] = t;
=======
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
>>>>>>> origin/master
	}
	return (1);
}

/**
<<<<<<< HEAD
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
=======
 * replace_vars - replaces vars in the tokenized string.
 * @info: the parameter struct.
 *
 * Return: 1 if replaced, 0 otherwise.
 */
int replace_vars(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			replace_string(&(info->argv[i]),
				_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			replace_string(&(info->argv[i]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[i][1], '=');
		if (node)
		{
			replace_string(&(info->argv[i]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[i], _strdup(""));
>>>>>>> origin/master

	}
	return (0);
}

/**
<<<<<<< HEAD
 * replace_string - a function that replaces a string
 * @old: parameter 1
 * @new: parameter 2
 * Return: 1 and 0
=======
 * replace_string - replaces string.
 * @old: address of old string.
 * @new: new string.
 *
 * Return: 1 if replaced, 0 otherwise
>>>>>>> origin/master
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}

