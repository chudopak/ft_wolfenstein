/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 19:02:09 by pmarash           #+#    #+#             */
/*   Updated: 2021/01/27 18:09:15 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"
#include "cub2d.h"

void	increment(t_all *all)
{
	if (all->player.aux == 'i')
		all->player.i += all->player.size;
	else
		all->player.j += all->player.size;
}

void	decrement(t_all *all)
{
	if (all->player.aux == 'i')
		all->player.i -= all->player.size;
	else
		all->player.j -= all->player.size;
}

int		draw_empty(t_all *all)
{
	increase_part_wall(&all->img, (int)all->player.i * SCALE, (int)all->player.j * SCALE, 0x11FFBBFF, SCALE);
	return (0);
}

int		draw_player(t_all *all)
{
	increase_part_wall(&all->img, (int)all->player.i * SCALE, (int)all->player.j * SCALE, 0x00FF00FF, SCALE);
	return (0);
}
