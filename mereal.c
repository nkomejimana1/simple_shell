#include "shell.h"
/**
 * _bellset - fills memory with a constant byte
 * @s: the pointer to the memory area
 * @b: the byte to fill *s with
 * @n: the amount of bytes to be filled
 * Return: (s) a pointer to the memory area s
 */
char *_bellset(char *s, char b, unsigned int n)
{
	unsigned int h;

	for (h = 0; h < n; h++)
		s[h] = b;
	return (s);
}

/**
 * allfree - frees a string of strings
 * @pp: string of strings
 */
void allfree(char **pp)
{
	char **e = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(e);
}

/**
 * _mereal - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_mereal(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
