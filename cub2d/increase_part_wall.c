/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increase_part_wall.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 17:38:18 by pmarash           #+#    #+#             */
/*   Updated: 2021/01/26 18:27:46 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"
#include "cub2d.h"

void	increase_part_wall(t_data *img, float width, float height, unsigned int color, int size)
{
	float	width_tmp;
	float	height_tmp;

	width_tmp = width;
	while (width_tmp++ < width + (float)size)
	{
		height_tmp = height;
		while (height_tmp++ < height + (float)size)
			pixel_put(img, width_tmp, height_tmp, color);
	}
}
