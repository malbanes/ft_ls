#include "ls.h"

char    *str_cpy_ls(char *src, unsigned int len)
{
    unsigned int i;
    char *ret;
    
    ret = NULL;
    i = 0;
    if ((ret = malloc(sizeof(char)*(len + 1))) == NULL)
        exit(0);
    while (i < len)
    {
        ret[i] = src[i];
        i++;
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
    if (dir != NULL)
    {
        lst->name = str_cpy_ls(dir->d_name, (unsigned int)dir->d_namlen);
        lst->type = dir->d_type;
    //if (lst->type == DT_DIR)
    //{
        if ((lst->path = ft_add_path(dir->d_name, path)) == NULL)
        {
            exit (2);
        //exit propre
        }
    }
    else
    {
        lst->name = str_cpy_ls(path, (unsigned int)ft_strlen(path) + 1);
    }
    lst->sec = 0;
    lst->nsec = 0;
   //     lst->path = NULL;
    lst->next = NULL;
    return (lst);
}

