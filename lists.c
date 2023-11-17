#include "shell.h"

/**
<<<<<<< HEAD
 * add_node - a function adds a node to the start of the list
 * @head: parameter 1
 * @str: parameter 2
 * @num: parameter 3
 * Return: integer
=======
 * add_node - adds a node to the start of the list.
 * @head: address of pointer to head node.
 * @str: str field of node.
 * @num: node index used by the history.
 *
 * Return: size of list.
>>>>>>> origin/master
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
<<<<<<< HEAD
 * add_node_end - a function adds a node to the end of the list
 * @head: parameter 1
 * @str: parameter 2
 * @num: parameter 3
 * Return: integer
=======
 * add_node_end - adds a node to the end of the list.
 * @head: address of pointer to head node.
 * @str: str field of node.
 * @num: node index used by the history.
 *
 * Return: size of list.
>>>>>>> origin/master
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
<<<<<<< HEAD
 * print_list_str - prints only the str element of a list_t linked list
 * @h: parameter 1
 * Return: integer
 */
size_t print_list_str(const list_t *h)
{
	size_t x = 0;
=======
 * print_list_str - prints only the str element of a list_t linked list.
 * @h: pointer to first node.
 *
 * Return: size of list.
 */
size_t print_list_str(const list_t *h)
{
	size_t i = 0;
>>>>>>> origin/master

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
<<<<<<< HEAD
		x++;
	}
	return (x);
}

/**
 * delete_node_at_index - a function that deletes node at given index
 * @head: parameter 1
 * @index: parameter 2
 * Return: 1 or 0
=======
		i++;
	}
	return (i);
}

/**
 * delete_node_at_index - deletes node at given index.
 * @head: address of pointer to first node.
 * @index: index of node to delete.
 *
 * Return: 1 on success, 0 on failure.
>>>>>>> origin/master
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
<<<<<<< HEAD
	unsigned int x = 0;
=======
	unsigned int i = 0;
>>>>>>> origin/master

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
<<<<<<< HEAD
		if (x == index)
=======
		if (i == index)
>>>>>>> origin/master
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
<<<<<<< HEAD
		x++;
=======
		i++;
>>>>>>> origin/master
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
<<<<<<< HEAD
 * free_list - a function that frees all nodes of a list
 * @head_ptr: parameter 1
=======
 * free_list - frees all nodes of a list.
 * @head_ptr: address of pointer to head node.
 *
>>>>>>> origin/master
 * Return: void
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}

