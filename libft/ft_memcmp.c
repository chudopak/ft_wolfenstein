/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:52:47 by pmarash           #+#    #+#             */
/*   Updated: 2020/11/02 15:00:28 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	i;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	i = -1;
	while (++i < n)
		if (d[i] != s[i])
			return ((int)(d[i] - s[i]));
	return (0);
}
