#include "ls.h"

void	(*TypeDeTri(t_opt *options))(struct dirent*, t_opt*, t_lst**, char *)
{
    if (options->t == 1)
    {
        if (options->r == 1)
        {
            	return(add_av_rtime);
        }
        else
        {
            return(add_av_time);
        }
    }
    else if (options->r == 1)
    {
        	return(add_av_ralph);
    }
    return(add_av_alph);
}

void    parcourir_lst_ralph(t_lst *tmp, t_lst *maille)
{
    while (tmp->next != NULL)
    {
        if (ft_strcmp(maille->name, tmp->name) <= 0 && ft_strcmp(maille->name, tmp->next->name) >= 0)
        {
            maille->next = tmp->next;
            tmp->next = maille;
            tmp = maille->next;
            return;
        }
        if (tmp->next != NULL)
            tmp = tmp->next;
    }
    tmp->next = maille;
}


void	add_av_ralph(struct dirent *dp, t_opt *options, t_lst **lst, char *path)
{
    t_lst *maille;
    t_lst *tmp;
    
    if (ft_compare(dp->d_name, options) == -1)
        return;
    tmp = *lst;
    maille = ft_lstnew_ls(dp, path);
    if (*lst == NULL)
    {
        *lst = maille;
        return;
    }
    else
    {
        if (ft_strcmp(maille->name, tmp->name) > 0)
        {
            maille->next = *lst;
            *lst = maille;
            return;
        }
        parcourir_lst_ralph(tmp, maille);
    }
}

void    parcourir_lst_alph(t_lst *tmp, t_lst *maille)
{
    while (tmp->next != NULL)
    {
        if (ft_strcmp(maille->name, tmp->name) >= 0 && ft_strcmp(maille->name, tmp->next->name) <= 0)
        {
            maille->next = tmp->next;
            tmp->next = maille;
            tmp = maille->next;
            return;
        }
        if (tmp->next != NULL)
            tmp = tmp->next;
            }
    tmp->next = maille;
}

void	add_av_alph(struct dirent *dp, t_opt *options, t_lst **lst, char *path)
{
    t_lst *maille;
    t_lst *tmp;
    
    if (ft_compare(dp->d_name, options) != -1)
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
            if (ft_strcmp(maille->name, tmp->name) < 0)
            {
                maille->next = *lst;
                *lst = maille;
                return;
            }
            parcourir_lst_alph(tmp, maille);
        }
    }
}






