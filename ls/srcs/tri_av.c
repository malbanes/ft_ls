#include "ls.h"

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
            type_de_tri_av(options)(name, option, &list);
            ft_putstr(av[i]); //refaire une fonction typedetri av
            {
                i++;
            }
            //print_list_sauf les dossiers
            se balader dans la liste et si dossier, appliquer "int	ft_recurcive(char *path, t_opt *options)"
            avec en path, le nom du dossier
        }
