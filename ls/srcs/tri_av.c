#include "ls.h"
void    ft_isdir(t_lst **list, t_opt *options)
{
    t_lst   *tmp;
    DIR *dirp;
    int i;
    
    i = 0;
    tmp = *list;
    if(tmp == NULL)
        return;
    while (tmp->next != NULL)
    {
        if ((dirp = opendir(tmp->name)) != NULL)
        {
            i++;
            ft_putstr(tmp->name);
            ft_putendl(":");
            ft_recurcive(tmp->name, options);
            closedir(dirp);
            if (i < options->arg)
                ft_putchar('\n');
        }
        tmp = tmp->next;
    }
    if ((dirp = opendir(tmp->name)) != NULL)
    {
        if (options->arg > 1)
        {
          //  ft_putchar('\n');
            ft_putstr(tmp->name);
            ft_putendl(":");
        }
        ft_recurcive(tmp->name, options);
        closedir(dirp);
    }
}

void    ft_make_lst_av(int ac, char **av, t_opt *options)
{
    int i;
    
    i = 1;
    t_lst *list;
    
    list = NULL;
    while (i < ac)
    {
        if (ft_cheack_arg_valide(av[i]) == 1)
        {
            TypeDeTri(options)(NULL, options, &list, av[i]);
            //se balader dans la liste et si dossier, appliquer "int	ft_recurcive(char *path, t_opt *options)"
            //avec en path, le nom du dossier
        }
        i++;
    }
    print_lst_av(&list, options);
    ft_isdir(&list, options);
}
