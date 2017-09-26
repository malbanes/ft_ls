#include "ls.h"

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

void	print_lst(t_lst **alst, t_opt *options)
{
    t_lst *tmp;
    
	//if (options->a == 1 && options->r == 0)
	//	ft_putstr(".\n..\n");
    if (*alst == NULL)
    {
        return;
    }
    tmp = *alst;
    while (tmp->next != NULL)
    {
        ft_putstr(tmp->name);
        ft_putchar('\n');
        tmp = tmp->next;
    }
    ft_putstr(tmp->name);
    ft_putchar('\n');
   // if (options->a == 1 && options->r == 1)
     //   ft_putstr(".\n..\n");
}
