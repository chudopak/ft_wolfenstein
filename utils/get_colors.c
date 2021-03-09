/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:51:58 by chudapak          #+#    #+#             */
/*   Updated: 2021/03/07 22:36:56 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

void	get_colors(t_all *all)
{
	all->color.flr = create_trgb(0, all->parsed.flor.r,
			all->parsed.flor.g, all->parsed.flor.b);
	all->color.clg = create_trgb(0, all->parsed.ceil.r,
			all->parsed.ceil.g, all->parsed.ceil.b);
}
