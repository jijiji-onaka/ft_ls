/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:59:49 by tjinichi          #+#    #+#             */
/*   Updated: 2020/07/11 17:46:53 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_p;
	unsigned char	*src_p;

	if (!dst && !src)
		return (NULL);
	dst_p = (unsigned char*)dst;
	src_p = (unsigned char*)src;
	if (src_p < dst_p)
	{
		while (len > 0)
		{
			dst_p[len - 1] = src_p[len - 1];
			len--;
		}
	}
	else
	{
		ft_memcpy(dst_p, src_p, len);
	}
	return (dst);
}
