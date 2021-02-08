/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_2dmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:01:34 by pmarash           #+#    #+#             */
/*   Updated: 2021/02/05 18:51:53 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"
#include "cub2d.h"

int		get_new_frame(t_all *all)
{
	if (all->player.mv_check == 1)
	{
		increment(all);
		if ((check_wall(all)) == 1)
			decrement(all);
		else
		{
			decrement(all);
			draw_empty(all);
			increment(all);
		}		
	}
	if (all->player.ray_mv_check == 1)
	{
		ft_clean_rays(all);
		ft_cast_rays(all);
		draw_player(all);
	}
	mlx_put_image_to_window(all->vars.mlx, all->vars.win, all->img.img, 0, 0);
	all->player.mv_check = 0;
	return (0);
}

void	ft_cast_rays(t_all *all)
{
	t_pl	ray;

	ray 		= all->player;
	ray.i		+= SCALE / 2 + 1;
	ray.j		+= SCALE / 2 + 1;
	ray.start	= ray.dir - VIEV_ANGLE;
	ray.end		= ray.dir + VIEV_ANGLE;
	while (ray.start <= ray.end)
	{
		ray.i = all->player.i + SCALE / 2 + 1;
		ray.j = all->player.j + SCALE / 2 + 1;
		while (all->parsed.map[(int)ray.i / SCALE][(int)ray.j / SCALE] != '1'
				&& all->parsed.map[(int)ray.i / SCALE][(int)ray.j / SCALE] != '2'
				&& all->parsed.map[(int)ray.i / SCALE][(int)ray.j / SCALE] != ' '
				&& all->parsed.map[(int)ray.i / SCALE][(int)ray.j / SCALE] != '\0')
		{
			ray.i += cos(ray.start);
			ray.j += sin(ray.start);
			pixel_put(&all->img, ray.i, ray.j, RAY);
		}
		ray.start += M_PI_2 / 100;
	}
}

void	get_picture(t_parse parsed)
{
	t_all	all;

	all.parsed		= parsed;
	all.vars.mlx	= mlx_init();
	all.vars.win	= mlx_new_window(all.vars.mlx,
						parsed.res.width, parsed.res.height, "test");
	all.img.img 	= mlx_new_image(all.vars.mlx,
						parsed.res.width, parsed.res.height);
	all.img.addr	= mlx_get_data_addr(all.img.img,
						&all.img.bits_per_pixel, &all.img.line_length, &all.img.endian);
						
	print_map(&all.img, parsed.p_coord.i, parsed.p_coord.j, parsed);
	mlx_put_image_to_window(all.vars.mlx, all.vars.win, all.img.img, 0, 0);
	
	all.player		= player_init(&all.img, parsed.p_coord.i, parsed.p_coord.j);
	mlx_hook(all.vars.win, 2, 1L<<0, move_player, &all);
	mlx_loop_hook(all.vars.mlx, get_new_frame, &all);
	mlx_loop(all.vars.mlx);
}

int		main(int ac, char **av)
{
	t_parse parsed;

	if (ac != 2)
	{
		ft_putstr("error");
		return (1);
	}
	parsed = ft_parser(av[1]);
	if (parsed.res.width < 200 || parsed.res.height < 200 || parsed.error_checker == 1)
	{
		ft_putstr("choose biger resalution\n");
		return (1);
	}
	get_picture(parsed);
	return (0);
}
