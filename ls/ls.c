#include "ls.h"

/*
lire dans le repertoire courant
*/

//void	ft_readdir(DIR *rep)
//{
//struct dirent *lecture;
//			while((lecture = readdir(rep)))
//			{
//				//cree maillon liste
//				list1->type = lecture->d_type; (unsigned char)
//				list1->name = lecture->d_name; (char[256])
//				list1->nxt = NULL;
//			}
//}

int	main(int ac, char **av)
{
	t_opt	*options;
	t_lst   *lst;
	int i;

	options = init_options(options);
	i = 1;
	if (ac > 1) //afficher d'abord les fichier puis les dossier
	{
        ft_parse_arg(av, ac, options);
		while (i < ac)
		{
            if (options->r == 0 && options->t == 0)
            {
                lst = ft_lstadd_ascii_av(&lst, av[i], 0);
            }
		//	if ((opendir(av[i]) != NULL)
		//	{
				//readdir fct RECURSIVE(rep)
		//		closedir(av[i]);
		//	}
			i++;
		}
        print_lst_av(&lst, options);
	}
//	else
//	{
//		if ((DIR *rep = opendir(".")) != NULL)
//		{
//			//readdir fct RECURSIVE(rep)
//			closedir(rep);
//		}
//	}
    return (1);
}
