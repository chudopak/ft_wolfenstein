/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_2dmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 18:01:34 by pmarash           #+#    #+#             */
/*   Updated: 2021/02/12 19:29:34 by chudapak         ###   ########.fr       */
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
	ray.start_agl	= ray.dir - VIEV_ANGLE;
	ray.end		= ray.dir + VIEV_ANGLE;
	while (ray.start_agl <= ray.end)
	{
		ray.i = all->player.i + SCALE / 2 + 1;
		ray.j = all->player.j + SCALE / 2 + 1;
		while (all->parsed.map[(int)ray.i / SCALE][(int)ray.j / SCALE] != '1'
				&& all->parsed.map[(int)ray.i / SCALE][(int)ray.j / SCALE] != '2'
				&& all->parsed.map[(int)ray.i / SCALE][(int)ray.j / SCALE] != ' '
				&& all->parsed.map[(int)ray.i / SCALE][(int)ray.j / SCALE] != '\0')
		{
			ray.i += cos(ray.start_agl);
			ray.j += sin(ray.start_agl);
			pixel_put(&all->img, ray.i, ray.j, RAY);
		}
		ray.start_agl += M_PI_2 / 5;
	}
}

t_pl	get_ray_info(t_all *all)
{
	//all->player.start_agl = all->player.dir - VIEV_ANGLE / 2;
	all->player.colom = -1;
	if (all->player.dir > 2 * M_PI)
		all->player.dir -= 2 * M_PI;
	else if (all->player.dir < 0)
		all->player.dir += 2 * M_PI;
	return (all->player);
}

double	count_len(t_raycast way, t_pl *ray)
{
	return (sqrt(pow(way.rayI - ray->i, 2) + pow(way.rayJ - ray->j, 2)));
}

double	get_hor_ray_len(t_all *all, t_pl *ray)
{
	t_raycast	hor;
	double		ray_len;

	if ((tan(ray->start_agl)))
		hor.tan = -1/tan(ray->start_agl);
	if (ray->start_agl == 2 * M_PI  || ray->start_agl == M_PI)
		return (0);
	else if (ray->start_agl > M_PI)//looking down
	{
		hor.rayI = (int)ray->i + 1;
		hor.rayJ = (ray->i - hor.rayI) * hor.tan + ray->j;
		hor.offsetI = 1;
		hor.offsetJ = -hor.offsetI * hor.tan;
	}
	else if (ray->start_agl < M_PI)//looking up
	{
		hor.rayI = (int)ray->i;
		hor.rayJ = (ray->i - hor.rayI) * hor.tan + ray->j;
		hor.offsetI = -1;
		hor.offsetJ = -hor.offsetI * hor.tan;
	}
	while ((int)hor.rayI > 0 && (int)hor.rayI < all->parsed.p_coord.rows
			&& (int)hor.rayJ > 0 && (int)hor.rayJ < LINES
			&& all->parsed.map[(int)hor.rayI][(int)hor.rayJ] != '1'
			&& all->parsed.map[(int)hor.rayI][(int)hor.rayJ] != '2'
			&& all->parsed.map[(int)hor.rayI][(int)hor.rayJ] != ' '
			&& all->parsed.map[(int)hor.rayI][(int)hor.rayJ] != '\0')
	{
		hor.rayI += hor.offsetI;
		hor.rayJ += hor.offsetJ;
		pixel_put(&all->img, hor.rayI, hor.rayJ, RAY);
	}
	return (ray_len = count_len(hor, ray));
}

double	get_ver_ray_len(t_all *all, t_pl *ray)
{
	t_raycast	ver;
	double		ray_len;

	if ((tan(ray->start_agl)))
		ver.tan = -tan(ray->start_agl);
	if (ray->start_agl == 3 * M_PI / 2 || ray->start_agl == M_PI / 2)
		return (0);
	else if (ray->start_agl < M_PI / 2 || ray->start_agl > 3 * M_PI / 2)//looking right
	{
		ver.rayJ = (int)ray->j + 1;
		ver.rayI = (ray->j - ver.rayJ) * ver.tan + ray->i;
		ver.offsetJ = 1;
		ver.offsetI = -ver.offsetJ * ver.tan;
	}
	else if (ray->start_agl > M_PI / 2 && ray->start_agl < 3 * M_PI / 2)//looking left
	{
		ver.rayJ = (int)ray->j;
		ver.rayI = (ray->j - ver.rayJ) * ver.tan + ray->i;
		ver.offsetJ = -1;
		ver.offsetI = -ver.offsetJ * ver.tan;
	}
	while ((int)ver.rayI > 0 && (int)ver.rayI < all->parsed.p_coord.rows
			&& (int)ver.rayJ > 0 && (int)ver.rayJ < LINES
			&& all->parsed.map[(int)ver.rayI][(int)ver.rayJ] != '1'
			&& all->parsed.map[(int)ver.rayI][(int)ver.rayJ] != '2'
			&& all->parsed.map[(int)ver.rayI][(int)ver.rayJ] != ' '
			&& all->parsed.map[(int)ver.rayI][(int)ver.rayJ] != '\0')
	{
		ver.rayI += ver.offsetI;
		ver.rayJ += ver.offsetJ;
		pixel_put(&all->img, ver.rayI, ver.rayJ, RAY);
	}
	return (ray_len = count_len(ver, ray));
}

void	get_ray_len(t_all *all, t_pl *ray)
{
	ray->ray_len_hor = get_hor_ray_len(all, ray);
	ray->ray_len_ver = get_ver_ray_len(all, ray);
	if (ray->ray_len_hor < ray->ray_len_ver)
		ray->ray_len = ray->ray_len_hor;
	else
		ray->ray_len = ray->ray_len_ver;
}

int		draw_new_frame(t_all *all)
{
	t_pl	ray;

	if (all->player.mv_check == 1)
	{
		ray = get_ray_info(all);
		//while (++ray.colom < (int)all->parsed.res.width)
		//{
		//	ray.start_agl = (ray.dir + VIEV_ANGLE / 2) - ((float)ray.colom / (float)all->parsed.res.width) * VIEV_ANGLE;
			get_ray_len(all, &ray);
			/*ray.ceiling = (int)((float)(all->parsed.res.height / 2) - all->parsed.res.height / (ray.ray_len));
			ray.floor = all->parsed.res.height - ray.ceiling;
			ray.string = -1;
			while (++ray.string < (int)all->parsed.res.height)
			{
				if (ray.string < ray.ceiling)
					pixel_put(&all->img, ray.string, ray.colom, CEILING);
				else if (ray.string >= ray.ceiling && ray.string <= ray.floor)
					pixel_put(&all->img, ray.string, ray.colom, WALL);
				else
					pixel_put(&all->img, ray.string, ray.colom, FLOOR);
			}*/
		//}
		mlx_put_image_to_window(all->vars.mlx, all->vars.win, all->img.img, 0, 0);
		all->player.mv_check = 0;
	}
	return (0);
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
	mlx_loop_hook(all.vars.mlx, draw_new_frame, &all);
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
