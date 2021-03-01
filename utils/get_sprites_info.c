/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites_info.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 17:03:06 by chudapak          #+#    #+#             */
/*   Updated: 2021/03/01 16:58:41 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"
#include <stdio.h>

static void	set_coordinates(t_all *all, int i, int j, t_sprite **sprite)
{
	if (all->counter >= all->parsed.amt_spr)
		return ;
	if (all->parsed.map[i][j] == '3')
	{
		printf("%c - next %c - ", all->parsed.map[i][j], all->parsed.map[i][j - 1]);
		sprite[all->counter]->i = (float)i + 0.5;
		sprite[all->counter]->j = (float)j + 0.5;
		all->parsed.map[i][j] = '2';
		printf("i - %f, j - %f\n", sprite[all->counter]->i, sprite[all->counter]->j);
		printf("%c\n", all->parsed.map[i][j]);
		all->counter++;
		return ;
	}
	if (all->parsed.map[i][j] == '1' || all->parsed.map[i][j] == '0' || all->parsed.map[i][j] == '2')
		return ;
	if (all->parsed.map[i][j] == '.')
		all->parsed.map[i][j] = '0';
	set_coordinates(all, i - 1, j, sprite);
	set_coordinates(all, i, j - 1, sprite);
	set_coordinates(all, i, j + 1, sprite);
	set_coordinates(all, i + 1, j, sprite);
}

t_sprite	*get_sprites_info(t_all *all)
{
	t_sprite	*sprite;

	all->counter = 0;
	if (!(sprite = (t_sprite*)malloc(sizeof(t_sprite) * all->parsed.amt_spr)))
		exit(0);
	for (int i = 0; i < all->parsed.p_coord.rows; i++)
	{
		for (int j = 0; all->parsed.map[i][j] != '\0'; j++)
			printf("%c", all->parsed.map[i][j]);
		printf("\n");
	}
	printf("\n");
	set_coordinates(all, all->parsed.p_coord.i, all->parsed.p_coord.j, &sprite);
	for (int i = 0; i < all->parsed.p_coord.rows; i++)
	{
		for (int j = 0; all->parsed.map[i][j] != '\0'; j++)
			printf("%c", all->parsed.map[i][j]);
		printf("\n");
	}
	return (sprite);
}