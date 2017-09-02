/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:32:47 by malbanes          #+#    #+#             */
/*   Updated: 2017/05/02 16:36:02 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"
/*
void    print_lst_ls(t_lst **lst, t_opt *opt)
{
    t_lst *tmp;

    if (*alst == NULL)
        return ;
    tmp = *alst;
    while (tmp->next != NULL)
    {
        ft_putendl(tmp->name);
        tmp = tmp->next;
    }
    ft_putendl(tmp->name);
}

char    *ft_strcpy_ls(char *dst, char *src1, char *src2)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (src1[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '/';
    i++;
    while (src2[j])
    {
        dst[i] = src[j];
        j++;
        i++;
    }
    dst[i] = '\0';
    return (dst);
}*/
/*
t_lst	*ft_lstnew_ls(dirent *buff, char *instance)
{
    t_lst *lst;
    
    if((lst = malloc(sizeof(t_lst))) == NULL)
    {
        exit (2);
        //exit propre
    }
    lst->name = malloc(sizeof(char) * (buff->d_namlen + ft_strlen(instance) + 2));
    lst->name = ft_strcpy_ls(lst->name, instance, char buff->d_name); //si t'as des noms trop long faut faire gaffe a la taille de d_name
    lst->next = NULL;
    return (lst);
}*/
/*
t_lst   **ft_tri_ls(dirent *buff, t_lst **lst2, t_opt *options, char *instance)
{
    t_lst *tmp;
    t_lst *element;

    tmp = *lst2;
    element = ft_lstnew_ls(buff, instance);
    while ()
}*/
/*
void    ls_recursive(t_lst **lst, t_opt *options)
{
    t_lst   *lst2;
    t_lst   *tmp;
    DIR     *dir;
    struct dirent *buff;
    
    print_lst;
    lst2 = NULL;
    buff = NULL;
    tmp = *lst;
    while (tmp->next != NULL)
    {
        if ((dir = opendir(tmp->path)) != NULL)
        {
            while ((buff = readdir(dir)) != NULL)
            {
                lst2 = ft_tri_ls(buff, &lst2, options, tmp->path);
                closedir(dir);
                ls_recurcive(lst2, options);
            }
        }
        tmp = tmp->next;
    }
    if ((dir = opendir(*lst->path)) != NULL)
    {
        if ((buff = readdir(dir) != NULL)
        {
            lst2 = ft_tri_ls(buff, &lst2, options);
            closedir(dir);
            ls_recurcive(lst2, options);
        }
    }
    ft_memdell(lst2);
}*/
