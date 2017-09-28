#include "ls.h"

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
