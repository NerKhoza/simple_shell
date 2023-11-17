#include "shell.h"

/**
<<<<<<< HEAD
 * list_len - determines length of linked list
 * @h: parameter 1
 * Return: integer
 */
size_t list_len(const list_t *h)
{
	size_t x = 0;
=======
 * list_len - determines length of linked list.
 * @h: pointer to first node.
 *
 * Return: size of list.
 */
size_t list_len(const list_t *h)
{
	size_t i = 0;
>>>>>>> origin/master

	while (h)
	{
		h = h->next;
<<<<<<< HEAD
		x++;
	}
	return (x);
}

/**
 * list_to_strings - returns an array of strings of the list->str
 * @head: parameter 1
 * Return: array
=======
		i++;
	}
	return (i);
}

/**
 * list_to_strings - returns an array of strings of the list->str.
 * @head: pointer to first node.
 *
 * Return: array of strings.
>>>>>>> origin/master
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
<<<<<<< HEAD
	size_t x = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !x)
		return (NULL);
	strs = malloc(sizeof(char *) * (x + 1));
	if (!strs)
		return (NULL);
	for (x = 0; node; node = node->next, x++)
=======
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
>>>>>>> origin/master
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
<<<<<<< HEAD
			for (j = 0; j < x; j++)
=======
			for (j = 0; j < i; j++)
>>>>>>> origin/master
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
<<<<<<< HEAD
		strs[x] = str;
	}
	strs[x] = NULL;
=======
		strs[i] = str;
	}
	strs[i] = NULL;
>>>>>>> origin/master
	return (strs);
}


/**
<<<<<<< HEAD
 * print_list - prints all elements of a list_t linked list
 * @h: parameter 1
 * Return: integer
 */
size_t print_list(const list_t *h)
{
	size_t x = 0;
=======
 * print_list - prints all the elements of a list_t linked list.
 * @h: pointer to first node.
 *
 * Return: size of the list.
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;
>>>>>>> origin/master

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
<<<<<<< HEAD
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
=======
		i++;
	}
	return (i);
}

/**
 * node_starts_with - returns node whose string starts with a prefix.
 * @node: pointer to list head.
 * @prefix: string to match.
 * @c: the next character after prefix to match.
 *
 * Return: match node or null.
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
>>>>>>> origin/master
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
<<<<<<< HEAD
 * get_node_index - a function that gets the index of a node
 * @head: parameter 1
 * @node: parameter 2
 * Return: index or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t x = 0;
=======
 * get_node_index - gets the index of a node.
 * @head: pointer to list head.
 * @node: pointer to the node.
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;
>>>>>>> origin/master

	while (head)
	{
		if (head == node)
<<<<<<< HEAD
			return (x);
		head = head->next;
		x++;
	}
	return (-1);
}

=======
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
>>>>>>> origin/master
