/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_ls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 04:50:36 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/02 01:35:55 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

static void	file_or_option_num(char **arg, int *op, int *fi)
{
	int		i;

	i = 0;
	while (arg[i])
	{
		if (arg[i][0] == '-')
			(*op)++;
		else
			(*fi)++;
		i++;
	}
}

static void	input_option_and_file(char **option, char **file, \
			char **arg)
{
	int		i;
	int		op_i;
	int		fi_i;
	bool	flag;

	i = 1;
	op_i = 0;
	fi_i = 0;
	flag = false;
	while (arg[i])
	{
		if (arg[i][0] == '-' && flag == false)
			option[op_i++] = arg[i] + 1;
		else
		{
			file[fi_i++] = arg[i];
			flag = true;
		}
		i++;
	}
	option[op_i] = NULL;
	file[fi_i] = NULL;
}

static void	option_check(char option, t_option *info)
{
	if (option == 'l')
		info->op_l = true;
	else if (option == 'a')
		info->op_a = true;
	else
		info->no_op = true;
}

static void	each_option_check(char *option, t_option *info)
{
	int	i;

	i = 0;
	while (option[i])
	{
		option_check(option[i], info);
		i++;
	}
}

static char	**input_dir_file(char **current_dir_file, \
			char *directory, t_option *info)
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
		if (info->op_a == false)
			if (ft_memcmp(dp->d_name, ".", 1) == 0)
				continue ;
		current_dir_file[i++] = dp->d_name;
	}
	current_dir_file[i] = NULL;
	closedir(dir);
	return (current_dir_file);
}

static int	stock_allocated_blocks(char **file_array, struct stat stat_buf)
{
	int		i;
	int		number_of_allocated_blocks;

	i = 0;
	number_of_allocated_blocks = 0;
	while (file_array[i])
	{
		if (lstat(file_array[i], &stat_buf) == 0)
		{
			i++;
			number_of_allocated_blocks += stat_buf.st_blocks;
			continue ;
		}
		array_free_2d((void***)&file_array, i);
		error_exit(ERR_STAT);
	}
	return (number_of_allocated_blocks);
}

static void	set_permission(char permission[11])
{
	int	i;

	i = 0;
	while (i < 10)
	{
		permission[i] = '-';
		i++;
	}
	permission[i] = '\0';
}

static void	put_permission(mode_t mode)
{
	char	permission[11];

	set_permission(permission);
	if (mode & S_IFDIR)
		permission[0] = 'd';
	if (mode & S_IRUSR)
		permission[1] = 'r';
	if (mode & S_IWUSR)
		permission[2] = 'w';
	if (mode & S_IXUSR)
		permission[3] = 'x';
	if (mode & S_IRGRP)
		permission[4] = 'r';
	if (mode & S_IWGRP)
		permission[5] = 'w';
	if (mode & S_IXGRP)
		permission[6] = 'x';
	if (mode & S_IROTH)
		permission[7] = 'r';
	if (mode & S_IWOTH)
		permission[8] = 'w';
	if (mode & S_IXOTH)
		permission[9] = 'x';
	printf("%-11s\n", permission);
}

static void	put_hardlink(int hardlink)
{
	printf("%-2d\n", hardlink);
}

static void	put_uid_and_gid(uid_t uid, gid_t gid)
{

}

static void	put_infomation_for_op_l(struct stat stat_buf, char *file_name)
{
	put_permission(stat_buf.st_mode);
	put_hardlink(stat_buf.st_nlink);
	put_uid_and_gid(stat_buf.st_uid, stat_buf.st_gid);
}

static void	option_ls_l(char **file_array)
{
	struct	stat stat_buf;
	int		i;
	int		number_of_allocated_blocks;

	number_of_allocated_blocks = stock_allocated_blocks(file_array, stat_buf);
	printf("total %d\n", number_of_allocated_blocks);
	fflush(stdout);
	i = 0;
	while (file_array[i])
	{
		if (lstat(file_array[i], &stat_buf) == 0)
		{
			put_infomation_for_op_l(stat_buf, file_array[i]);
			i++;
			continue ;
		}
		array_free_2d((void***)&file_array, i);
		error_exit(ERR_STAT);
	}

}

// printf("アクセス保護 : %o\n", stat_buf.st_mode);
// printf("ハードリンクの数 : %d\n", stat_buf.st_nlink);
// printf("所有者のユーザID : %d\n", stat_buf.st_uid);
// printf("所有者のグループID : %d\n", stat_buf.st_gid);
// printf("容量（バイト単位） : %d\n", stat_buf.st_size);
// printf("最終状態変更時刻 : %s", (char*)ctime(&stat_buf.st_ctime));

static void	option_ls_no_file(t_option *info, char **file)
{
	DIR				*dir;
	char			**current_dir_file;
	int				alloc_size;
	int				hidden_file_num;

	if ((dir = opendir(".")) == NULL)
	{
		two_2d_ptr_free((void ***)(&(info->option)), (void ***)(&(file)));
		error_exit(ERR_OPENDIR);
	}
	alloc_size = dir_in_file_num(dir, &hidden_file_num) + 1;
	if (info->op_a == false)
		alloc_size -= hidden_file_num;
	closedir(dir);
	if (!(current_dir_file = malloc(sizeof(char *) * \
			(alloc_size))))
	{
		two_2d_ptr_free((void ***)(&(info->option)), (void ***)(&(file)));
		error_exit(ERR_MALLOC);
	}
	two_2d_ptr_free((void ***)(&(info->option)), (void ***)(&(file)));
	input_dir_file(current_dir_file, ".", info);
	ft_strsort(current_dir_file);
	// if (info->op_large_r)
	// 	option_ls_large_r(info, current_dir_file);
	// else if (info->op_l)
	// 	current_dir_file = option_ls_l(current_dir_file);
	// else
		// option_ls_easy_op(current_dir_file);
	if (info->op_l)
		option_ls_l(current_dir_file);
	display_2d(current_dir_file);
	free(current_dir_file);
}

static void	divide_features(t_option *info, char **file, int file_num)
{
	if (file[0] == NULL)
	{
		option_ls_no_file(info, file);
	}
	// else
	// {
	// 	option_ls_one_more_file();
	// }
}

static void	divide_options(char **option, char **file, int file_num)
{
	t_option	info;
	int			i;

	initialize_option_flag(&info);
	i = -1;
	while (option[++i])
	{
		if (ft_strlen(option[i]) == 1)
			option_check(option[i][0], &info);
		else
			each_option_check(option[i], &info);
	}
	info.option = option;
	divide_features(&info, file, file_num);
}

void		option_ls(char **arg)
{
	char	**option;
	char	**file;
	int		option_num;
	int		file_num;

	file_or_option_num(arg, &option_num, &file_num);
	if (!(option = malloc(sizeof(char *) * (option_num + 1))))
		error_exit(ERR_MALLOC);
	if (!(file = malloc(sizeof(char *) * (file_num + 1))))
	{
		free(option);
		error_exit(ERR_MALLOC);
	}
	input_option_and_file(option, file, arg);
	divide_options(option, file, file_num);
	free(option);
	free(file);
}
