/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:29:38 by pmarash           #+#    #+#             */
/*   Updated: 2021/01/25 16:09:33 by pmarash          ###   ########.fr       */
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
