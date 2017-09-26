/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 10:05:37 by malbanes          #+#    #+#             */
/*   Updated: 2017/09/23 16:07:15 by malbanes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

#include <unistd.h> //write
#include <dirent.h> //opendir readdir closedir
#include <sys/stat.h> //stat lstat
#include <pwd.h> //getpwnam
#include <sys/types.h>
#include <sys/xattr.h> //listxattr
#include <time.h> //time
#include <stdlib.h>
#include <errno.h> // perror
#include <string.h> //strerror
#include "../libft/libft.h"

typedef struct		s_opt
{
	int	l;
	int a;
	int r;
	int R;
	int t;
	int ret;
	int arg;
}					t_opt;

typedef struct s_lst
{
    char        *path;
    char    *name;
	char    type;
    time_t  sec;
    long    nsec;
	struct s_lst	*next;
}				t_lst;

typedef struct		s_struct_ls
{
    t_opt   *opt;
    int     buff_len;
    char    *buff;
    t_lst   *lst;
}					t_struct_ls;

//init.c
char    *str_cpy_ls(char *src, unsigned int len);
t_lst   *ft_lstnew_ls(struct dirent *dir, char *path);

//tri_alph.c
void	(*TypeDeTri(t_opt *options))(struct dirent*, t_opt*, t_lst**, char *);
void	add_av_alph(struct dirent *dp, t_opt *options, t_lst **lst, char *path);
void    parcourir_lst_alph(t_lst *tmp, t_lst *maille);
void    parcourir_lst_ralph(t_lst *tmp, t_lst *maille);
void	add_av_ralph(struct dirent *dp, t_opt *options, t_lst **lst, char *path);

//tri_time.c
void    ft_add_time(t_lst **maille, char *path);
void    parcourir_lst_rtime(t_lst *tmp, t_lst *maille);
void	add_av_rtime(struct dirent *dp, t_opt *options, t_lst **lst, char *path);
void    parcourir_lst_time(t_lst *tmp, t_lst *maille);
void	add_av_time(struct dirent *dp, t_opt *options, t_lst **lst, char *path);

//recurcive.c
int	ft_compare(char *av, t_opt *options);
int	ft_recurcive(char *path, t_opt *options);
char    *ft_add_path(char *av, char *path);

//options.c
t_opt	*init_options(void);
int	ft_check_option_valid(char *av, t_opt *options);
int	found_option(char c, t_opt *options);
void    print_options(t_opt *options);

//parce.c
int	ft_cheack_arg_valide(char *av);
void	ft_parse_arg(char **av, int ac, t_opt	*options);

//del.c
void    delt_lst(t_lst **lst);

//print.c
void    ft_print_error(t_lst **error);
void	print_lst(t_lst **alst, t_opt *options);

//list.c
t_lst	*ft_lstnew_ls_av(char *av);
t_lst	*ft_lstadd_ascii_av(t_lst **alst, char *av, int er);

# endif
