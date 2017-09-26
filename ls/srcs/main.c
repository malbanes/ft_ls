#include "ls.h"

int	main(int ac, char **av)
{
    t_struct_ls	*ls;
    
    ls = malloc(sizeof(t_struct_ls));
    ls->opt=init_options();
    ft_parse_arg(av, ac, ls->opt);
    //print_options(ls->opt);
    if (ls->opt->arg == 0)
    {
        ft_recurcive(".", ls->opt);
    }
    //	else
    //
    while (1);
    //parcourir les arguments et en faire une liste
    return (1);
}
