/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:24:47 by pmarash           #+#    #+#             */
/*   Updated: 2020/12/09 16:15:47 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	i;
	char			*cp_s;

	i = 0;
	while (s1[i])
		i++;
	cp_s = (char*)malloc(sizeof(char) * (i + 1));
	if (cp_s)
	{
		cp_s[i] = '\0';
		i = -1;
		while (s1[++i])
			cp_s[i] = s1[i];
	}
	return (cp_s);
}
