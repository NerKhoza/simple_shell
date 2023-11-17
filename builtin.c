#include "shell.h"

/**
<<<<<<< HEAD
 * _myexit - a function that exits the shell
 * @info: function parameter
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
=======
 * _myexit - exits the shell
 * @info: Structure containing potential arguments.
 * Used to maintain constant function prototype.
 * Return: exits with a given exit status.
 * (0) if info.argv[0] != "exit"
>>>>>>> origin/master
 */
int _myexit(info_t *info)
{
	int exitcheck;

<<<<<<< HEAD
	if (info->argv[1])
=======
	if (info->argv[1])  /* If there is an exit arguement */
>>>>>>> origin/master
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
<<<<<<< HEAD
 * _mycd - a function that changes the current directory of the process
 * @info: function parameter
 *  Return: 0
=======
 * _mycd - changes the current directory of the process.
 * @info: Structure containing potential arguments.
 * Used to maintain constant function prototype.
 * Return: Always 0
>>>>>>> origin/master
 */
int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
<<<<<<< HEAD
			chdir_ret = chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
=======
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
>>>>>>> origin/master
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
<<<<<<< HEAD
		chdir_ret = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
=======
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
>>>>>>> origin/master
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
<<<<<<< HEAD
 * _myhelp - a function changes the current directory of the process
 * @info: function parameter
 *  Return: 0
=======
 * _myhelp - changes the current directory of the process.
 * @info: Structure containing potential arguments.
 * Used to maintain constant function prototype.
 *  Return: Always 0
>>>>>>> origin/master
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
<<<<<<< HEAD
		_puts(*arg_array);
=======
		_puts(*arg_array); /* temp att_unused workaround */
>>>>>>> origin/master
	return (0);
}

