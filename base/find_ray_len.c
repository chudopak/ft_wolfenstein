/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ray_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 17:16:45 by chudapak          #+#    #+#             */
/*   Updated: 2021/03/08 20:58:29 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

int		check_cell(t_all *all, t_raycast cell)
{
	if ((int)cell.ray_i > 0 && (int)cell.ray_i < all->parsed.p_coord.rows
			&& (int)cell.ray_j > 0
			&& (int)cell.ray_j < all->parsed.p_coord.coloms
			&& all->parsed.map[(int)cell.ray_i][(int)cell.ray_j] != '1'
			&& all->parsed.map[(int)cell.ray_i][(int)cell.ray_j] != ' '
			&& all->parsed.map[(int)cell.ray_i][(int)cell.ray_j] != '\0')
		return (0);
	return (1);
}

void	set_hor_variebles(t_pl *ray, t_raycast *hor, int indicator)
{
	if (indicator == 1)
	{
		hor->ray_i = (int)ray->i + 1;
		hor->ray_j = (ray->i - hor->ray_i) * hor->tan + ray->j;
		hor->offset_i = 1;
		hor->offset_j = -hor->offset_i * hor->tan;
	}
	else
	{
		hor->ray_i = (int)ray->i - 0.00000001;
		hor->ray_j = (ray->i - hor->ray_i) * hor->tan + ray->j;
		hor->offset_i = -1;
		hor->offset_j = -hor->offset_i * hor->tan;
	}
}

double	get_hor_ray_len(t_all *all, t_pl *ray)
{
	t_raycast	hor;
	double		ray_len;

	if ((tan(ray->start_agl)))
		hor.tan = 1 / tan(ray->start_agl);
	if (ray->start_agl == 2 * M_PI || ray->start_agl == M_PI)
		return (0);
	else if (ray->start_agl > M_PI)
		set_hor_variebles(ray, &hor, 1);
	else if (ray->start_agl < M_PI)
		set_hor_variebles(ray, &hor, 0);
	while (!check_cell(all, hor))
	{
		hor.ray_i += hor.offset_i;
		hor.ray_j += hor.offset_j;
	}
	ray->ray_cross_j = hor.ray_j;
	return (ray_len = count_len(hor, ray));
}

void	set_ver_variebles(t_pl *ray, t_raycast *ver, int indicator)
{
	if (indicator == 1)
	{
		ver->ray_j = (int)ray->j + 1;
		ver->ray_i = (ray->j - ver->ray_j) * ver->tan + ray->i;
		ver->offset_j = 1;
		ver->offset_i = -ver->offset_j * ver->tan;
	}
	else
	{
		ver->ray_j = (int)ray->j - 0.00000001;
		ver->ray_i = (ray->j - ver->ray_j) * ver->tan + ray->i;
		ver->offset_j = -1;
		ver->offset_i = -ver->offset_j * ver->tan;
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
	else if (ray->start_agl < M_PI / 2
			|| ray->start_agl > 3 * M_PI / 2)
		set_ver_variebles(ray, &ver, 1);
	else if (ray->start_agl > M_PI / 2
			&& ray->start_agl < 3 * M_PI / 2)
		set_ver_variebles(ray, &ver, 0);
	while (!check_cell(all, ver))
	{
		ver.ray_i += ver.offset_i;
		ver.ray_j += ver.offset_j;
	}
	ray->ray_cross_i = ver.ray_i;
	return (ray_len = count_len(ver, ray));
}
