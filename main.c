/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:35:33 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/01 05:22:25 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int	main(int argc, char *argv[])
{
	if (argc == 1)
		no_option_ls(".");
	else if (argc >= 2 && argv[1][0] != '-')
		specified_no_option_ls(argv);
	else
		option_ls(argv);
	return (0);
}
