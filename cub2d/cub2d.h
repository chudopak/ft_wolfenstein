/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub2d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:03:07 by pmarash           #+#    #+#             */
/*   Updated: 2021/02/04 22:15:32 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB2D_H
# define CUB2D_H

# define SCALE 20
# define MOVE 4
# define EMPT 0x11FFBBFF
# define PL 0x00FF00FF
# define SPRITE 0x0000BB10
# define WALL 0x00FFBB15
# define RAY 0x0099BB99
# define ANGLE M_PI
# define MV_ANGLE 0.1
# define VIEV_ANGLE M_PI / 4

void	get_picture(t_parse parsed);
void	increase_part_wall(t_data *img, float width, float height, unsigned int color, int size);
void	print_map(t_data *img, int i, int j, t_parse parsed);
int		move_player(int keycode, t_all *all);
t_pl	player_init(t_data *img, int i, int j);
void	increment(t_all *all);
void	decrement(t_all *all);
int		get_new_frame(t_all *all);
int		draw_empty(t_all *all);
int		draw_player(t_all *all);
void	ft_cast_rays(t_all *all);
void	draw_ray(t_all *all, t_pl ray, unsigned int color);
int		check_wall(t_all *all);
void	ft_clean_rays(t_all *all);

#endif