/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:37:10 by pmarash           #+#    #+#             */
/*   Updated: 2021/01/26 18:26:48 by pmarash          ###   ########.fr       */
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
		increase_part_wall(img, (float)(i * 20), (float)(j * 20), 0x00FFBB00, 20);
		return ;
	}
	if (parsed.map[i][j] == '2')
		increase_part_wall(img, (float)(i * 20), (float)(j * 20), 0x0000BBFF, 20);
	if (parsed.map[i][j] == '.')
	{
		increase_part_wall(img, (float)(i * 20), (float)(j * 20), 0x11FFBBFF, 20);
		parsed.map[i][j] = '0';
	}
	print_map(img, i - 1, j, parsed);
	print_map(img, i, j - 1, parsed);
	print_map(img, i, j + 1, parsed);
	print_map(img, i + 1, j, parsed);
}
