#include "ls.h"

int	ft_compare(char *av)
{
	int i;
	int err;

	err = 0;
	i = 0;
    //if (av[0] == '.')
    //    return (-1);
	while (av[i] != '\0')
	{
		if (av[i] == '.')
			err ++;
		i++;
	}
	if ((i == 1 && err == 1) || (i == 2 && err == 2))
	{
		return (-1);
	}
	return (0);
}

void	add_av(struct dirent *dp, t_opt *options, t_lst **lst, char *path)
{
	t_lst *maille;
	t_lst *tmp;

	if (ft_compare(dp->d_name) != -1)
	{
		tmp = *lst;
		maille = ft_lstnew_ls(dp, path);
		if (*lst == NULL)
		{
			*lst = maille;
			return;
		}
		else
		{
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
			}
			tmp->next = maille;
		}
	}
}

int	ft_recurcive(char *path, t_opt *options)
{
	struct dirent *dp;
	DIR *dirp;
	t_lst *list;
	t_lst *tmp;
	int i;

	i = 0;
    list = NULL;
	if (path == NULL)
		return (0);
	if ((dirp = opendir(path)) == NULL)
		return (1);
	while ((dp = readdir(dirp)) != NULL)
	{
		add_av(dp, options, &list, path);
	}
	closedir(dirp);
	print_lst(&list);
    ft_putchar('\n');
	tmp = list;
	while (tmp != NULL)
	{
		if ((dirp = opendir(tmp->path)) != NULL)
		{
				ft_putstr(tmp->path);
				ft_putendl(":");
				closedir(dirp);
			if (ft_compare(tmp->data->d_name) != -1)
			{
				ft_recurcive(tmp->path, options);
			}
		}
        i++;
		tmp = tmp->next;
	}
	delt_lst(&list);
	return (0);
}

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
