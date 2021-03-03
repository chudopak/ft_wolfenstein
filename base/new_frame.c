/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_frame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:47:12 by chudapak          #+#    #+#             */
/*   Updated: 2021/03/03 20:41:19 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

void	get_ray_len(t_all *all, t_pl *ray)
{
	all->counter = 0;
	ray->ray_len_hor = get_hor_ray_len(all, ray);
	ray->ray_len_ver = get_ver_ray_len(all, ray);
	if (ray->ray_len_hor < ray->ray_len_ver)
	{
		ray->ray_len = ray->ray_len_hor;
		ray->rayCross = 'H';
	}
	else
	{
		ray->ray_len = ray->ray_len_ver;
		ray->rayCross = 'V';
	}
}

int		draw_new_frame(t_all *all)
{
	t_pl		ray;

	move_player(all);
	ray = get_ray_info(all);
	while (++ray.colom < (int)all->parsed.res.width)
	{
		ray.start_agl = (ray.dir + VIEV_ANGLE / 2) - ((float)ray.colom / (float)all->parsed.res.width) * VIEV_ANGLE;
		ray.start_agl = keep_angle_in_range(ray.start_agl);
		get_ray_len(all, &ray);
		fix_fisheye(all, &ray);
		side_wall(&ray);
		fill_picture(all, &ray);
	}
	if (all->parsed.amt_spr != 0)
		draw_sprite(all, &ray);
	mlx_do_sync(all->vars.mlx);
	mlx_put_image_to_window(all->vars.mlx, all->vars.win, all->img.img, 0, 0);
	return (0);
}