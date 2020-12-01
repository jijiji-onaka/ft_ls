/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_option_ls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 02:35:32 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/01 19:08:07 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static char	**input_dir_file(char **current_dir_file, \
			char *directory)
{
	DIR				*dir;
	struct dirent	*dp;
	int				i;

	if ((dir = opendir(directory)) == NULL)
	{
		free(current_dir_file);
		error_exit(ERR_OPENDIR);
	}
	i = 0;
	while ((dp = readdir(dir)) != NULL)
	{
		if (ft_memcmp(dp->d_name, ".", 1) == 0)
			continue ;
		current_dir_file[i++] = dp->d_name;
	}
	current_dir_file[i] = NULL;
	closedir(dir);
	return (current_dir_file);
}

void		no_option_ls(char *directory)
{
	DIR				*dir;
	char			**current_dir_file;
	int				alloc_size;
	int				hidden_file_num;

	if ((dir = opendir(directory)) == NULL)
		error_exit(ERR_OPENDIR);
	alloc_size = dir_in_file_num(dir, &hidden_file_num) - hidden_file_num + 1;
	closedir(dir);
	if (!(current_dir_file = malloc(sizeof(char *) * \
			(alloc_size))))
		error_exit(ERR_MALLOC);
	input_dir_file(current_dir_file, directory);
	ft_strsort(current_dir_file);
	display_2d(current_dir_file);
	free(current_dir_file);
}
