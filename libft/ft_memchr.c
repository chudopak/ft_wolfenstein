/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:25:29 by pmarash           #+#    #+#             */
/*   Updated: 2020/11/02 14:47:26 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*d;

	d = (unsigned char*)arr;
	i = -1;
	while (++i < n)
		if (d[i] == (unsigned char)c)
			return ((void*)arr + i);
	return (0);
}
