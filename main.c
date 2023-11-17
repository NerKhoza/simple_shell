#include "shell.h"

/**
<<<<<<< HEAD
 * main - main function
 * @ac: parameter 1
 * @av: parameter 2
 * Return: 0 and 1
=======
 * main - entry point.
 * @ac: arg count.
 * @av: arg vector.
 *
 * Return: 0 on success, 1 on error
>>>>>>> origin/master
 */
int main(int ac, char **av)
{
	info_t info[] = { INFO_INIT };
<<<<<<< HEAD
	int bf = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (bf)
		: "r" (bf));

	if (ac == 2)
	{
		bf = open(av[1], O_RDONLY);
		if (bf == -1)
=======
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
>>>>>>> origin/master
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
<<<<<<< HEAD
		info->readfd = bf;
=======
		info->readfd = fd;
>>>>>>> origin/master
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}
<<<<<<< HEAD

=======
>>>>>>> origin/master
