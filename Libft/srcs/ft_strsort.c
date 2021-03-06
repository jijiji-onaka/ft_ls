/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:34:18 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/02 02:28:45 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strsort(char **str, int(*cmp_by)(char *, char *))
{
	int		i;
	int		j;
	int		str_num;

	i = 0;
	str_num = count_2d(str);
	while (i < str_num - 1)
	{
		j = i + 1;
		while (j < str_num)
		{
			if ((*cmp_by)(str[i], str[j]) > 0)
				ft_swap((void**)&(str[i]), (void**)&(str[j]));
			j++;
		}
		i++;
	}
}
