/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 21:05:05 by chudapak          #+#    #+#             */
/*   Updated: 2021/03/05 20:16:30 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

void	draw_ceil(t_all *all, t_pl *ray)
{
	while (ray->string < ray->ceiling)
	{
		pixel_put(&all->img, ray->string, ray->colom, all->color.clg);
		ray->string++;
	}
}
