/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:49:13 by chudapak          #+#    #+#             */
/*   Updated: 2021/03/04 19:37:51 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

static void	check_near_wall(t_all *all)
{
	if (all->parsed.map[(int)(all->player.i - STOP_BF_WALL / 1.01)][(int)(all->player.j)] != '0'
			&& all->parsed.map[(int)(all->player.i - STOP_BF_WALL / 1.01)][(int)(all->player.j)] != '.'
			&& all->parsed.map[(int)(all->player.i - STOP_BF_WALL / 1.01)][(int)(all->player.j)] != '2')
		all->player.i = (int)(all->player.i - STOP_BF_WALL / 1.01 + 1) + STOP_BF_WALL / 1.01;
	if (all->parsed.map[(int)(all->player.i + STOP_BF_WALL / 1.01)][(int)(all->player.j)] != '0'
			&& all->parsed.map[(int)(all->player.i + STOP_BF_WALL / 1.01)][(int)(all->player.j)] != '.'
			&& all->parsed.map[(int)(all->player.i + STOP_BF_WALL / 1.01)][(int)(all->player.j)] != '2')
		all->player.i = (int)(all->player.i + STOP_BF_WALL / 1.01) - STOP_BF_WALL / 1.01;
	if (all->parsed.map[(int)(all->player.i)][(int)(all->player.j - STOP_BF_WALL / 1.01)] != '0'
			&& all->parsed.map[(int)(all->player.i)][(int)(all->player.j - STOP_BF_WALL / 1.01)] != '.'
			&& all->parsed.map[(int)(all->player.i)][(int)(all->player.j - STOP_BF_WALL / 1.01)] != '2')
		all->player.j = (int)(all->player.j - STOP_BF_WALL / 1.01 + 1) + STOP_BF_WALL / 1.01;
	if (all->parsed.map[(int)(all->player.i)][(int)(all->player.j + STOP_BF_WALL / 1.01)] != '0'
			&& all->parsed.map[(int)(all->player.i)][(int)(all->player.j + STOP_BF_WALL / 1.01)] != '.'
			&& all->parsed.map[(int)(all->player.i)][(int)(all->player.j + STOP_BF_WALL / 1.01)] != '2')
		all->player.j = (int)(all->player.j + STOP_BF_WALL / 1.01) - STOP_BF_WALL / 1.01;
}

static void	mv_left_right(t_all *all, int way_direction)
{
	float	limit_i;
	float	limit_j;

	limit_i = 0;
	limit_j = 0;
	all->player.move.step_i = STEP_L_R * cos(all->player.dir) * way_direction;
	all->player.move.step_j = STEP_L_R * sin(all->player.dir) * way_direction;
	all->player.i += all->player.move.step_i;
	if (all->player.move.step_i < 0)
	{
		limit_i = -STOP_BF_WALL / 1.01;
		if (all->parsed.map[(int)(all->player.i + limit_i)][(int)(all->player.j)] != '0'
				&& all->parsed.map[(int)(all->player.i + limit_i)][(int)(all->player.j)] != '.'
				&& all->parsed.map[(int)(all->player.i + limit_i)][(int)(all->player.j)] != '2')
			all->player.i = (int)(all->player.i + limit_i + 1) - limit_i;
	}
	else if (all->player.move.step_i > 0)
	{
		limit_i = STOP_BF_WALL / 1.01;
		if (all->parsed.map[(int)(all->player.i + limit_i)][(int)(all->player.j)] != '0'
				&& all->parsed.map[(int)(all->player.i + limit_i)][(int)(all->player.j)] != '.'
				&& all->parsed.map[(int)(all->player.i + limit_i)][(int)(all->player.j)] != '2')
			all->player.i = (int)(all->player.i + limit_i) - limit_i;
	}
	all->player.j += all->player.move.step_j;
	if (all->player.move.step_j < 0)
	{
		limit_j = -STOP_BF_WALL / 1.01;
		if (all->parsed.map[(int)all->player.i][(int)(all->player.j + limit_j)] != '0'
				&& all->parsed.map[(int)all->player.i][(int)(all->player.j + limit_j)] != '.'
				&& all->parsed.map[(int)all->player.i][(int)(all->player.j + limit_j)] != '2')
			all->player.j = (int)(all->player.j + limit_j + 1) - limit_j;
	}
	else if (all->player.move.step_j > 0)
	{
		limit_j = STOP_BF_WALL / 1.01;
		if (all->parsed.map[(int)all->player.i][(int)(all->player.j + limit_j)] != '0'
				&& all->parsed.map[(int)all->player.i][(int)(all->player.j + limit_j)] != '.'
				&& all->parsed.map[(int)all->player.i][(int)(all->player.j + limit_j)] != '2')
			all->player.j = (int)(all->player.j + limit_j) - limit_j;
	}
	check_near_wall(all);
}

static void	mv_foward_back(t_all *all, int way_direction)
{
	float	limit_i;
	float	limit_j;

	limit_i = 0;
	limit_j = 0;
	all->player.move.step_i = STEP_TO_WALL * (-sin(all->player.dir)) * way_direction;
	all->player.move.step_j = STEP_TO_WALL * cos(all->player.dir) * way_direction;
	all->player.i += all->player.move.step_i;
	if (all->player.move.step_i < 0)
	{
		limit_i = -STOP_BF_WALL / 1.01;
		if (all->parsed.map[(int)(all->player.i + limit_i)][(int)(all->player.j)] != '0'
				&& all->parsed.map[(int)(all->player.i + limit_i)][(int)(all->player.j)] != '.'
				&& all->parsed.map[(int)(all->player.i + limit_i)][(int)(all->player.j)] != '2')
			all->player.i = (int)(all->player.i + limit_i + 1) - limit_i;
	}
	else if (all->player.move.step_i > 0)
	{
		limit_i = STOP_BF_WALL / 1.01;
		if (all->parsed.map[(int)(all->player.i + limit_i)][(int)(all->player.j)] != '0'
				&& all->parsed.map[(int)(all->player.i + limit_i)][(int)(all->player.j)] != '.'
				&& all->parsed.map[(int)(all->player.i + limit_i)][(int)(all->player.j)] != '2')
			all->player.i = (int)(all->player.i + limit_i) - limit_i;
	}
	all->player.j += all->player.move.step_j;
	if (all->player.move.step_j < 0)
	{
		limit_j = -STOP_BF_WALL / 1.01;
		if (all->parsed.map[(int)all->player.i][(int)(all->player.j + limit_j)] != '0'
				&& all->parsed.map[(int)all->player.i][(int)(all->player.j + limit_j)] != '.'
				&& all->parsed.map[(int)all->player.i][(int)(all->player.j + limit_j)] != '2')
			all->player.j = (int)(all->player.j + limit_j + 1) - limit_j;
	}
	else if (all->player.move.step_j > 0)
	{
		limit_j = STOP_BF_WALL / 1.01;
		if (all->parsed.map[(int)all->player.i][(int)(all->player.j + limit_j)] != '0'
				&& all->parsed.map[(int)all->player.i][(int)(all->player.j + limit_j)] != '.'
				&& all->parsed.map[(int)all->player.i][(int)(all->player.j + limit_j)] != '2')
			all->player.j = (int)(all->player.j + limit_j) - limit_j;
	}
	check_near_wall(all);
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

int		move_player(t_all *all)
{
	if (all->key.w == 1)
		set_position(all, 'w');
	if (all->key.a == 1)
		set_position(all, 'a');
	if (all->key.s == 1)
		set_position(all, 's');
	if (all->key.d == 1)
		set_position(all, 'd');
	if (all->key.right == 1)
		set_position(all, 'r');
	if (all->key.left == 1)
		set_position(all, 'l');
	return (0);
}