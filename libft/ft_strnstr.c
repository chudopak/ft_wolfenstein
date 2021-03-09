/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:54:42 by pmarash           #+#    #+#             */
/*   Updated: 2020/12/09 16:16:00 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str_big, const char *str_sm, size_t len)
{
	unsigned int	pos;
	unsigned int	j;

	j = 0;
	if (!str_sm[j])
		return ((char*)str_big);
	pos = 0;
	while (str_big[pos] && pos < len)
	{
		j = 0;
		if (str_big[pos] == str_sm[j])
		{
			while (str_sm[j] && str_big[pos + j] == str_sm[j]
					&& (pos + j) < len)
				j++;
			if (str_sm[j] == '\0')
				return ((char*)&str_big[pos]);
		}
		pos++;
	}
	return (0);
}
