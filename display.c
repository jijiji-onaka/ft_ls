/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 02:37:28 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/01 04:46:00 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	display_2d(char **array2d)
{
	int	i;
	int	count;

	while (array2d[count])
		count++;
	i = 0;
	while (array2d[i])
	{
		if (count <= 3)
			printf("%-8s", array2d[i]);
		else
			printf("%-16s", array2d[i]);
		fflush(stdout);
		if (i != 0 && i % 6 == 0)
		{
			puts("");
			i++;
			continue ;
		}
		i++;
	}
	write(1, "\n", 1);
}
