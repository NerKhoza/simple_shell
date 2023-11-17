#include "shell.h"

/**
<<<<<<< HEAD
 * is_cmd - a function that determines if a file is an executable command
 * @info: parameter 1
 * @path: parameter 2
 * Return: 1 or 0
=======
 * is_cmd - determines if a file is an executable command.
 * @info: the info struct
 * @path: path to the file.
 *
 * Return: 1 if true, 0 otherwise.
>>>>>>> origin/master
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
<<<<<<< HEAD
 * dup_chars - a function that duplicates characters
 * @pathstr: parameter 1
 * @start: parameter 2
 * @stop: parameter 3
 * Return: pointer
=======
 * dup_chars - duplicates the characters.
 * @pathstr: the PATH string.
 * @start: starting index.
 * @stop: stopping index.
 *
 * Return: pointer to new buffer.
>>>>>>> origin/master
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
<<<<<<< HEAD
	int x = 0, k = 0;

	for (k = 0, x = start; x < stop; x++)
		if (pathstr[x] != ':')
			buf[k++] = pathstr[x];
=======
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
>>>>>>> origin/master
	buf[k] = 0;
	return (buf);
}

/**
<<<<<<< HEAD
 * find_path - a function that finds this cmd in the PATH string
 * @info: parameter 1
 * @pathstr: parameter 2
 * @cmd: parameter 3
 * Return: path of cmd or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int x = 0, curr_pos = 0;
=======
 * find_path - finds this cmd in the PATH of the string.
 * @info: the info struct.
 * @pathstr: the PATH string.
 * @cmd: the cmd to find.
 *
 * Return: full path of cmd if found or NULL.
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
>>>>>>> origin/master
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
<<<<<<< HEAD
		if (!pathstr[x] || pathstr[x] == ':')
		{
			path = dup_chars(pathstr, curr_pos, x);
=======
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);
>>>>>>> origin/master
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
<<<<<<< HEAD
			if (!pathstr[x])
				break;
			curr_pos = x;
		}
		x++;
=======
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
>>>>>>> origin/master
	}
	return (NULL);
}

