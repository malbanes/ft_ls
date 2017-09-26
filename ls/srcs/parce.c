#include "ls.h"

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
        }
        else
            options->arg++;
        i++;
    }
    if (error != NULL)
    {
        ft_print_error(&error);
        delt_lst(&error);
    }
}
