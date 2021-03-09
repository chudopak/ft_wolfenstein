/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:19:59 by pmarash           #+#    #+#             */
/*   Updated: 2020/12/09 16:15:51 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*cct_str;
	t_lis			init;

	init.i = -1;
	init.j = -1;
	init.len_s1 = 0;
	init.len_s2 = 0;
	if (s1)
		init.len_s1 = ft_strlen(s1);
	if (s2)
		init.len_s2 = ft_strlen(s2);
	cct_str = (char*)malloc(sizeof(char) * (init.len_s1 + init.len_s2 + 1));
	if (cct_str)
	{
		while (++init.i < init.len_s1)
			cct_str[init.i] = s1[init.i];
		while (++init.j < init.len_s2)
		{
			cct_str[init.i] = s2[init.j];
			init.i++;
		}
		cct_str[init.i] = '\0';
		return (cct_str);
	}
	return (0);
}
