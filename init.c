#include "shell.h"
/**
 * _length - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _length(char *s)
{
	int h = 0;

	if (!u)
		return (0);

	while (*u++)
		h++;
	return (h);
}

/**
 * _lexico - performs lexicogarphic comparison of two strangs.
 * @u1: the first strang
 * @u2: the second strang
 *
 * Return: negative if u1 < u2, positive if u1 > u2, zero if u1 == u2
 */
int _lexico(char *u1, char *u2)
{
	while (*u1 && *u2)
	{
		if (*u1 != *u2)
			return (*u1 - *u2);
		u1++;
		u2++;
	}
	if (*u1 == *u2)
		return (0);
	else
		return (*u1 < *u2 ? -1 : 1);
}

/**
 * begins_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *begins_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _ings - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_ings(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
