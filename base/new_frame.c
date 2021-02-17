/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_frame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 16:47:12 by chudapak          #+#    #+#             */
/*   Updated: 2021/02/16 22:02:38 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

void	fix_fisheye(t_all *all, t_pl *ray)
{
	ray->fish_angle = all->player.dir - ray->start_agl;
	if (ray->fish_angle > 2 * M_PI)
		ray->fish_angle -= 2 * M_PI;
	else if (ray->fish_angle < 0)
		ray->fish_angle += 2 * M_PI;
	ray->ray_len *= cos(ray->fish_angle);
}

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

float	keep_angle_in_range(float angle)
{
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	else if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

double	count_len(t_raycast way, t_pl *ray)
{
	return (sqrt(pow(way.rayI - ray->i, 2) + pow(way.rayJ - ray->j, 2)));
}

void	set_hor_variebles(t_pl *ray, t_raycast *hor, int indicator)
{
	if (indicator == 1)
	{
		hor->rayI = (int)ray->i + 1;
		hor->rayJ = (ray->i - hor->rayI) * hor->tan + ray->j;
		hor->offsetI = 1;
		hor->offsetJ = -hor->offsetI * hor->tan;
	}
	else
	{
		hor->rayI = (int)ray->i - 0.001;
		hor->rayJ = (ray->i - hor->rayI) * hor->tan + ray->j;
		hor->offsetI = -1;
		hor->offsetJ = -hor->offsetI * hor->tan;
	}
}

double	get_hor_ray_len(t_all *all, t_pl *ray)
{
	t_raycast	hor;
	double		ray_len;

	if ((tan(ray->start_agl)))
		hor.tan = 1/tan(ray->start_agl);
	if (ray->start_agl == 2 * M_PI  || ray->start_agl == M_PI)
		return (0);
	else if (ray->start_agl > M_PI)//looking down
		set_hor_variebles(ray, &hor, 1);
	else if (ray->start_agl < M_PI)//looking up
		set_hor_variebles(ray, &hor, 0);
	while ((int)hor.rayI > 0 && (int)hor.rayI < all->parsed.p_coord.rows
			&& (int)hor.rayJ > 0 && (int)hor.rayJ < all->parsed.p_coord.coloms
			&& all->parsed.map[(int)hor.rayI][(int)hor.rayJ] != '1'
			&& all->parsed.map[(int)hor.rayI][(int)hor.rayJ] != '2'
			&& all->parsed.map[(int)hor.rayI][(int)hor.rayJ] != ' '
			&& all->parsed.map[(int)hor.rayI][(int)hor.rayJ] != '\0')
	{
		hor.rayI += hor.offsetI;
		hor.rayJ += hor.offsetJ;
	}
	return (ray_len = count_len(hor, ray));
}

void	set_ver_variebles(t_pl *ray, t_raycast *ver, int indicator)
{
	if (indicator == 1)
	{
		ver->rayJ = (int)ray->j + 1;
		ver->rayI = (ray->j - ver->rayJ) * ver->tan + ray->i;
		ver->offsetJ = 1;
		ver->offsetI = -ver->offsetJ * ver->tan;
	}
	else
	{
		ver->rayJ = (int)ray->j - 0.001;
		ver->rayI = (ray->j - ver->rayJ) * ver->tan + ray->i;
		ver->offsetJ = -1;
		ver->offsetI = -ver->offsetJ * ver->tan;
	}
}

double	get_ver_ray_len(t_all *all, t_pl *ray)
{
	t_raycast	ver;
	double		ray_len;

	if ((tan(ray->start_agl)))
		ver.tan = tan(ray->start_agl);
	if (ray->start_agl == 3 * M_PI / 2 || ray->start_agl == M_PI / 2)
		return (0);
	else if (ray->start_agl < M_PI / 2 || ray->start_agl > 3 * M_PI / 2)//looking right
		set_ver_variebles(ray, &ver, 1);
	else if (ray->start_agl > M_PI / 2 && ray->start_agl < 3 * M_PI / 2)//looking left
		set_ver_variebles(ray, &ver, 0);
	while ((int)ver.rayI > 0 && (int)ver.rayI < all->parsed.p_coord.rows
			&& (int)ver.rayJ > 0 && (int)ver.rayJ < all->parsed.p_coord.coloms
			&& all->parsed.map[(int)ver.rayI][(int)ver.rayJ] != '1'
			&& all->parsed.map[(int)ver.rayI][(int)ver.rayJ] != '2'
			&& all->parsed.map[(int)ver.rayI][(int)ver.rayJ] != ' '
			&& all->parsed.map[(int)ver.rayI][(int)ver.rayJ] != '\0')
	{
		ver.rayI += ver.offsetI;
		ver.rayJ += ver.offsetJ;
	}
	return (ray_len = count_len(ver, ray));
}

void	get_ray_len(t_all *all, t_pl *ray)
{
	ray->ray_len_hor = get_hor_ray_len(all, ray);
	ray->ray_len_ver = get_ver_ray_len(all, ray);
	if (ray->ray_len_hor < ray->ray_len_ver)
		ray->ray_len = ray->ray_len_hor;
	else
		ray->ray_len = ray->ray_len_ver;
	fix_fisheye(all, ray);
}

void	fill_picture(t_all *all, t_pl *ray)
{
	ray->ceiling = (int)((float)(all->parsed.res.height / 2) - all->parsed.res.height / (ray->ray_len * 3));
	ray->floor = all->parsed.res.height - ray->ceiling;
	ray->string = -1;
	while (++ray->string < (int)all->parsed.res.height)
	{
		if (ray->string < ray->ceiling)
			pixel_put(&all->img, ray->string, ray->colom, CEILING);
		else if (ray->string >= ray->ceiling && ray->string <= ray->floor)
			pixel_put(&all->img, ray->string, ray->colom, WALL);
		else
			pixel_put(&all->img, ray->string, ray->colom, FLOOR);
	}
}

int		draw_new_frame(t_all *all)
{
	t_pl	ray;

	if (all->player.mv_check == 1)
	{
		ray = get_ray_info(all);
		while (++ray.colom < (int)all->parsed.res.width)
		{
			ray.start_agl = (ray.dir + VIEV_ANGLE / 2) - ((float)ray.colom / (float)all->parsed.res.width) * VIEV_ANGLE;
			ray.start_agl = keep_angle_in_range(ray.start_agl);
			get_ray_len(all, &ray);
			fill_picture(all, &ray);
		}
		mlx_put_image_to_window(all->vars.mlx, all->vars.win, all->img.img, 0, 0);
		all->player.mv_check = 0;
	}
	return (0);
}