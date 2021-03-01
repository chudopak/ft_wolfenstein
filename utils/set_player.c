/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:07:44 by chudapak          #+#    #+#             */
/*   Updated: 2021/02/28 17:26:13 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

static void	step_off_wall(t_all *all)
{
	if (all->parsed.map[(int)(all->player.i - 0.5)][(int)all->player.j] == '1'
			|| all->parsed.map[(int)(all->player.i - 0.5)][(int)all->player.j] == '3')
		all->player.i += STOP_BF_WALL;
	else if (all->parsed.map[(int)(all->player.i + 0.5)][(int)all->player.j] == '1'
			|| all->parsed.map[(int)(all->player.i + 0.5)][(int)all->player.j] == '3')
		all->player.i -= STOP_BF_WALL;
	if (all->parsed.map[(int)all->player.i][(int)(all->player.j - 0.5)] == '1'
			|| all->parsed.map[(int)all->player.i][(int)(all->player.j - 0.5)] == '3')
		all->player.j += STOP_BF_WALL;
	else if (all->parsed.map[(int)all->player.i][(int)(all->player.j + 0.5)] == '1'
			|| all->parsed.map[(int)all->player.i][(int)(all->player.j + 0.5)] == '3')
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

/*static void	sprite_fill(t_all *all, int i, int j, t_sprite **sprite)
{
	if (all->counter == all->parsed.amt_sprites)
		return ;
	if (all->parsed.map[i][j] == '2')
	{
		sprite[all->counter]->i = (float)i + 0.5;
		sprite[all->counter]->j = (float)j + 0.5;
		all->counter++;
		return;
	}
	if (all->parsed.map[i][j] == '1' || all->parsed.map[i][j] == '0')
		return ;
	if (all->parsed.map[i][j] == '.')
		all->parsed.map[i][j] = '0';
	sprite_fill(all, i - 1, j, sprite);
	sprite_fill(all, i, j - 1, sprite);
	sprite_fill(all, i, j + 1, sprite);
	sprite_fill(all, i + 1, j, sprite);
}*/

int		set_player(t_all *all)
{
	//t_sprite	*sprite;
//
	//all->counter = 0;
	//sprite = malloc(sizeof(t_sprite) * all->parsed.amt_sprites);
	fill_keys(all);
	all->player.i = (float)all->parsed.p_coord.i;
	all->player.j = (float)all->parsed.p_coord.j;
	//sprite_fill(all, (int)all->player.i, (int)all->player.j, &sprite);
	all->parsed.map[(int)(all->player.i)][(int)all->player.j] = '0';//'.'
	step_off_wall(all);
	if (all->parsed.p_coord.start_angle == 'N')
		all->player.dir = M_PI / 2;
	else if (all->parsed.p_coord.start_angle == 'E')
		all->player.dir = M_PI;
	else if (all->parsed.p_coord.start_angle == 'S')
		all->player.dir = 3 * M_PI / 2;
	else if (all->parsed.p_coord.start_angle == 'W')
		all->player.dir = M_PI * 2;
	else
		return (1);
	return (0);
}