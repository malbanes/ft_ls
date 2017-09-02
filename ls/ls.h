/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malbanes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 10:05:37 by malbanes          #+#    #+#             */
/*   Updated: 2017/05/02 16:43:50 by malbanes         ###   ########.fr       */
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
#include "libft/libft.h"

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
	unsigned char	type;
	char		*name;
    char        *path;
	struct dirent *data;
	struct s_lst	*next;
}				t_lst;

typedef struct		s_struct_ls
{
    t_opt   *opt;
    int     buff_len;
    char    *buff;
    t_lst   *lst;
}					t_struct_ls;

t_struct_ls    *init_struct_ls(t_struct_ls *stru_ls);
void	print_lst_av(t_lst **alst, t_opt *opt);
void	print_lst(t_lst **alst);
t_lst	*ft_lstadd_ascii_av(t_lst **alst, char *av, int er);
t_lst	*ft_lstnew_ls(struct dirent *dir);
t_opt	*init_options(void);
int	found_option(char c, t_opt *options);
void print_options(t_opt *options);

void	ft_parse_arg(char **av, int ac, t_opt	*options);
char	**ft_get_arg(char **av, int ac, t_opt *opt);
int	ft_cheack_arg_valide(char *av);
int	ft_check_option_valid(char *av, t_opt *options);


# endif
