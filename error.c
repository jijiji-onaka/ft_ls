/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 05:14:49 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/01 05:14:54 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		error_exit(char *s)
{
	perror(s);
	exit(1);
}

void	error_output(char *s)
{
	printf("ls: %s: ", s);
	fflush(stdout);
	perror("");
}
