#include "shell.h"

/**
 * _intere1 - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */
int _intere1(info_t *info)
{
	int intcheck;

	if (info->argv[1]) /* If there is an exit arguement */
	{
		intcheck = _erratoi(info->argv[1]);
		if (intcheck == -1)
		{
			info->status = 2;
			print_error(info, "Invalid number: ");
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
 * _intere2 - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _intere2(info_t *info)
{
	char *s, *eric, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		eric = _getenv(info, "HOME=");
		if (!eric)
			chdir_ret = /* TODO: what should this be? */
				chdir((eric = _getenv(info, "PWD=")) ? eric : "/");
		else
			chdir_ret = chdir(eric);
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
		chdir_ret = /* TODO: what should this be? */
			chdir((eric = _getenv(info, "OLDPWD=")) ? eric : "/");
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
 * _intere3 - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _intere3(info_t *info)
{
	char **eric_iteka;

	eric_iteka = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*eric_iteka); /* temp att_unused workaround */
	return (0);
}

