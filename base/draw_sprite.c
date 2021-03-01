/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 20:07:01 by chudapak          #+#    #+#             */
/*   Updated: 2021/03/01 20:50:47 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

static void	get_dist_seen_spr(t_all *all, t_pl *ray, t_spr **visible_spr)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (++i < all->parsed.amt_spr)
	{
		all->sprite[i].vec_i = all->sprite[i].i - ray->i;
		all->sprite[i].vec_j = all->sprite[i].j - ray->j;
		all->sprite[i].eye_i = cos(ray->dir);
		all->sprite[i].eye_j = sin(ray->dir);
		all->sprite[i].sprite_angle = atan2(eye_j, eye_i) - atan2(vec_j, vec_i);
	}
}

void	draw_sprite(t_all *all, t_pl *ray)
{
	t_spr	*visible_spr;

	if (!(visible_spr = malloc(sizeof(t_spr) * all->parsed.amt_spr)))
		exit(0);
	get_dist_seen_spr(all, ray);
	
}