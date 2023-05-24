#include "shell.h"

/**
 * _string_ - copies a string
 * @eric: the destination
 * @source: the source
 *
 * Return: pointer to destination
 */
char *_string_(char *eric, char *source)
{
	int a = 0;

	if (eric == source || source == 0)
		return (eric);
	while (source[a])
	{
		eric[a] = source[a];
		a++;
	}
	eric[a] = 0;
	return (eric);
}

/**
 * _stringdup - duplicates a string
 * @strang: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_stringdup(const char *strang)
{
	int length = 0;
	char *retantion;

	if (strang == NULL)
		return (NULL);
	while (*strang++)
		length++;
	retantion = malloc(sizeof(char) * (length + 1));
	if (!retantion)
		return (NULL);
	for (length++; length--;)
		retantion[length] = *--strang;
	return (retantion);
}

/**
 * _enter - prints an input string
 * @strong: the string to be printed
 *
 * Return: Nothing
 */
void _enter(char *strong)
{
	int a = 0;

	if (!strong)
		return;
	while (strong[a] != '\0')
	{
		_putchar(strong[a]);
		a++;
	}
}

/**
 * _putchar1 - writes the character i to stdout
 * @i: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar1(char i)
{
	static int ab;
	static char buf[WRITE_BUF_SIZE];

	if (i == BUF_FLUSH || ab >= WRITE_BUF_SIZE)
	{
		write(1, buf, ab);
		ab = 0;
	}
	if (i != BUF_FLUSH)
		buf[ab++] = i;
	return (1);
}

