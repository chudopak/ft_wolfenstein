/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:39:28 by pmarash           #+#    #+#             */
/*   Updated: 2021/01/26 18:29:43 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"
#include "cub2d.h"

t_pl	player_init(t_data *img, int i, int j)
{
	t_pl	player;

	player.i = (float)i;
	player.j = (float)j;
	increase_part_wall(img, i * 20, j * 20, 0x00FF00FF, 20);
	return (player);
}