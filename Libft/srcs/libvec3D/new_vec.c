/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:58:14 by tjinichi          #+#    #+#             */
/*   Updated: 2020/10/23 14:58:24 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_p3	new_vec(double x, double y, double z)
{
	t_p3	res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}
