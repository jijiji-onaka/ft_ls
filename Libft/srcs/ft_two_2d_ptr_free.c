/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_two_2d_ptr_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 18:05:00 by tjinichi          #+#    #+#             */
/*   Updated: 2020/12/01 18:05:12 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	two_2d_ptr_free(void ***p1, void ***p2)
{
	free(*p1);
	*p1 = NULL;
	free(*p2);
	*p2 = NULL;
}
