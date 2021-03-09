/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 18:31:04 by pmarash           #+#    #+#             */
/*   Updated: 2021/03/07 22:36:09 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

int		check_string(char *data)
{
	int		i;

	i = -1;
	while (data[++i] == ' ' || data[i] == '\n' || data[i] == '\0')
		if (data[i] == '\n' || data[i] == '\0')
			return (1);
	return (0);
}

void	check_for_player(t_parse *parsed, char symb, int i, int j)
{
	if (symb == 'N' || symb == 'W' || symb == 'S' || symb == 'E')
	{
		parsed->p_coord.i = i;
		parsed->p_coord.j = j;
		parsed->p_coord.start_angle = symb;
	}
}

void	coloms_size(t_parse *parsed, int current_str_len)
{
	if (parsed->p_coord.coloms < current_str_len)
		parsed->p_coord.coloms = current_str_len;
}
