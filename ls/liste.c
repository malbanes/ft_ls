#include "ls.h"

int	ft_compare(char *av)
{
	int i;
	int err;

	err = 0;
	i = 0;
	while (av[i] != '\0')
	{
		if (av[i] == '.')
			err ++;
		i++;
	}
	if (i == 1 && err == 1)
		return (-1);
	if (i == 2 && err == 2)
		return (-1);
	return (0);
}

void	add_av(struct dirent *dp, t_opt *options, t_lst **lst)
{
	t_lst *maille;
	t_lst *tmp;

	tmp = *lst;
	maille = ft_lstnew_ls(dp);
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

int	ft_recurcive(char *av, t_opt *options)
{
	struct dirent *dp;
	DIR *dirp;
	t_lst *list;
	t_lst *tmp;
	char	*path;

	//path = ft_strcpy(ft_strnew(ft_strlen(av)), av);
	//ft_putstr(path);
	//free (path);
	list = NULL;
	if (av == NULL)
		return (0);
	if ((dirp = opendir(av)) == NULL)
		return (1);
	while ((dp = readdir(dirp)) != NULL)
	{
		add_av(dp, options, &list);
	}
	closedir(dirp);
	print_lst(&list);
	tmp = list;
	while (tmp != NULL)
	{
		if ((dirp = opendir(tmp->data->d_name)) != NULL)
		{
			if (ft_compare(tmp->data->d_name) != -1)
			{
				ft_putstr(av);
				ft_putstr("/");
				ft_putstr(tmp->data->d_name);
				ft_putendl(":");
				closedir(dirp);
				ft_recurcive(tmp->data->d_name, options);
			}
		}
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
