/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:06:31 by pmarash           #+#    #+#             */
/*   Updated: 2020/11/02 13:12:50 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	unsigned char	*d;
	unsigned char	*s;

	i = -1;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	if (!dst && !src)
		return (0);
	while (++i < n)
		d[i] = s[i];
	return (dst);
}
