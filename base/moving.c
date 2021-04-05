#include "../headers/overall.h"

static void	mv_left_right(t_all *all, int way_direction)
{
	all->player.move.step_i = STEP_L_R * cos(all->player.dir) * way_direction;
	all->player.move.step_j = STEP_L_R * sin(all->player.dir) * way_direction;
	all->player.i += all->player.move.step_i;
	axis_i_movement(all);
	all->player.j += all->player.move.step_j;
	axis_j_movement(all);
	check_near_wall(all);
}

static void	mv_foward_back(t_all *all, int way_direction)
{
	all->player.move.step_i = STEP_TO_WALL
			* (-sin(all->player.dir)) * way_direction;
	all->player.move.step_j = STEP_TO_WALL
			* cos(all->player.dir) * way_direction;
	all->player.i += all->player.move.step_i;
	axis_i_movement(all);
	all->player.j += all->player.move.step_j;
	axis_j_movement(all);
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

int			move_player(t_all *all)
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
