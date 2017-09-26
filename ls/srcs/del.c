#include "ls.h"

void    delt_lst(t_lst **lst)
{
    t_lst *tmp;
    
    if (*lst == NULL)
    {
        free(*lst);
        return;
    }
    tmp = *lst;
    while ((*lst)->next != NULL)
    {
        tmp = tmp->next;
        free((*lst)->path);
        free((*lst)->name);
        free(*lst);
        *lst = tmp;
    }
    free((*lst)->path);
    free((*lst)->name);
    free(*lst);
}
