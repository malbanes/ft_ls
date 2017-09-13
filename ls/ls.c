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

char    *ft_add_path(char *av, char *path)
{
    int i;
    int j;
    char *ret;
    
    ret = NULL;
    i = 0;
    j = 0;
    if ((ret = malloc(sizeof(char)*(ft_strlen(av) + ft_strlen(path) + 2))) == NULL)
        return (NULL);
    while (path[i] != '\0')
    {
        ret[i] = path[i];
        i++;
    }
    ret[i] = '/';
    i++;
    while (av[j] != '\0')
    {
        ret[i] = av[j];
        i++;
        j++;
    }
    ret[i] = '\0';
    return (ret);
}

t_lst   *ft_lstnew_ls(struct dirent *dir, char *path)
{
    t_lst   *lst;

    if((lst = malloc(sizeof(t_lst))) == NULL)
    {
        exit (2);
        //exit propre
    }
    lst->data = dir;
    if (lst->data->d_type == DT_DIR)
    {
        if ((lst->path = ft_add_path(dir->d_name, path)) == NULL)
        {
            exit (2);
            //exit propre
        }
    }
    else
        lst->path = NULL;
    lst->next = NULL;
    return (lst);
}
/*
int	main(int ac, char **av)
{
	t_struct_ls	*stru_ls;
	t_lst   *lst;
    t_opt   *options;
	int i;

    stru_ls = init_struct_ls(stru_ls);
	//stru_ls->opt = init_options(options);
    options = init_options();
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
}*/
