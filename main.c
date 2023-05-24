#include "shell.h"

/**
 * main - entry point
 * @iteka: arg count
 * @eric: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int iteka, char **eric)
{
	info_t info[] = { INFO_INIT };
	int eric_iteka = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (eric_iteka)
			: "r" (eric_iteka));

	if (iteka == 2)
	{
		eric_iteka = open(av[1], O_RDONLY);
		if (eric_iteka == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(eric[0]);
				_eputs(": 0: Can't open ");
				_eputs(eric[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = eric_iteka;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, eric);
	return (EXIT_SUCCESS);
}

