/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:34:39 by pmarash           #+#    #+#             */
/*   Updated: 2021/01/27 18:09:38 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"
#include "cub2d.h"

void	set_posicion(t_all *all, int size, char coord)
{
	if (coord == 'i')
		all->player.aux = 'i';
	else
		all->player.aux = 'j';
	all->player.size = size;
	all->player.mv_check = 1;
}

int		move_player(int keycode, t_all *all)
{
	if (keycode == 53)
		mlx_destroy_window(all->vars.mlx, all->vars.win);
	if (keycode == 13)
		set_posicion(all, -1, 'i');
	if (keycode == 0)
		set_posicion(all, -1, 'j');
	if (keycode == 1)
		set_posicion(all, 1, 'i');
	if (keycode == 2)
		set_posicion(all, 1, 'j');
	return (0);
}
