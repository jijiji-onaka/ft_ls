/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 02:38:55 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/01 19:07:42 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		dir_in_file_num(DIR *dir, int *hidden_file_num)
{
	struct dirent	*dp;
	int				file_num;

	while ((dp = readdir(dir)) != NULL)
	{
		if (ft_memcmp(dp->d_name, ".", 1) == 0)
			(*hidden_file_num)++;
		file_num++;
	}
	return (file_num);
}

void	width_format_output(char *s)
{
	printf("%-16s", s);
	fflush(stdout);
}

void	initialize_option_flag(t_option *flag)
{
	flag->op_l = false;
	flag->op_a = false;
	flag->no_op = false;
}
