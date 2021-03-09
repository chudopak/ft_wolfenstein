/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 11:34:31 by pmarash           #+#    #+#             */
/*   Updated: 2020/12/09 16:16:02 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, char ch)
{
	unsigned int	i;
	unsigned int	nb_position;

	i = -1;
	nb_position = 0;
	while (str[++i])
		if (str[i] == ch)
			nb_position = i;
	if (str[i] == ch)
		return ((char*)(str + i));
	else if (str[nb_position] == ch)
		return ((char*)(str + nb_position));
	return (0);
}
