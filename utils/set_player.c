/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:07:44 by chudapak          #+#    #+#             */
/*   Updated: 2021/02/12 20:45:20 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

int		set_player(t_all *all)
{
	all->player.i = (float)all->parsed.p_coord.i;
	all->player.j = (float)all->parsed.p_coord.j;
	if (all->parsed.p_coord.start_angle == 'N')
		all->player.dir = M_PI / 2;
	else if (all->parsed.p_coord.start_angle == 'E')
		all->player.dir = M_PI;
	else if (all->parsed.p_coord.start_angle == 'S')
		all->player.dir = 3 * M_PI / 2;
	else if (all->parsed.p_coord.start_angle == 'W')
		all->player.dir = M_PI * 2;
	else
		return (1);
	return (0);
}