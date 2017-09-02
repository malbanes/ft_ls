#include "ls.h"

t_opt	*init_options(void)
{
    t_opt *options;
    
    options = NULL;
    if ((options = malloc(sizeof(t_opt))) == NULL)
        exit(2);
    options->l = 0;
    options->a = 0;
    options->t = 0;
    options->r = 0;
    options->R = 0;
    options->ret = 0;
    options->arg = 0;
    return (options);
}

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

void    print_options(t_opt *options)
{
    ft_putstr("options l = ");
    ft_putnbr(options->l);
    ft_putchar('\n');
    ft_putstr("options a = ");
    ft_putnbr(options->a);
    ft_putchar('\n');
    ft_putstr("options t = ");
    ft_putnbr(options->t);
    ft_putchar('\n');
    ft_putstr("options r = ");
    ft_putnbr(options->r);
    ft_putchar('\n');
    ft_putstr("options R = ");
    ft_putnbr(options->R);
    ft_putchar('\n');
    ft_putstr("options retour = ");
    ft_putnbr(options->ret);
    ft_putchar('\n');
    ft_putstr("options arguments = ");
    ft_putnbr(options->arg);
    ft_putchar('\n');
    while (1);
}
