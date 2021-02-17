/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_frame_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 15:59:18 by chudapak          #+#    #+#             */
/*   Updated: 2021/02/11 18:59:50 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

t_pl	get_ray_info(t_all *all)
{
	//all->player.start_agl = all->player.dir - VIEV_ANGLE / 2;
	all->player.colom = -1;
	if (all->player.dir > 2 * M_PI)
		all->player.dir -= 2 * M_PI;
	else if (all->player.dir < 0)
		all->player.dir += 2 * M_PI;
	return (all->player);
}

void	way_pl_looking(t_pl *ray)
{
	ray->cos_i = cos(ray->start_agl);
	ray->sin_j = sin(ray->start_agl);
	ray->step_len = 0;
	if (ray->cos_i < 0)
		ray->step_i = 1;
	else
		ray->step_i = 0;
	if (ray->sin_j < 0)
		ray->step_j = 1;
	else
		ray->step_j = 0;
}

void	get_final_coordinate(t_all *all, t_pl *ray)
{
	double	len_i;
	double	len_j;
	double	one_i;
	double	one_j;
	double	ratio;

	len_i = ray->cos_i * ray->step_len - ray->cos_i * (ray->step_len - STEP_TO_WALL);
	len_j = ray->sin_j * ray->step_len - ray->sin_j * (ray->step_len - STEP_TO_WALL);
	if ((int)ray->i != (int)(ray->i - len_i))
	{
		ratio = fabs(((int)ray->i - all->player.i + ray->step_i) / ray->i - all->player.i - len_i);
		ray->j /= ratio;
		ray->i = (int)ray->i + ray->step_i;
	}
	else if ((int)ray->j != (int)(ray->j - len_j))
	{
		ray->i /= fabs(((int)ray->j - all->player.j + ray->step_j) / ray->j - all->player.j - len_j);
		ray->j = (int)ray->j + ray->step_j;
	}
	else
	{
		ratio = fabs(((int)ray->i - all->player.i + ray->step_i) / ray->i - all->player.i - len_i);
		one_j = ray->j / ratio;
		ratio = fabs(((int)ray->j - all->player.j + ray->step_j) / ray->j - all->player.j - len_j);
		one_i = ray->i / ratio;
		if (one_i < one_j)
		{
			ray->j /= fabs(((int)ray->i - all->player.i + ray->step_i) / ray->i - all->player.i - len_i);
			ray->i = (int)ray->i + ray->step_i;
		}
		else
		{
			ray->i /= fabs(((int)ray->j - all->player.j + ray->step_j) / ray->j - all->player.j - len_j);
			ray->j = (int)ray->j + ray->step_j;
		}
	}
}

void 	get_ray_len(t_all *all, t_pl *ray)
{
	way_pl_looking(ray);
	while (all->parsed.map[(int)ray->i][(int)ray->j] != '1'
				&& all->parsed.map[(int)ray->i][(int)ray->j] != '2'
				&& all->parsed.map[(int)ray->i][(int)ray->j] != ' '
				&& all->parsed.map[(int)ray->i][(int)ray->j] != '\0')
	{
		ray->step_len += STEP_TO_WALL;
		ray->i += all->player.i + ray->cos_i * ray->step_len;
		ray->j += all->player.j + ray->sin_j * ray->step_len;
	}
	get_final_coordinate(all, ray);
	ray->ray_len = sqrt(pow(ray->i - all->player.i, 2) + pow(ray->j - all->player.j, 2));
}

int		draw_new_frame(t_all *all)
{
	t_pl	ray;
 
	ray = get_ray_info(all);
	while (++ray.colom < (int)all->parsed.res.width)
	{
		ray.dir = 0;
		ray.start_agl = (ray.dir - VIEV_ANGLE / 2) + ((float)ray.colom / (float)all->parsed.res.width) * VIEV_ANGLE;
		get_ray_len(all, &ray);
		ray.ceiling = (float)(all->parsed.res.height / 2) - all->parsed.res.height / (ray.ray_len);
		ray.floor = all->parsed.res.height - ray.ceiling;
		ray.string = -1;
		while (++ray.string < (int)all->parsed.res.height)
		{
			if (ray.string < ray.ceiling)
				pixel_put(&all->img, ray.string, ray.colom, CEILING);
			else if (ray.string >= ray.ceiling && ray.string <= ray.floor)
				pixel_put(&all->img, ray.string, ray.colom, WALL);
			else
				pixel_put(&all->img, ray.string, ray.colom, FLOOR);
		}
	}
	mlx_put_image_to_window(all->vars.mlx, all->vars.win, all->img.img, 0, 0);
	return (0);
}