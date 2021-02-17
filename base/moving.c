/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:49:13 by chudapak          #+#    #+#             */
/*   Updated: 2021/02/16 21:24:26 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

static void	mv_left_right(t_all *all, int way_direction)
{
	double	step_i;
	double	step_j;

	step_i = STEP_TO_WALL * cos(all->player.dir) * way_direction;
	step_j = STEP_TO_WALL * sin(all->player.dir) * way_direction;
	all->player.i += step_i;
	all->player.j += step_j;
	if (all->parsed.map[(int)(all->player.i + step_i)][(int)(all->player.j + step_j)] == '1'
			|| all->parsed.map[(int)(all->player.i + step_i)][(int)(all->player.j + step_j)] == '2')
	{
		all->player.i -= step_i;
		all->player.j -= step_j;
	}
}

static void	mv_foward_back(t_all *all, int way_direction)
{
	double	step_i;
	double	step_j;

	step_i = STEP_TO_WALL * (-sin(all->player.dir)) * way_direction;
	step_j = STEP_TO_WALL * cos(all->player.dir) * way_direction;
	all->player.i += step_i;
	all->player.j += step_j;
	if (all->parsed.map[(int)(all->player.i + step_i)][(int)(all->player.j + step_j)] == '1'
			|| all->parsed.map[(int)(all->player.i + step_i)][(int)(all->player.j + step_j)] == '2')
	{
		all->player.i -= step_i;
		all->player.j -= step_j;
	}
}

static void	set_position(t_all *all, char coord)
{
	if (coord == 'd')
		mv_left_right(all, 1);
	else if (coord == 'a')
		mv_left_right(all, -1);
	else if (coord == 'w')
		mv_foward_back(all, 1);
	else if (coord == 's')
		mv_foward_back(all, -1);
	else if (coord == 'l')
		all->player.dir += ANGLE_MOVE;
	else if (coord == 'r')
		all->player.dir -= ANGLE_MOVE;
	all->player.mv_check = 1;
}

int		move_player(int keycode, t_all *all)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 13)
		set_position(all, 'w');
	else if (keycode == 0)
		set_position(all, 'a');
	else if (keycode == 1)
		set_position(all, 's');
	else if (keycode == 2)
		set_position(all, 'd');
	else if (keycode == 124)
		set_position(all, 'r');
	else if (keycode == 123)
		set_position(all, 'l');
	return (0);
}