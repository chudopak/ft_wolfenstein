/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 20:07:01 by chudapak          #+#    #+#             */
/*   Updated: 2021/03/04 22:18:52 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

static void			calculate_angle_btw_pl_and_spr(t_all *all, t_pl *ray, int i)
{
	all->sprite[i].vec_j = sqrt(all->sprite[i].i * all->sprite[i].i
			+ all->sprite[i].j * all->sprite[i].j)
			+ sqrt(ray->i * ray->i + ray->j * ray->j);
	all->sprite[i].ang_btw_pl_sp =
			fabs(acos(all->sprite[i].vec_i / all->sprite[i].vec_j));
	all->sprite[i].vec_i = all->sprite[i].i - ray->i;
	all->sprite[i].vec_j = all->sprite[i].j - ray->j;
	all->sprite[i].spr_agl =
			atan2(all->sprite[i].vec_i, all->sprite[i].vec_j);
	if (all->sprite[i].spr_agl < 0)
		all->sprite[i].spr_agl *= -1;
	else if (all->sprite[i].spr_agl >= 0)
		all->sprite[i].spr_agl = 2.0 * M_PI - all->sprite[i].spr_agl;
	all->sprite[i].ang_btw_pl_sp = (all->sprite[i].spr_agl - ray->dir) * -1;
	if (fabs(all->sprite[i].ang_btw_pl_sp) >
			2 * M_PI - (VIEV_ANGLE + 0.15) / 2.0)
	{
		if (all->sprite[i].ang_btw_pl_sp < 0)
			all->sprite[i].ang_btw_pl_sp =
				2 * M_PI - fabs(all->sprite[i].ang_btw_pl_sp);
		else if (all->sprite[i].ang_btw_pl_sp > 0)
			all->sprite[i].ang_btw_pl_sp =
				(2 * M_PI - fabs(all->sprite[i].ang_btw_pl_sp)) * -1;
	}
}

static t_spr		*get_dist_seen_spr(t_all *all, t_pl *ray)
{
	int		i;
	int		j;
	t_spr	*visible_spr;

	if (!(visible_spr = malloc(sizeof(t_spr) * all->parsed.amt_spr)))
		exit(0);//
	i = -1;
	j = 0;
	while (++i < all->parsed.amt_spr)
	{
		calculate_angle_btw_pl_and_spr(all, ray, i);
		if (fabs(all->sprite[i].ang_btw_pl_sp) < (VIEV_ANGLE + 0.15) / 2.0)
		{
			visible_spr[j].i = all->sprite[i].i;
			visible_spr[j].j = all->sprite[i].j;
			visible_spr[j].ang_btw_pl_sp = all->sprite[i].ang_btw_pl_sp;
			visible_spr[j].len_till_pl = sqrt(all->sprite[i].vec_i
					* all->sprite[i].vec_i + all->sprite[i].vec_j
					* all->sprite[i].vec_j);
			j++;
		}
	}
	all->counter = j;
	return (visible_spr);
}

static t_spr_limit	calculate_sprite_parametres(t_all *all,
					t_spr *visible_spr, int i)
{
	t_spr_limit	data;

	data.put_down = ((float)all->parsed.res.height
			- (float)all->parsed.res.height * 0.9) / visible_spr[i].len_till_pl;
	data.spr_ceiling = (float)all->parsed.res.height / 2.0
			- all->parsed.res.height / (visible_spr[i].len_till_pl * WALL_SCALE)
			+ data.put_down;
	data.spr_floor = (float)all->parsed.res.height
			- data.spr_ceiling + data.put_down;
	data.spr_non_scale_height = data.spr_floor - data.spr_ceiling;
	data.spr_height = data.spr_non_scale_height * FS_H_SCALE;
	data.mv_to_bottom = data.spr_height - data.spr_non_scale_height;
	data.aspect_ratio = (float)all->texture[TEXTURES - 1].tH
			/ (float)all->texture[TEXTURES - 1].tW;
	data.spr_width = (data.spr_non_scale_height / data.aspect_ratio)
			* FS_W_SCALE;
	data.mdl_spr = (0.5 * (visible_spr[i].ang_btw_pl_sp
			/ (VIEV_ANGLE / 2.0)) + 0.5) * (float)all->parsed.res.width;
	data.ratio_h = (float)all->texture[TEXTURES - 1].tH / data.spr_height;
	data.ratio_w = (float)all->texture[TEXTURES - 1].tW / data.spr_width;
	return (data);
}

static void			paint_sprite(t_all *all,
					t_spr *visible_spr, int i, float *rays)
{
	t_spr_limit	data;

	if (fabs(visible_spr[i].ang_btw_pl_sp) < (VIEV_ANGLE + 0.15) / 2.0)
	{
		data = calculate_sprite_parametres(all, visible_spr, i);
		set_start_img_colom(&data);
		while (data.colom_tex < data.spr_width
				&& data.img_colom < (int)all->parsed.res.width)
		{
			set_start_img_row(&data);
			if (rays[data.img_colom] >= visible_spr[i].len_till_pl)
				while (data.row_tex < data.spr_height
						&& data.img_row < (int)all->parsed.res.height)
				{
					if (check_for_empty_pixel(all, data))
						draw_sprite_colom(all, data);
					data.img_row++;
					data.row_tex++;
				}
			data.img_colom++;
			data.colom_tex++;
		}
	}
}

void				draw_sprite(t_all *all, t_pl *ray, float *rays)
{
	t_spr	*visible_spr;
	int		i;
	int		j;

	visible_spr = get_dist_seen_spr(all, ray);
	if (all->counter != 0)
	{
		i = -1;
		while (++i < all->counter - 1)
		{
			j = i;
			while (++j < all->counter)
				sprite_swap(&visible_spr[i], &visible_spr[j]);
		}
		i = -1;
		while (++i < all->counter)
			paint_sprite(all, visible_spr, i, rays);
	}
	if (visible_spr != NULL)
		free(visible_spr);
}
