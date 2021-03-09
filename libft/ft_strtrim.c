/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 16:57:00 by pmarash           #+#    #+#             */
/*   Updated: 2020/12/09 16:16:03 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_set(const char ch, const char *set)
{
	unsigned int	i;

	i = -1;
	if (set)
		while (set[++i])
			if (set[i] == ch)
				return (1);
	return (0);
}

char				*ft_strtrim(const char *s1, const char *set)
{
	t_trim1	offset;
	char	*trim_s;

	if (!s1 || !set)
		return (0);
	offset.i = 0;
	while (s1[offset.i] && ft_set(s1[offset.i], set))
		offset.i++;
	offset.beg = (char*)&s1[offset.i];
	if ((offset.i = ft_strlen(s1) - 1) != -1)
		while (offset.i >= 0 && ft_set(s1[offset.i], set))
			offset.i--;
	offset.end = (char*)&s1[offset.i];
	if (!*s1 || offset.beg == offset.end)
		offset.len = 2;
	else
		offset.len = offset.end - offset.beg + 2;
	if (!(trim_s = malloc(sizeof(char) * offset.len)))
		return (0);
	ft_strlcpy(trim_s, offset.beg, offset.len);
	return (trim_s);
}
