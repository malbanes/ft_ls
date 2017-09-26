#include <sys/stat.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include "libft/libft.h"

int	main(int ac, char **av)
{
	struct stat	*buff1;
	struct stat	*buff2;
	int d = 0;
	char	*buff;

	buff1 = 0;
	buff2 = 0;

	buff = NULL;
	buff = malloc(sizeof(char)*10);
	buff1 = malloc(sizeof(struct stat));
	buff2 = malloc(sizeof(struct stat));
	lstat(av[1], buff1);
	lstat(av[2], buff2);
	d = open(av[1], O_RDONLY); //O_WRONLY
	read(d, (void*)buff, 10);
	ft_putendl(buff);
	close(d);
	ft_putstr("\nvaleur de sec 1:");
	ft_putnbr(buff1->st_mtimespec.tv_sec);
	ft_putstr("\nvaleur de nano sec 1:");
    ft_putnbr(buff1->st_mtimespec.tv_nsec);
    ft_putstr("\nvaleur de sec 2:");
    ft_putnbr(buff2->st_mtimespec.tv_sec);
    ft_putstr("\nvaleur de nano sec 2:");
    ft_putnbr((buff2->st_mtimespec.tv_nsec/1000000));
}
