#include "../headers/overall.h"

static void	step_off_wall(t_all *all)
{
	if (all->parsed.map[(unsigned int)(all->player.i - 0.5)]
			[(unsigned int)all->player.j] == '1')
		all->player.i += STOP_BF_WALL;
	else if (all->parsed.map[(unsigned int)(all->player.i + 0.5)]
			[(unsigned int)all->player.j]
			== '1')
		all->player.i -= STOP_BF_WALL;
	if (all->parsed.map[(unsigned int)all->player.i]
			[(unsigned int)(all->player.j - 0.5)] == '1')
		all->player.j += STOP_BF_WALL;
	else if (all->parsed.map[(unsigned int)all->player.i]
			[(unsigned int)(all->player.j + 0.5)]
			== '1')
		all->player.j -= STOP_BF_WALL;
}

static void	fill_keys(t_all *all)
{
	all->key.w = 0;
	all->key.a = 0;
	all->key.s = 0;
	all->key.d = 0;
	all->key.right = 0;
	all->key.left = 0;
}

int			set_player(t_all *all)
{
	fill_keys(all);
	all->player.i = (float)all->parsed.p_coord.i;
	all->player.j = (float)all->parsed.p_coord.j;
	all->parsed.map[(unsigned int)(all->player.i)]
			[(unsigned int)all->player.j] = '0';
	step_off_wall(all);
	if (all->parsed.p_coord.start_angle == 'N')
		all->player.dir = M_PI / 2;
	else if (all->parsed.p_coord.start_angle == 'E')
		all->player.dir = 2 * M_PI;
	else if (all->parsed.p_coord.start_angle == 'S')
		all->player.dir = 3 * M_PI / 2;
	else if (all->parsed.p_coord.start_angle == 'W')
		all->player.dir = M_PI;
	else
		return (1);
	return (0);
}
