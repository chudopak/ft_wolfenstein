/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 21:03:37 by chudapak          #+#    #+#             */
/*   Updated: 2021/02/24 21:03:56 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

void		draw_floor(t_all *all, t_pl *ray)
{
	while (ray->string < (int)all->parsed.res.height)
	{
		pixel_put(&all->img, ray->string, ray->colom, all->color.flr);
		ray->string++;
	}
}
