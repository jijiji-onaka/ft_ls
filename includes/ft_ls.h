/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:35:48 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/01 19:11:33 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdio.h>
# include <dirent.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include <sys/stat.h>
# include "error.h"
# include "../Libft/srcs/libft.h"

typedef struct	s_option
{
	bool		op_l;
	bool		op_a;
	bool		no_op;
	char		**option;
}				t_option;


int		error_exit(char *s);
void	error_output(char *s);

void	no_option_ls(char *directory);

void	display_2d(char **array2d);
// void	display_1d(char *array);

int		dir_in_file_num(DIR *dir, int *hidden_file_num);
void	width_format_output(char *s);
void	initialize_option_flag(t_option *flag);

void	specified_no_option_ls(char **arg);

void	option_ls(char **arg);

#endif
