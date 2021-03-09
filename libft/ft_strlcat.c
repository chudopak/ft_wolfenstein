/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:49:02 by pmarash           #+#    #+#             */
/*   Updated: 2020/12/09 16:15:52 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	sz;

	if (!dst && !src)
		return (0);
	sz = ft_strlen(dst);
	if (size < sz)
		return (ft_strlen((char*)src) + size);
	i = 0;
	if (size > 0)
	{
		while (src[i] && sz + 1 < size)
			dst[sz++] = src[i++];
		dst[sz] = '\0';
	}
	while (src[i])
	{
		i++;
		sz++;
	}
	return (sz);
}
