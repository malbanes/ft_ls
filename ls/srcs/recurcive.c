#include "ls.h"

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

int	ft_compare(char *av, t_opt *options)
{
    int i;
    int err;
    
    err = 0;
    i = 0;
    if (options->a == 0 && av[0] == '.')// Permet de ne pas enregistrer les dossier cachee
        return (-1);
    while (av[i] != '\0')
    {
        if (av[i] == '.')
            err ++;
        i++;
    }
    if ((i == 1 && err == 1) || (i == 2 && err == 2))
    {
        return (-2);
    }
    return (0);
}

int	ft_recurcive(char *path, t_opt *options)
{
    struct dirent *dp;
    DIR *dirp;
    t_lst *list;
    t_lst *tmp;
    
    list = NULL;
    if (path == NULL)
        return (0);
    if ((dirp = opendir(path)) == NULL)
        return (1);
	//seekdir(dirp, 2);
    
    while ((dp = readdir(dirp)) != NULL)
	{
		TypeDeTri(options)(dp, options, &list, path);
	}
	closedir(dirp);
    print_lst(&list, options);
	if (options->R == 1)
	{
		ft_putchar('\n');
		tmp = list;
		while (tmp != NULL)
		{
			if ((dirp = opendir(tmp->path)) != NULL)
			{
				if (ft_compare(tmp->name, options) != -1 && ft_compare(tmp->name, options) != -2) //cf ft_compare pour plus d'options
				{
					ft_putstr(tmp->path);
					ft_putendl(":");
				}
				closedir(dirp);
				if (ft_compare(tmp->name, options) != -1 && ft_compare(tmp->name, options) != -2)
					ft_recurcive(tmp->path, options);
			}
			tmp = tmp->next;
		}
	}
    delt_lst(&list);
    return (0);
}
