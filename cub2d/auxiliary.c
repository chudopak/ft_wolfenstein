/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:02:09 by pmarash           #+#    #+#             */
/*   Updated: 2021/02/05 18:52:08 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"
#include "cub2d.h"

void	increment(t_all *all)
{
	if (all->player.aux == 'i')
		all->player.i += all->player.size;
	else
		all->player.j += all->player.size;
}

void	decrement(t_all *all)
{
	if (all->player.aux == 'i')
		all->player.i -= all->player.size;
	else
		all->player.j -= all->player.size;
}

int		draw_empty(t_all *all)
{
	increase_part_wall(&all->img, (int)all->player.i, (int)all->player.j, EMPT, SCALE);
	return (0);
}

int		draw_player(t_all *all)
{
	increase_part_wall(&all->img, (int)all->player.i, (int)all->player.j, PL, SCALE);
	return (0);
}

void	draw_ray(t_all *all, t_pl ray, unsigned int color)
{
	float	i_tmp;

	i_tmp = ray.i * SCALE + SCALE;
	while (i_tmp-- > ray.i * SCALE)
		pixel_put(&all->img, i_tmp, ray.j * SCALE + 10, color);
}

int		check_wall(t_all *all)
{
	if (all->parsed.map[(int)(all->player.i / SCALE)][(int)(all->player.j / SCALE)] == '1'
			|| all->parsed.map[(int)(all->player.i / SCALE)][(int)(all->player.j / SCALE)] == '2'
			|| all->parsed.map[(int)((all->player.i + SCALE - MOVE / 2) / SCALE)][(int)((all->player.j + SCALE - MOVE / 2) / SCALE)] == '1'
			|| all->parsed.map[(int)((all->player.i + SCALE - MOVE / 2) / SCALE)][(int)((all->player.j + SCALE - MOVE / 2) / SCALE)] == '2'
			|| all->parsed.map[(int)((all->player.i + SCALE - MOVE / 2) / SCALE)][(int)((all->player.j) / SCALE)] == '1'
			|| all->parsed.map[(int)((all->player.i + SCALE - MOVE / 2) / SCALE)][(int)((all->player.j) / SCALE)] == '2'
			|| all->parsed.map[(int)((all->player.i) / SCALE)][(int)((all->player.j + SCALE - MOVE / 2) / SCALE)] == '1'
			|| all->parsed.map[(int)((all->player.i) / SCALE)][(int)((all->player.j + SCALE - MOVE / 2) / SCALE)] == '2')
		return (1);
	return (0);
}

void	ft_clean_rays(t_all *all)
{
	t_pl	ray;

	ray			= all->player;
	ray.old_i	+= SCALE / 2 + 1;
	ray.old_j	+= SCALE / 2 + 1;
	ray.start	= ray.old_dir - VIEV_ANGLE;
	ray.end		= ray.old_dir + VIEV_ANGLE;
	while (ray.start <= ray.end)
	{
		ray.old_i = all->player.old_i + SCALE / 2 + 1;
		ray.old_j = all->player.old_j + SCALE / 2 + 1;
		while (all->parsed.map[(int)ray.old_i / SCALE][(int)ray.old_j / SCALE] != '1'
				&& all->parsed.map[(int)ray.old_i / SCALE][(int)ray.old_j / SCALE] != '2'
				&& all->parsed.map[(int)ray.old_i / SCALE][(int)ray.old_j / SCALE] != ' '
				&& all->parsed.map[(int)ray.old_i / SCALE][(int)ray.old_j / SCALE] != '\0')
		{
			ray.old_i += cos(ray.start);
			ray.old_j += sin(ray.start);
			pixel_put(&all->img, ray.old_i, ray.old_j, EMPT);
		}
		ray.start += M_PI_2 / 100;
	}
}
