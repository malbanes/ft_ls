/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 12:02:55 by malbanes          #+#    #+#             */
/*   Updated: 2017/09/02 13:11:41 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include <stdio.h>
#include <dirent.h>

void	print_lst(t_lst **alst);

t_struct_ls    *init_struct_ls(t_struct_ls *stru_ls)
{
    if ((stru_ls = malloc(sizeof(t_struct_ls))) == NULL)
    {
        //exit propre
    }
    stru_ls->opt = NULL;
    stru_ls->buff_len = 0;
    stru_ls->buff = NULL;
    stru_ls->lst = NULL;
    return (stru_ls);
}

t_lst	*ft_lstnew_ls_av(char *av)
{
	t_lst *lst;

	if((lst = malloc(sizeof(t_lst))) == NULL)
	{
		exit (2);
		//exit propre
	}
    lst->name = malloc(sizeof(char) * ft_strlen(av) + 1);
	ft_strcpy(lst->name, av);
	//lst->info = NULL;
	lst->next = NULL;
	return (lst);
}

t_lst	*ft_lstadd_ascii_av(t_lst **alst, char *av, int er)
{
	t_lst	*element;
	t_lst	*tmp;
    
	tmp = *alst;
    if (ft_cheack_arg_valide(av) == 0 && er == 0)
        return (*alst);
	element = ft_lstnew_ls_av(av);
	if (*alst == NULL)
    {
		element->next = NULL;
        *alst = element;
        return(element);
    }
    else
	{
        if (ft_strcmp(element->name, tmp->name) < 0)
        {
            element->next = *alst;
            *alst = element;
            return (*alst);
        }
		while (tmp->next != NULL)
		{
			if (ft_strcmp(element->name, tmp->name) >= 0 && ft_strcmp(element->name, tmp->next->name) <= 0)
            {
                element->next = tmp->next;
                tmp->next = element;
                tmp = element->next;
                return (*alst);
            }
            if (tmp->next != NULL)
                tmp = tmp->next;
		}
        tmp->next = element;
	}
	return (*alst);
}

void	print_lst(t_lst **alst)
{
	t_lst *tmp;

	tmp = *alst;
	while (tmp->next != NULL)
	{
    ft_putstr(tmp->name);
        ft_putchar(' ');
		tmp = tmp->next;
	}
		ft_putstr(tmp->name);
}

void    print_if_dossier(char *name, t_opt *opt)
{
    DIR *dirp;
    struct dirent *buf;
    int i;
    
    i = 0;
    if ((opendir(name) != NULL && opt->arg > 1) ||(opendir(name) != NULL &&  opt->ret != 0))
    {
        ft_putstr(name);
        ft_putendl(":");
    }
    if ((dirp = opendir(name)) != NULL)
    {
        while ((buf = readdir(dirp)) != NULL)
        {
            if (i > 1)
                ft_putendl(buf->d_name);
            i++;
        }
    }
}

void	print_lst_av(t_lst **alst, t_opt *opt)
{
    t_lst *tmp;

    if (*alst == NULL)
        return ;
    tmp = *alst;
    while (tmp->next != NULL)
    {
        if (opendir(tmp->name) == NULL)
        {
            ft_putstr(tmp->name);
            ft_putchar(' ');
        }
            tmp = tmp->next;
    }
    if (opendir(tmp->name) == NULL)
    {
        ft_putendl(tmp->name);
        putchar('\n');
    }
    tmp = *alst;
    while (tmp->next != NULL)
    {
        print_if_dossier(tmp->name, opt);
        tmp = tmp->next;
    }
    print_if_dossier(tmp->name, opt);
}

//void	ft_swap_content(t_lst *lst1, t_lst *lst2)
//{
//	char	tmp[255];
//
//	ft_strcpy(tmp, lst1->name);
//	ft_strcpy(lst1->name, lst2->name);
//	ft_strcpy(lst2->name, tmp);
//}

/* <<<<<<<<<<<<<<<<<< MAIN TEST LISTE CHAINEE >>>>>>>>>>>>>>>>>> */

/*int	main(int ac, char **av)
{
	int i;
	t_lst *lst;
	t_opt	*options;

	i = 1;
	options = init_options(options);
	while (av[i] != NULL)
	{
		lst = ft_lstadd_ascii_av(&lst, av[i], options->r);
		//ft_putendl(" ");
		i++;
	}
	print_lst_av(&lst);
	return (0);
}*/
