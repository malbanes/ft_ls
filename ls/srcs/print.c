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

void	print_lst_av(t_lst **alst, t_opt *options)
{
    t_lst *tmp;
    DIR *dirp;
    int i;
    
    i = 0;
    dirp = NULL;
    if (*alst == NULL)
    {
        return;
    }
    tmp = *alst;
    while (tmp->next != NULL)
    {
        if ((dirp = opendir(tmp->name)) == NULL) // ou ISDIR sur lst->type
        {
            ft_putstr(tmp->name);
            ft_putchar('\n');
        }
        else
        {
            i++;
            closedir(dirp);
        }
        tmp = tmp->next;
    }
    dirp = NULL;
    if ((dirp = opendir(tmp->name)) == NULL) // ou ISDIR sur lst->type
    {
        ft_putstr(tmp->name);
        ft_putchar('\n');
    }
    else
    {
        i++;
        closedir(dirp);
    }
    if (i != options->arg)
        ft_putchar('\n');
    options->arg = i;
}

void	print_lst(t_lst **alst, t_opt *options)
{
    t_lst *tmp;
    
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
}
