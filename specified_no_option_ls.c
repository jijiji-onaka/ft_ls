/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specified_no_option_ls.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 02:41:24 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/01 05:34:27 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static void	output_dir(char **dir_array, int dir_num)
{
	int	i;

	ft_strsort(dir_array);
	i = 0;
	while (dir_array[i])
	{
		printf("%s:\n", dir_array[i]);
		no_option_ls(dir_array[i]);
		if (i != dir_num - 1)
			write(1, "\n", 1);
		i++;
	}
}

static void	display_one_more_dir(int arg_num, char **arg, \
			int dir_count)
{
	DIR				*dir;
	int				i;
	char			**dir_array;

	if (!(dir_array = malloc(sizeof(char *) * (dir_count + 1))))
		error_exit(ERR_MALLOC);
	i = 0;
	while (arg_num-- > 1)
	{
		if ((dir = opendir(arg[arg_num])) == NULL)
			continue ;
		dir_array[i++] = arg[arg_num];
		closedir(dir);
	}
	dir_array[i] = NULL;
	output_dir(dir_array, i);
	free(dir_array);
}

static void	display_only_one_directory(int arg_num, char **arg)
{
	DIR				*dir;

	while (arg_num-- > 1)
	{
		if ((dir = opendir(arg[arg_num])) == NULL)
			continue ;
		no_option_ls(arg[arg_num]);
		closedir(dir);
		exit(0);
	}
}

static void	func_for_dir(int dir_count, int arg_num, \
		char **arg)
{
	if (dir_count == arg_num - 1 && dir_count == 1)
		display_only_one_directory(arg_num, arg);
	if (dir_count != arg_num - 1 && errno != 20)
		write(1, "\n\n", 2);
	if (errno == 20 && dir_count > 0)
		write(1, "\n\n", 2);
	if (dir_count == 0)
		write(1, "\n", 1);
	display_one_more_dir(arg_num, arg, dir_count);
}

void		specified_no_option_ls(char **arg)
{
	DIR				*dir;
	int				arg_num;
	int				arg_num_tmp;
	int				dir_count;

	arg_num = count_2d(arg);
	dir_count = 0;
	arg_num_tmp = arg_num;
	while (arg_num-- > 1)
	{
		errno = 0;
		if ((dir = opendir(arg[arg_num])) == NULL)
		{
			if (errno != 20)
			{
				error_output(arg[arg_num]);
				continue ;
			}
			width_format_output(arg[arg_num]);
			continue ;
		}
		dir_count++;
		closedir(dir);
	}
	func_for_dir(dir_count, arg_num_tmp, arg);
}
