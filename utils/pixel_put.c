/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:29:38 by pmarash           #+#    #+#             */
/*   Updated: 2021/02/19 17:37:05 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

void	pixel_put(t_data *data, int width, int height, unsigned int color)
{
	char	*dst;

	dst = data->addr + (width * data->line_length
			+ height * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

double	count_len(t_raycast way, t_pl *ray)
{
	return (sqrt(pow(way.rayI - ray->i, 2) + pow(way.rayJ - ray->j, 2)));
}
