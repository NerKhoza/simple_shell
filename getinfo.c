#include "shell.h"

/**
<<<<<<< HEAD
 * clear_info - a function that initializes info_t struct
 * @info: function parameter
=======
 * clear_info - initializes info_t struct.
 * @info: struct address.
>>>>>>> origin/master
 */
void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
<<<<<<< HEAD
 * set_info - a function that initializes info_t struct
 * @info: parameter 1
 * @av: parameter 2
 */
void set_info(info_t *info, char **av)
{
	int x = 0;
=======
 * set_info - initializes info_t struct.
 * @info: struct address.
 * @av: argument vector.
 */
void set_info(info_t *info, char **av)
{
	int i = 0;
>>>>>>> origin/master

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{

			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
<<<<<<< HEAD
		for (x = 0; info->argv && info->argv[x]; x++)
			;
		info->argc = x;
=======
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;
>>>>>>> origin/master

		replace_alias(info);
		replace_vars(info);
	}
}

/**
<<<<<<< HEAD
 * free_info - a function that frees info_t struct fields
 * @info: parameter 1
 * @all: parameter 2
=======
 * free_info - frees info_t struct fields.
 * @info: struct address.
 * @all: true if freeing all fields.
>>>>>>> origin/master
 */
void free_info(info_t *info, int all)
{
	ffree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		ffree(info->environ);
			info->environ = NULL;
		bfree((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUF_FLUSH);
	}
}
<<<<<<< HEAD

=======
>>>>>>> origin/master