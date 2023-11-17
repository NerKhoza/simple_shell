#include "shell.h"

/**
<<<<<<< HEAD
 * get_history_file - a function that gets the history file
 * @info: function parameter
 * Return: string
=======
 * get_history_file - gets the history of the  file.
 * @info: parameter struct.
 *
 * Return: allocated string containg history file.
>>>>>>> origin/master
 */

char *get_history_file(info_t *info)
{
<<<<<<< HEAD
	char *buf, *dr;

	dr = _getenv(info, "HOME=");
	if (!dr)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dr) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dr);
=======
	char *buf, *dir;

	dir = _getenv(info, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
>>>>>>> origin/master
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}

/**
<<<<<<< HEAD
 * write_history - a function that creates a file
 * @info: parameter 1
 * Return: 1 or -1
=======
 * write_history - creates a file, or appends to an existing file.
 * @info: the parameter struct.
 *
 * Return: 1 on success, else -1
>>>>>>> origin/master
 */
int write_history(info_t *info)
{
	ssize_t fd;
	char *filename = get_history_file(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
<<<<<<< HEAD
 * read_history - a function that reads history from file
 * @info: parameter 1
 * Return: histcount or 0
 */
int read_history(info_t *info)
{
	int x, last = 0, linecount = 0;
=======
 * read_history - reads history from file.
 * @info: the parameter struct.
 *
 * Return: histcount on success, 0 otherwise
 */
int read_history(info_t *info)
{
	int i, last = 0, linecount = 0;
>>>>>>> origin/master
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_file(info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
<<<<<<< HEAD
	for (x = 0; x < fsize; x++)
		if (buf[x] == '\n')
		{
			buf[x] = 0;
			build_history_list(info, buf + last, linecount++);
			last = x + 1;
		}
	if (last != x)
=======
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			build_history_list(info, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
>>>>>>> origin/master
		build_history_list(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}

/**
<<<<<<< HEAD
 * build_history_list - a function that adds entry to a history linked list
 * @info: parameter 1
 * @buf: parameter 2
 * @linecount: parameter 3
 * Return: 0
=======
 * build_history_list - adds entry to a history linked list.
 * @info: Structure containing potential arguments. Used to maintain.
 * @buf: buffer.
 * @linecount: the history linecount, histcount.
 *
 * Return: Always 0
>>>>>>> origin/master
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
<<<<<<< HEAD
 * renumber_history - renumbers the history linked list after changes
 * @info: parameter 1
 * Return: histcount
=======
 * renumber_history - renumbers the history linked list after the changes.
 * @info: Structure containing potential arguments. 
 * Used to maintain.
 *
 * Return: the new histcount.
>>>>>>> origin/master
 */
int renumber_history(info_t *info)
{
	list_t *node = info->history;
<<<<<<< HEAD
	int x = 0;

	while (node)
	{
		node->num = x++;
		node = node->next;
	}
	return (info->histcount = x);
=======
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (info->histcount = i);
>>>>>>> origin/master
}

