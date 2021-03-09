/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:25:36 by pmarash           #+#    #+#             */
/*   Updated: 2020/12/09 16:15:53 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	size_t			sz_src;

	if (!dst && !src)
		return (0);
	sz_src = 0;
	while (src[sz_src])
		sz_src++;
	i = -1;
	if (size > 0)
	{
		while (src[++i] && i < (size - 1))
			dst[i] = src[i];
		dst[i] = '\0';
	}
	return (sz_src);
}
