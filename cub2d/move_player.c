/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:34:39 by pmarash           #+#    #+#             */
/*   Updated: 2021/02/12 19:25:58 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"
#include "cub2d.h"

static void	set_posicion(t_all *all, int size, char coord)
{
	if (coord == 'i')
		all->player.aux = 'i';
	else
		all->player.aux = 'j';
	all->player.size = size;
	all->player.mv_check = 1;
	all->player.ray_mv_check = 1;
	all->player.old_dir = all->player.dir;
	all->player.old_i = all->player.i;
	all->player.old_j = all->player.j;
}

/*static void	set_angle(t_all *all, float size_a)
{
	all->player.size_a = size_a;
	
}*/

int		move_player(int keycode, t_all *all)
{
	if (keycode == 53)
		//mlx_destroy_window(all->vars.mlx, all->vars.win);
		exit(0);
	else if (keycode == 13)
		set_posicion(all, -MOVE, 'i');
	else if (keycode == 0)
		set_posicion(all, -MOVE, 'j');
	else if (keycode == 1)
		set_posicion(all, MOVE, 'i');
	else if (keycode == 2)
		set_posicion(all, MOVE, 'j');
	else if (keycode == 124)
	{
		all->player.old_dir = all->player.dir;
		all->player.mv_check = 1;
		all->player.dir -= MV_ANGLE;
		all->player.old_i = all->player.i;
		all->player.old_j = all->player.j;
	}	
	else if (keycode == 123)
	{
		all->player.old_dir = all->player.dir;
		all->player.mv_check = 1;
		all->player.dir += MV_ANGLE;
		all->player.old_i = all->player.i;
		all->player.old_j = all->player.j;
	}	
	return (0);
}
