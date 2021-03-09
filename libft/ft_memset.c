/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:04:34 by pmarash           #+#    #+#             */
/*   Updated: 2020/11/02 13:20:43 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*d;

	i = -1;
	d = (unsigned char*)dest;
	while (n != 0)
	{
		d[++i] = (unsigned char)c;
		n--;
	}
	return (dest);
}
