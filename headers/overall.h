/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overall.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:44:53 by pmarash           #+#    #+#             */
/*   Updated: 2021/01/27 18:09:09 by pmarash          ###   ########.fr       */
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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

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

typedef struct	s_pl {
	float		i;
	float		j;
	char		aux;
	int			size;
	int			mv_check;
}				t_pl;

typedef struct	s_all {
	t_data		img;
	t_vars		vars;
	t_pl		player;
	t_parse		parsed;
}				t_all;

void			pixel_put(t_data *data, int	width, int height, unsigned int color);

#endif
