/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:40:33 by pmarash           #+#    #+#             */
/*   Updated: 2020/12/24 20:27:09 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, char *src, int size)
{
	int		i;

	i = 0;
	if (!src)
		return (0);
	if (!dst)
		return (0);
	while (src[i] && dst[i] != '\0' && size > 0)
	{
		dst[i] = src[i];
		i++;
		size--;
	}
	return (dst);
}
