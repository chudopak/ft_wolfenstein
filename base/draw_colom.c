/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_colom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 17:04:52 by chudapak          #+#    #+#             */
/*   Updated: 2021/03/09 21:52:54 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

static int	get_nb_texture(t_pl *ray)
{
	if (ray->ray_hit_wall == 'N')
		return (0);
	else if (ray->ray_hit_wall == 'S')
		return (1);
	else if (ray->ray_hit_wall == 'W')
		return (2);
	else if (ray->ray_hit_wall == 'E')
		return (3);
	return (-1);
}

static void	get_row_colom_tex(t_all *all, t_pl *ray)
{
	if (ray->wall_h > (int)all->parsed.res.height)
		ray->row_of_tex = (((float)(ray->wall_h - (int)all->parsed.res.height)
					/ ray->wall_h) / 2.0) * all->texture[ray->nb_tex].t_h;
	else
		ray->row_of_tex = 0;
	if (ray->nb_tex == 0 || ray->nb_tex == 1)
	{
		if (ray->start_agl > M_PI)
			ray->colom_of_tex = all->texture[ray->nb_tex].t_w
					- (int)fabs((ray->ray_cross_j
					- (int)ray->ray_cross_j) * all->texture[ray->nb_tex].t_w);
		else
			ray->colom_of_tex = (int)fabs((ray->ray_cross_j
					- (int)ray->ray_cross_j) * all->texture[ray->nb_tex].t_w);
	}
	else if (ray->nb_tex == 2 || ray->nb_tex == 3)
	{
		if (M_PI / 2 < ray->start_agl && ray->start_agl <= 3 * M_PI / 2)
			ray->colom_of_tex = all->texture[ray->nb_tex].t_w
					- (int)fabs((ray->ray_cross_i
					- (int)ray->ray_cross_i) * all->texture[ray->nb_tex].t_w);
		else
			ray->colom_of_tex = (int)fabs((ray->ray_cross_i
					- (int)ray->ray_cross_i) * all->texture[ray->nb_tex].t_w);
	}
}

void		draw_wall(t_all *all, t_pl *ray)
{
	ray->step = (float)all->texture[ray->nb_tex].t_h / ray->wall_h;
	get_row_colom_tex(all, ray);
	while (ray->string < ray->floor
			&& ray->string < (int)all->parsed.res.height)
	{
		pixel_put(&all->img, ray->string, ray->colom,
				*(unsigned int*)(all->texture[ray->nb_tex].ptr +
				((int)ray->row_of_tex * all->texture[ray->nb_tex].size_line
				+ ray->colom_of_tex * 4)));
		ray->row_of_tex += ray->step;
		ray->string++;
	}
}

void		fill_picture(t_all *all, t_pl *ray)
{
	ray->ceiling = ((float)(all->parsed.res.height / 2)
			- ((float)all->parsed.res.height * all->parsed.res.ratio)
			/ (ray->ray_len * WALL_SCALE));
	ray->floor = all->parsed.res.height - ray->ceiling;
	ray->wall_h = ray->floor - ray->ceiling;
	if ((ray->nb_tex = get_nb_texture(ray)) == -1)
		error_exit(all, 2, "error - can't find texture");
	ray->string = 0;
	draw_ceil(all, ray);
	draw_wall(all, ray);
	draw_floor(all, ray);
}
