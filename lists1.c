#include "shell.h"

/**
 * list_len - determines length of linked list
 * @h: parameter 1
 * Return: integer
 */
size_t list_len(const list_t *h)
{
	size_t x = 0;

	while (h)
	{
		h = h->next;
		x++;
	}
	return (x);
}

/**
 * list_to_strings - returns an array of strings of the list->str
 * @head: parameter 1
 * Return: array
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t x = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !x)
		return (NULL);
	strs = malloc(sizeof(char *) * (x + 1));
	if (!strs)
		return (NULL);
	for (x = 0; node; node = node->next, x++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < x; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[x] = str;
	}
	strs[x] = NULL;
	return (strs);
}


/**
 * print_list - prints all elements of a list_t linked list
 * @h: parameter 1
 * Return: integer
 */
size_t print_list(const list_t *h)
{
	size_t x = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		x++;
	}
	return (x);
}

/**
 * node_starts_with - returns node whose string starts with prefix
 * @node: parameter 1
 * @prefix: parameter 2
 * @c: parameter 3
 * Return: node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *t = NULL;

	while (node)
	{
		t = starts_with(node->str, prefix);
		if (t && ((c == -1) || (*t == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - a function that gets the index of a node
 * @head: parameter 1
 * @node: parameter 2
 * Return: index or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t x = 0;

	while (head)
	{
		if (head == node)
			return (x);
		head = head->next;
		x++;
	}
	return (-1);
}
