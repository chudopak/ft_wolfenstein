/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:37:10 by pmarash           #+#    #+#             */
/*   Updated: 2021/02/02 21:09:03 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"
#include "cub2d.h"

void	print_map(t_data *img, int i, int j, t_parse parsed)
{
	if (parsed.map[i][j] == '0')
		return ;
	if (parsed.map[i][j] == '1')
	{
		increase_part_wall(img, (float)(i * SCALE), (float)(j * SCALE), WALL, SCALE);
		return ;
	}
	if (parsed.map[i][j] == '2')
		increase_part_wall(img, (float)(i * SCALE), (float)(j * SCALE), SPRITE, SCALE);
	if (parsed.map[i][j] == '.')
	{
		increase_part_wall(img, (float)(i * SCALE), (float)(j * SCALE), EMPT, SCALE);
		parsed.map[i][j] = '0';
	}
	print_map(img, i - 1, j, parsed);
	print_map(img, i, j - 1, parsed);
	print_map(img, i, j + 1, parsed);
	print_map(img, i + 1, j, parsed);
}
