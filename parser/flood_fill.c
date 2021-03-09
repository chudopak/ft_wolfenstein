/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:28:54 by pmarash           #+#    #+#             */
/*   Updated: 2021/03/08 21:00:43 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

void	flood_fill(char **map, int i, int j, t_parse *parsed)
{
	if (parsed->error_checker == 1)
		return ;
	if (i == parsed->p_coord.rows || i < 0
			|| map[i][j] == '\0' || map[i][j] == ' '
			|| ((j == 0 || i == 0) && map[i][j] == '0'))
	{
		parsed->error_checker = 1;
		return ;
	}
	if (map[i][j] == '1' || map[i][j] == '.' || map[i][j] == '3')
		return ;
	if (map[i][j] == '2')
	{
		parsed->amt_spr++;
		map[i][j] = '3';
	}
	if (map[i][j] == '0')
		map[i][j] = '.';
	flood_fill(map, i - 1, j, parsed);
	flood_fill(map, i, j - 1, parsed);
	flood_fill(map, i, j + 1, parsed);
	flood_fill(map, i + 1, j, parsed);
}
