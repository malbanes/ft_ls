#include "ls.h"

void    ft_add_time(t_lst **maille, char *path)
{
    struct stat	*buff;
    t_lst   *tmp;
    
    tmp = *maille;
    buff = NULL;
    buff = malloc(sizeof(struct stat));
    //if ((lstat(tmp->path, buff)) != 0)
    if ((lstat(path, buff)) != 0)
    {
        ft_putstr("fail de lstat\n");
        exit (0);
    }
    tmp->sec = buff->st_mtimespec.tv_sec;
    tmp->nsec = buff->st_mtimespec.tv_nsec;
    free(buff);
}

int ft_compare_time(t_lst *maille, t_lst *tmp)
{
    if (maille->sec < tmp->sec)
    {
        return (1);
    }
    else if (maille->sec > tmp->sec)
        return (0);
    else
    {
        if (maille->nsec < tmp->nsec)
            return (1);
        else if (maille->nsec > tmp->nsec)
            return (0);
        else
        {
            if (ft_strcmp(maille->name, tmp->name) > 0)
                return (1);
            else
                return (0);
        }
    }
}

void    parcourir_lst_rtime(t_lst *tmp, t_lst *maille)
{
    while (tmp->next != NULL)
    {
        if (ft_compare_time(maille, tmp) == 0 && ft_compare_time(maille, tmp->next) == 1)
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

void	add_av_rtime(struct dirent *dp, t_opt *options, t_lst **lst, char *path)
{
    t_lst *maille;
    t_lst *tmp;
    
    if (dp == NULL || ft_compare(dp->d_name, options) != -1)
    {
        tmp = *lst;
        maille = ft_lstnew_ls(dp, path);
        ft_add_time(&maille, path);
        if (*lst == NULL)
        {
            *lst = maille;
            return;
        }
        else
        {
            if (ft_compare_time(maille, tmp) == 1)
            {
                maille->next = *lst;
                *lst = maille;
                return;
            }
            parcourir_lst_rtime(tmp, maille);
        }
    }
}


void    parcourir_lst_time(t_lst *tmp, t_lst *maille)
{
    while (tmp->next != NULL)
    {
        if (ft_compare_time(maille, tmp) == 1 && ft_compare_time(maille, tmp->next) == 0)
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

void	add_av_time(struct dirent *dp, t_opt *options, t_lst **lst, char *path)
{
    t_lst *maille;
    t_lst *tmp;
    
    if (dp == NULL || ft_compare(dp->d_name, options) != -1)
    {
        tmp = *lst;
        maille = ft_lstnew_ls(dp, path);
        ft_add_time(&maille, path);
        if (*lst == NULL)
        {
            *lst = maille;
            return;
        }
        else
        {
            if (ft_compare_time(maille, tmp) == 0)
            {
                maille->next = *lst;
                *lst = maille;
                return;
            }
            parcourir_lst_time(tmp, maille);
        }
    }
}
