#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_eric - checks if character is a delimeter
 * @a: the char to check
 * @eric: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_eric(char a, char *eric)
{
	while (*eric)
		if (*eric++ == a)
			return (1);
	return (0);
}

/**
 * _isiteka - checks for alphabetic character
 * @d: The character to input
 * Return: 1 if d is alphabetic, 0 otherwise
 */

int _isiteka(int d)
{
	if ((d >= 'a' && d <= 'z') || (d >= 'A' && d <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _checker - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _checker(char *s)
{
	int i, sign = 1, findme = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && findme != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			findme = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (findme == 1)
			findme = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

