/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ray_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 17:16:45 by chudapak          #+#    #+#             */
/*   Updated: 2021/02/28 17:23:37 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

int		check_cell(t_all *all, t_raycast cell)
{
	if ((int)cell.rayI > 0 && (int)cell.rayI < all->parsed.p_coord.rows
			&& (int)cell.rayJ > 0 && (int)cell.rayJ < all->parsed.p_coord.coloms
			&& all->parsed.map[(int)cell.rayI][(int)cell.rayJ] != '1'
			&& all->parsed.map[(int)cell.rayI][(int)cell.rayJ] != ' '
			&& all->parsed.map[(int)cell.rayI][(int)cell.rayJ] != '\0')
		return (0);
	return (1);
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
		hor->rayI = (int)ray->i - 0.00000001;
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
	while (!check_cell(all, hor))
	{
		hor.rayI += hor.offsetI;
		hor.rayJ += hor.offsetJ;
	}
	ray->ray_cross_j = hor.rayJ;
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
		ver->rayJ = (int)ray->j - 0.00000001;
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
	while (!check_cell(all, ver))
	{
		ver.rayI += ver.offsetI;
		ver.rayJ += ver.offsetJ;
	}
	ray->ray_cross_i = ver.rayI;
	return (ray_len = count_len(ver, ray));
}
