/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 21:05:05 by chudapak          #+#    #+#             */
/*   Updated: 2021/02/24 21:05:27 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

void		draw_ceil(t_all *all, t_pl *ray)
{
	while (ray->string < ray->ceiling)
	{
		pixel_put(&all->img, ray->string, ray->colom, all->color.clg);
		ray->string++;
	}
}
