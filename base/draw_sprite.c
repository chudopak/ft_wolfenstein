/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 20:07:01 by chudapak          #+#    #+#             */
/*   Updated: 2021/03/03 21:17:55 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"
#include <stdio.h>

static void		calculate_angle_btw_pl_and_spr(t_all *all, t_pl *ray, int i)
{
	all->sprite[i].vec_j = sqrt(all->sprite[i].i * all->sprite[i].i + all->sprite[i].j * all->sprite[i].j)
							+ sqrt(ray->i * ray->i + ray->j * ray->j);
	all->sprite[i].ang_btw_pl_sp = fabs(acos(all->sprite[i].vec_i / all->sprite[i].vec_j));
	all->sprite[i].vec_i = all->sprite[i].i - ray->i;
	all->sprite[i].vec_j = all->sprite[i].j - ray->j;
	all->sprite[i].sprite_angle = atan2(all->sprite[i].vec_i, all->sprite[i].vec_j);
	if (all->sprite[i].sprite_angle < 0)
		all->sprite[i].sprite_angle *= -1;
	else if (all->sprite[i].sprite_angle >= 0)
		all->sprite[i].sprite_angle = 2.0 * M_PI - all->sprite[i].sprite_angle;
	all->sprite[i].ang_btw_pl_sp = (all->sprite[i].sprite_angle - ray->dir) * -1;
	if (fabs(all->sprite[i].ang_btw_pl_sp) > 2 * M_PI - (VIEV_ANGLE + 0.1) / 2.0)
	{
		if (all->sprite[i].ang_btw_pl_sp < 0)
			all->sprite[i].ang_btw_pl_sp = 2 * M_PI - fabs(all->sprite[i].ang_btw_pl_sp);
		else if (all->sprite[i].ang_btw_pl_sp > 0)
			all->sprite[i].ang_btw_pl_sp = (2 * M_PI - fabs(all->sprite[i].ang_btw_pl_sp)) * -1;
	}
}

static t_spr	*get_dist_seen_spr(t_all *all, t_pl *ray)
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
		if (fabs(all->sprite[i].ang_btw_pl_sp) < (VIEV_ANGLE + 0.1) / 2.0)
		{
			visible_spr[j].ang_btw_pl_sp = all->sprite[i].ang_btw_pl_sp;
			visible_spr[j].len_till_pl = sqrt(all->sprite[i].vec_i * all->sprite[i].vec_i
												+ all->sprite[i].vec_j * all->sprite[i].vec_j);
			j++;
		}
	}
	all->counter = j;
	return (visible_spr);
}

/*static void	sort_far_to_near(t_spr **visible_spr, int see_spr)
{
	t_spr	tmp;
	int		i;
	int		j;

	i = -1;
	while (++i < see_spr - 1)
	{
		j = i;
		while (++j < see_spr)
			if (visible_spr[i]->len_till_pl > visible_spr[j]->len_till_pl)
			{
				tmp = *visible_spr[i];
				visible_spr[i] = visible_spr[j];
				*visible_spr[j] = tmp;
			}
	}
}*/

static t_spr_limit	calculate_sprite_parametres(t_all *all, t_spr *visible_spr, int i)
{
	t_spr_limit	data;

	data.spr_ceiling = (float)all->parsed.res.height / 2.0
						- all->parsed.res.height / (visible_spr[i].len_till_pl * WALL_SCALE);
	if (data.spr_ceiling < ((float)all->parsed.res.height / 2.0) * 0.2)
		data.spr_ceiling = ((float)all->parsed.res.height / 2.0) * 0.2;
	data.spr_floor = (float)all->parsed.res.height - data.spr_ceiling;
	data.spr_height = data.spr_floor - data.spr_ceiling;
	data.aspect_ratio = (float)all->texture[TEXTURES - 1].tH / (float)all->texture[TEXTURES - 1].tW;
	data.spr_width = data.spr_height / data.aspect_ratio;
	data.mdl_spr = (0.5 * (visible_spr[i].ang_btw_pl_sp / (VIEV_ANGLE / 2.0)) + 0.5) * (float)all->parsed.res.width;
	data.colom_tex = -1;
	data.ratio_h = (float)all->texture[TEXTURES - 1].tH / data.spr_height;
	data.ratio_w = (float)all->texture[TEXTURES - 1].tW / data.spr_width;
	return (data);
}

static int	check_for_empty_pixel(t_all *all, t_spr_limit data)
{
	if ((*(unsigned int*)(all->texture[TEXTURES - 1].ptr + (int)(data.row_tex * data.ratio_h)
			* all->texture[TEXTURES - 1].size_line + (int)(data.colom_tex * data.ratio_w)
			* (all->texture[TEXTURES - 1].bpp / 8))) != 0x00000000)
		return (1);
	return (0);
}

static void	paint_sprite(t_all *all, t_spr *visible_spr, int i)
{
	t_spr_limit	data;

	//printf("agl - %f, len - %f\n", visible_spr[i]->ang_btw_pl_sp, visible_spr[i]->len_till_pl);
	if (fabs(visible_spr[i].ang_btw_pl_sp) < (VIEV_ANGLE + 0.1) / 2.0)
	{
		data = calculate_sprite_parametres(all, visible_spr, i);
		while (++data.colom_tex < data.spr_width)
		{
			data.row_tex = -1;
			data.img_colom = (int)(data.mdl_spr + data.colom_tex - (data.spr_width / 2.0));
			if (data.img_colom >= 0 && data.img_colom < (int)all->parsed.res.width)
				while (++data.row_tex < data.spr_height)
					if (check_for_empty_pixel(all, data))
					{
						data.img_row = (int)data.spr_ceiling + data.row_tex;
						data.sprite_row = (int)(data.row_tex * data.ratio_h) * all->texture[TEXTURES - 1].size_line;
						data.sprite_colom = (int)(data.colom_tex * data.ratio_w) * (all->texture[TEXTURES - 1].bpp / 8);
						pixel_put(&all->img, data.img_row, data.img_colom, *(unsigned int*)(all->texture[TEXTURES - 1].ptr
								+ data.sprite_row + data.sprite_colom));
					}
		}
	}
}

void	draw_sprite(t_all *all, t_pl *ray)
{
	t_spr	*visible_spr;
	int		i;

	visible_spr = get_dist_seen_spr(all, ray);
	if (all->counter != 0)
	{
		//sort_far_to_near(&visible_spr, all->counter);
		i = -1;
		while (++i < all->counter)
			paint_sprite(all, visible_spr, i);
	}
	if (visible_spr != NULL)
		free(visible_spr);
}