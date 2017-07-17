/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 12:02:55 by malbanes          #+#    #+#             */
/*   Updated: 2017/05/02 16:43:47 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
#include <stdio.h>

void	print_lst(t_lst **alst);

t_opt	*init_options(t_opt *options)
{
	if ((options = malloc(sizeof(t_opt))) == NULL)
		exit(2);
	options->l = 0;
	options->a = 0;
	options->t = 0;
	options->r = 0;
	options->R = 0;
	options->ret = 0;
	options->arg = 0;
	return (options);
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
		ft_putendl(tmp->name);
		tmp = tmp->next;
	}
		ft_putstr(tmp->name);
}

void    print_if_dossier(char *name, t_opt *opt)
{
    if (opendir(name) != NULL && opt->arg <= 1)
        ft_putendl(name);
    else if (opendir(name) != NULL && opt->arg > 1)
    {
        ft_putstr(name);
        ft_putendl(":\n");
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
            ft_putendl(tmp->name);
        tmp = tmp->next;
    }
    if (opendir(tmp->name) == NULL)
        ft_putendl(tmp->name);
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
