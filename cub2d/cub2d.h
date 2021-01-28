/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub2d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:03:07 by pmarash           #+#    #+#             */
/*   Updated: 2021/01/27 18:08:46 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB2D_H
# define CUB2D_H

# define SCALE 20

void	get_picture(t_parse parsed);
void	increase_part_wall(t_data *img, float width, float height, unsigned int color, int size);
void	print_map(t_data *img, int i, int j, t_parse parsed);
int		move_player(int keycode, t_all *all);
t_pl	player_init(t_data *img, int i, int j);
void	increment(t_all *all);
void	decrement(t_all *all);
int		get_new_frame(t_all *all);
void	set_posicion(t_all *all, int size, char coord);
int		draw_empty(t_all *all);
int		draw_player(t_all *all);

#endif