#include "shell.h"
/**
 * _myin - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myin(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_iteka - sets iteka to string
 * @info: parameter struct
 * @str: the string iteka
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_iteka(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->iteka),
		get_node_index(info->iteka, node_starts_with(info->iteka, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_iteka - sets iteka to string
 * @info: parameter struct
 * @str: the string iteka
 *
 * Return: Always 0 on success, 1 on error
 */
int set_iteka(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_iteka(info, str));

	unset_iteka(info, str);
	return (add_node_end(&(info->iteka), str, 0) == NULL);
}

/**
 * print_iteka - prints an iteka string
 * @node: the iteka node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_iteka(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myiteka - mimics the iteka builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myiteka(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->iteka;
		while (node)
		{
			print_iteka(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_iteka(info, info->argv[i]);
		else
			print_iteka(node_starts_with(info->iteka, info->argv[i], '='));
	}

	return (0);
}
