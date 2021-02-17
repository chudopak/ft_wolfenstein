/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overall.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:44:53 by pmarash           #+#    #+#             */
/*   Updated: 2021/02/16 21:56:25 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OVERALL_H
# define OVERALL_H

# include "ft_parser.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../minilibx_mms_20200219/mlx.h"
# include <math.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

# define CEILING 0x00419AE3
# define WALL 0x006A5402
# define FLOOR 0x11FFBBFF

//
# define ANGLE_MOVE 0.07
# define VIEV_ANGLE 1.15192
# define STEP_TO_WALL 0.1

# define LINES 48

typedef struct	s_data {
	char		*addr;
	void		*img;
	int			endian;
	int			bits_per_pixel;
	int			line_length;
}				t_data;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
}				t_vars;

typedef struct	s_raycast {
	double		tan;
	double		rayJ;
	double		rayI;
	double		offsetJ;
	double		offsetI;
}				t_raycast;

typedef struct	s_pl {
	float		i;
	float		j;
	float		old_i;
	float		old_j;
	char		aux;
	int			size;
	double		dir;
	float		size_a;
	int			mv_check;
	int			ray_mv_check;
	float		old_dir;
	double		start_agl;
	float		end;
	int			floor;
	int			ceiling;
	double		ray_len;
	float		step_len;
	int			colom;
	int			string;
	int			cos_i;
	int			sin_i;
	int			step_i;
	int			step_j;
	double		fish_angle;
	double		ray_len_hor;
	double		ray_len_ver;
}				t_pl;

typedef struct	s_frame {
	int			floor;
	int			ceiling;
	float		ray_len;
}				t_frame;

typedef struct	s_all {
	t_data		img;
	t_vars		vars;
	t_pl		player;
	t_parse		parsed;
	int			way_launch;
}				t_all;

void			pixel_put(t_data *data, int	width, int height, unsigned int color);
int				first_file_validation(int ac, char **av);
int				second_validation(t_all all);
int				draw_new_frame(t_all *all);
void		 	get_ray_len(t_all *all, t_pl *ray);
void			get_final_coordinate(t_all *all, t_pl *ray);
void			way_pl_looking(t_pl *ray);
t_pl			get_ray_info(t_all *all);
int				set_player(t_all *all);
double			get_ver_ray_len(t_all *all, t_pl *ray);
double			get_hor_ray_len(t_all *all, t_pl *ray);
double			count_len(t_raycast way, t_pl *ray);
int				move_player(int keycode, t_all *all);
float			keep_angle_in_range(float angle);
void			fill_picture(t_all *all, t_pl *ray);
void			set_ver_variebles(t_pl *ray, t_raycast *ver, int indicator);


#endif
