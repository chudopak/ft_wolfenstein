/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 17:03:06 by chudapak          #+#    #+#             */
/*   Updated: 2021/03/08 22:05:42 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

t_sprite	*get_sprites_info(t_all *all)
{
	int			i;
	int			j;
	t_sprite	*sprite;

	all->counter = 0;
	if (!(sprite = (t_sprite*)malloc(sizeof(t_sprite) * (all->parsed.amt_spr))))
		exit(0);
	i = -1;
	while (++i < all->parsed.p_coord.rows && all->counter < all->parsed.amt_spr)
	{
		j = 0;
		while (all->parsed.map[i][j] != '\0'
				&& all->counter < all->parsed.amt_spr)
		{
			if (all->parsed.map[i][j] == '3')
			{
				sprite[all->counter].i = (float)i + 0.5;
				sprite[all->counter].j = (float)j + 0.5;
				all->parsed.map[i][j] = '2';
				all->counter++;
			}
			j++;
		}
	}
	return (sprite);
}
