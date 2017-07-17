#include "ls.h"

int	found_option(char c, t_opt *options)
{
    if (c == 'l')
    {
        options->l = 1;
        return(1);
    }
    if (c == 'a')
    {
        options->a = 1;
        return(1);
    }
    if (c == 't')
    {
        options->t = 1;
        return(1);
    }
    if (c == 'r')
    {
        options->r = 1;
        return(1);
    }
    if (c == 'R')
    {
        options->R = 1;
        return(1);
    }
    return(0);
}
// ls -r -4 arg = illegal option mais ls -r a -4 = no such file et lecture

int	ft_check_option_valid(char *av, t_opt *options)
{
	int i;

	i = 1;
    if (!(av))
        return (0);
	if (av[0] == '\0' || av[0] != '-' || av[1] == '\0')
		return (0);
	while (av[i] != '\0')
	{
        if (options->arg == 0 && options->ret != 2)
        {
            if (found_option(av[i], options) == 0)
            {
                ft_putstr("my_ls : illegal option -- ");
                ft_putchar(av[i]);
                ft_putchar('\n');
                ft_putendl("usage: my_ls [-Ralrt] [file ...]");
                free(options);
                exit(2);
            }
        }
		i++;
	}
            return(1);
}

int	ft_cheack_arg_valide(char *av)
{
	struct stat *buff;
    
	if((buff = malloc(sizeof(struct stat))) == NULL)
		exit(2);
	if (lstat(av, buff))
	{
		free(buff);
		return (0);
	}
	free(buff);
	return(1);
}

void    ft_print_error(t_lst **error)
{
    t_lst *tmp;
    
    if (*error != NULL)
    {
        tmp = *error;
        while (tmp->next != NULL)
        {
            ft_putstr("my_ls: ");
            ft_putstr(tmp->name);
            ft_putendl(": No such file or directory");
            tmp = tmp->next;
        }
        ft_putstr("my_ls: ");
        ft_putstr(tmp->name);
        ft_putendl(": No such file or directory");
    }
}

void	ft_parse_arg(char **av, int ac, t_opt	*options)
{
    t_lst *error;
	int i;

    error = NULL;
	i = 1;
	while (i < ac)
	{
        if (av[i] == NULL)
        {
            ft_putendl("fts_open");
            exit (2);
        }
        if (ft_check_option_valid(av[i], options) == 1 && options->arg == 0 && options->ret != 2);
        else if (opendir(av[i]) == NULL)
        {
            if (ft_cheack_arg_valide(av[i]) == 0)//cheack_arg_valid
            {
                ft_lstadd_ascii_av(&error, av[i], 1);
                options->ret = 2;
            }
            else
                options->arg++;
        }
        //	closedir(av[i]);
		i++;
	}
    if (error != NULL)
        ft_print_error(&error);
}
