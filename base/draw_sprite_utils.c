/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:14:36 by pmarash           #+#    #+#             */
/*   Updated: 2021/03/04 22:19:05 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

void	set_start_img_colom(t_spr_limit *data)
{
	data->colom_tex = 0;
	data->img_colom = (int)(data->mdl_spr + data->colom_tex
			- (data->spr_width / 2.0));
	if (data->img_colom < 0)
	{
		data->colom_tex -= data->img_colom;
		data->img_colom = 0;
	}
}

int		check_for_empty_pixel(t_all *all, t_spr_limit data)
{
	if ((*(unsigned int*)(all->texture[TEXTURES - 1].ptr
			+ (int)(data.row_tex * data.ratio_h)
			* all->texture[TEXTURES - 1].size_line
			+ (int)(data.colom_tex * data.ratio_w)
			* (all->texture[TEXTURES - 1].bpp / 8))) != 0x00000000)
		return (1);
	return (0);
}

void	sprite_swap(t_spr *seen_spr, t_spr *seen_spr1)
{
	t_spr	tmp;

	if (seen_spr->len_till_pl < seen_spr1->len_till_pl)
	{
		tmp = *seen_spr;
		*seen_spr = *seen_spr1;
		*seen_spr1 = tmp;
	}
}

void	draw_sprite_colom(t_all *all, t_spr_limit data)
{
	data.sprite_row = (int)(data.row_tex * data.ratio_h)
			* all->texture[TEXTURES - 1].size_line;
	data.sprite_colom = (int)(data.colom_tex * data.ratio_w)
			* (all->texture[TEXTURES - 1].bpp / 8);
	pixel_put(&all->img, data.img_row, data.img_colom,
			*(unsigned int*)(all->texture[TEXTURES - 1].ptr
			+ data.sprite_row + data.sprite_colom));
}

void	set_start_img_row(t_spr_limit *data)
{
	if (data->spr_floor - data->spr_height < 0)
	{
		data->row_tex = (data->spr_floor - data->spr_height) * -1;
		data->img_row = 0;
	}
	else
	{
		data->row_tex = 0;
		data->img_row = (int)data->spr_ceiling - data->mv_to_bottom;
	}
}