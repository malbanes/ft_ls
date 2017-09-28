#include "ls.h"

int	main(int ac, char **av)
{
    t_struct_ls	*ls;
    int i;
    
    i = 1;
    ls = malloc(sizeof(t_struct_ls));
    ls->opt=init_options();
    ft_parse_arg(av, ac, ls->opt);
    if (ls->opt->arg == 0 && ls->opt->ret != 2)
    {
        ft_recurcive(".", ls->opt);
    }
    else if (ls->opt->arg > 0)
    {
        ls->opt->is_argument = 1;
        ft_make_lst_av(ac, av, ls->opt);
    }
    //while (1);
    return (1);
}
