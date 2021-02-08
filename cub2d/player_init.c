/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:39:28 by pmarash           #+#    #+#             */
/*   Updated: 2021/02/02 20:11:11 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"
#include "cub2d.h"

t_pl	player_init(t_data *img, int i, int j)
{
	t_pl	player;

	player.i = (float)i * SCALE;
	player.j = (float)j * SCALE;
	player.dir = ANGLE;
	player.mv_check = 2;
	increase_part_wall(img, player.i, player.j, PL, SCALE);
	return (player);
}