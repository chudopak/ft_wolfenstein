/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 20:07:01 by chudapak          #+#    #+#             */
/*   Updated: 2021/03/01 21:50:16 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

static int	get_dist_seen_spr(t_all *all, t_pl *ray, t_spr **visible_spr)
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
		all->sprite[i].sprite_angle = atan2(eye_i, eye_j) - atan2(vec_i, vec_j);
		if (all->sprite[i].sprite_angle < -M_PI)
			all->sprite[i].sprite_angle += 2.0 * M_PI;
		if (all->sprite[i].sprite_angle > M_PI)
			all->sprite[i].sprite_angle -= 2.0 * M_PI;
		if (all->sprite[i].sprite_angle < VIEV_ANGLE / 2.0)
		{
			visible_spr[j]->sprite_angle = all->sprite[i].sprite_angle;
			visible_spr[j]->len_till_pl = sqrt(all->sprite[i].vec_i * all->sprite[i].vec_i
												+ all->sprite[i].vec_j * all->sprite[i].vec_j);
			j++;
		}
	}
	return (j);
}

static void	sort_far_to_near(t_spr **visible_spr)
{
	t_spr	tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (++i < all->parsed.amt_spr)
	{
		if (visible_spr[i]->len_till_pl > visible_spr[j]->len_till_pl)
		{
			tmp = visible_spr[i];
			visible_spr[i] = visible_spr[j];
			visible_spr[j] = tmp;
		}
		
	}

}

void	draw_sprite(t_all *all, t_pl *ray)
{
	t_spr	*visible_spr;
	int		see_spr;

	if (!(visible_spr = malloc(sizeof(t_spr) * all->parsed.amt_spr)))
		exit(0);
	if (!(see_spr = get_dist_seen_spr(all, ray, &visible_spr))
		return ;
	sort_far_to_near(&visible_spr);
	
}