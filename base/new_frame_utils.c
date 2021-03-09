/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_frame_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 17:15:25 by chudapak          #+#    #+#             */
/*   Updated: 2021/03/09 21:40:05 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

float	keep_angle_in_range(float angle)
{
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	else if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

t_pl	get_ray_info(t_all *all)
{
	all->player.start_agl = all->player.dir - VIEV_ANGLE / 2;
	all->player.colom = -1;
	if (all->player.dir > 2 * M_PI)
		all->player.dir -= 2 * M_PI;
	else if (all->player.dir < 0)
		all->player.dir += 2 * M_PI;
	return (all->player);
}

void	fix_fisheye(t_all *all, t_pl *ray)
{
	ray->fish_angle = ((double)ray->colom
			/ (double)all->parsed.res.width) * VIEV_ANGLE - VIEV_ANGLE / 2;
	if (ray->fish_angle > 2 * M_PI)
		ray->fish_angle -= 2 * M_PI;
	else if (ray->fish_angle < 0)
		ray->fish_angle += 2 * M_PI;
	ray->ray_len *= cos(ray->fish_angle);
}

void	side_wall(t_pl *ray)
{
	if (ray->ray_cross == 'H' && 0 < ray->start_agl && ray->start_agl <= M_PI)
		ray->ray_hit_wall = 'N';
	else if (ray->ray_cross == 'H' && M_PI < ray->start_agl
			&& ray->start_agl <= 2 * M_PI)
		ray->ray_hit_wall = 'S';
	else if (ray->ray_cross == 'V'
			&& ((ray->start_agl <= M_PI / 2 && ray->start_agl > 0)
			|| (ray->start_agl > 3 * M_PI / 2 && ray->start_agl <= 2 * M_PI)))
		ray->ray_hit_wall = 'E';
	else if (ray->ray_cross == 'V' && ray->start_agl > M_PI / 2
			&& ray->start_agl <= 3 * M_PI / 2)
		ray->ray_hit_wall = 'W';
}
