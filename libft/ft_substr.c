/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:45:27 by pmarash           #+#    #+#             */
/*   Updated: 2020/12/09 16:16:04 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s1, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	start_sub;
	unsigned int	i;
	unsigned int	check_len;

	substr = 0;
	start_sub = start - 1;
	i = 0;
	if (!s1)
		return (0);
	if ((check_len = ft_strlen(s1)) < start)
	{
		substr = (char*)malloc(sizeof(char));
		substr[0] = '\0';
		return (substr);
	}
	while (s1[++start_sub])
		i++;
	if (i < len)
		len = i;
	substr = (char*)malloc(sizeof(char) * (len + 1));
	if (substr)
		ft_strlcpy(substr, s1 + start, len + 1);
	return (substr);
}
