/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overall.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:44:53 by pmarash           #+#    #+#             */
/*   Updated: 2021/03/03 20:38:31 by pmarash          ###   ########.fr       */
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

# define WALL_W 0x00419AE3
# define WALL_S 0x006A5402
# define WALL_N 0x11FFBBFF
# define WALL_E 0x001234FF

//
# define ANGLE_MOVE 0.03
# define VIEV_ANGLE 0.75

# define STEP_TO_WALL 0.05
# define WALL_SCALE 2.0
# define STEP_L_R 0.05 * VIEV_ANGLE

# define TEXTURES 5
# define STOP_BF_WALL 0.3

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

typedef struct	s_side {
	int			ray_cross_i;
	int			ray_cross_j;
	int			side;
}				t_side;

typedef struct	s_tmpres {
	int			screen_width;
	int			screen_height;
}				t_tmpres;

typedef struct	s_move {
	double		step_i;
	double		step_j;
	double		limit_i;
	double		limit_j;		
}				t_move;

typedef struct	s_pl {
	float		i;
	float		j;
	int			size;
	double		dir;
	int			mv_check;
	int			ray_mv_check;
	float		old_dir;
	double		start_agl;
	float		end;
	int			floor;
	int			ceiling;
	int			wallH;
	int			nb_tex;
	float		step;
	float		row_of_tex;
	int			colom_of_tex;
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
	char		rayCross;
	double		len_main_ray;
	char		ray_hit_wall;
	float		ray_cross_i;
	float		ray_cross_j;
	t_move		move;
}				t_pl;

typedef struct	s_frame {
	int			floor;
	int			ceiling;
	float		ray_len;
}				t_frame;

typedef struct	s_colors {
	int			flr;
	int			clg;
}				t_colors;

typedef struct	s_keys {
	int			w;
	int			s;
	int			d;
	int			a;
	int			right;
	int			left;
}				t_keys;

typedef struct	s_textures {
	int			tH;
	int			tW;
	char		*path;
	void		*tex;
	void		*ptr;
	int			bpp;
	int			size_line;
	int			endian;
}				t_textures;

typedef struct	s_sprite {
	float		i;
	float		j;
	float		vec_i;
	float		vec_j;
	float		eye_i;
	float		eye_j;
	float		ang_btw_pl_sp;
	float		sprite_angle;
}				t_sprite;

typedef struct	s_spr {
	float		i;
	float		j;
	float		len_till_pl;
	float		ang_btw_pl_sp;
	float		sprite_angle;
}				t_spr;

typedef struct	s_spr_limits {
	float		spr_ceiling;
	float		spr_floor;
	float		spr_height;
	float		spr_width;
	float		aspect_ratio;
	float		mdl_spr;
	float		row_tex;
	float		colom_tex;
	float		ratio_h;
	float		ratio_w;
	int			img_colom;
	int			img_row;
	int			sprite_colom;
	int			sprite_row;
}				t_spr_limit;

typedef struct	s_all {
	t_data		img;
	t_vars		vars;
	t_pl		player;
	t_parse		parsed;
	int			way_launch;
	t_tmpres	tmpRes;
	t_colors	color;
	t_keys		key;
	t_textures	texture[TEXTURES];
	char		*tex_path[5];
	t_sprite	*sprite;
	int			counter;
}				t_all;

void			pixel_put(t_data *data, int	width, int height, unsigned int color);
int				first_file_validation(int ac, char **av);
int				second_validation(t_all all);
int				draw_new_frame(t_all *all);
void		 	get_ray_len(t_all *all, t_pl *ray);
t_pl			get_ray_info(t_all *all);
int				set_player(t_all *all);
double			get_ver_ray_len(t_all *all, t_pl *ray);
double			get_hor_ray_len(t_all *all, t_pl *ray);
double			count_len(t_raycast way, t_pl *ray);
int				move_player(t_all *all);
float			keep_angle_in_range(float angle);
void			fill_picture(t_all *all, t_pl *ray);
void			set_ver_variebles(t_pl *ray, t_raycast *ver, int indicator);
void			set_hor_variebles(t_pl *ray, t_raycast *hor, int indicator);
void			fix_fisheye(t_all *all, t_pl *ray);
void			validate_resalution(t_all *all);
int				get_b(int trgb);
int				get_g(int trgb);
int				get_r(int trgb);
int				get_t(int trgb);
int				create_trgb(int t, int r, int g, int b);
void			get_colors(t_all *all);
int				check_cell(t_all *all, t_raycast cell);
void			side_wall(t_pl *ray);
void			draw_wall_no_tex(t_all *all, t_pl *ray);
int				key_pressed(int keycode, t_all *all);
int				key_released(int keycode, t_all *all);
int				load_textures(t_all *all);
void			draw_wall(t_all *all, t_pl *ray);
void			draw_floor(t_all *all, t_pl *ray);
void			draw_ceil(t_all *all, t_pl *ray);
t_sprite		*get_sprites_info(t_all *all);
void			draw_sprite(t_all *all, t_pl *ray);

#endif
