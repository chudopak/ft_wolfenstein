/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 13:54:19 by pmarash           #+#    #+#             */
/*   Updated: 2020/12/09 16:15:44 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				**clear_tab(char **tab)
{
	unsigned int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (NULL);
}

static unsigned int		count_pieces(const char *s, char c)
{
	unsigned int	i;
	unsigned int	pieces;

	i = -1;
	pieces = 0;
	while ((s[i + 1] == c) && s[i + 1])
		i++;
	while (s[++i])
		if ((s[i] != c) && (s[i + 1] == c || s[i + 1] == '\0'))
			pieces++;
	return (pieces + 1);
}

static char				*fill_str(unsigned int size,
						const char *s, unsigned int start)
{
	unsigned int	i;
	unsigned int	end_point;
	char			*tab;

	i = 0;
	end_point = start + size;
	if (!(tab = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	while (start < end_point)
	{
		tab[i] = s[start];
		start++;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

static char				**allocate_mem(const char *s, char c,
						char **tab, unsigned char pieces)
{
	unsigned int	size;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (j < pieces)
	{
		size = 0;
		while ((s[i] == c) && s[i])
			i++;
		while ((s[i] != c) && s[i])
		{
			size++;
			i++;
		}
		tab[j] = fill_str(size, s, i - size);
		if (!tab[j])
			return (clear_tab(tab));
		j++;
		i++;
	}
	tab[j] = 0;
	return (tab);
}

char					**ft_split(const char *s, char c)
{
	unsigned int	pieces;
	char			**tab;

	if (!s)
		return (0);
	pieces = count_pieces(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * pieces)))
		return (0);
	tab = allocate_mem(s, c, tab, pieces - 1);
	return (tab);
}
