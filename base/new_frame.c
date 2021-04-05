#include "../headers/overall.h"

static void		get_ray_len(t_all *all, t_pl *ray)
{
	all->counter = 0;
	ray->ray_len_hor = get_hor_ray_len(all, ray);
	ray->ray_len_ver = get_ver_ray_len(all, ray);
	if (ray->ray_len_hor < ray->ray_len_ver)
	{
		ray->ray_len = ray->ray_len_hor;
		ray->ray_cross = 'H';
	}
	else
	{
		ray->ray_len = ray->ray_len_ver;
		ray->ray_cross = 'V';
	}
}

static float	draw_background(t_all *all, t_pl *ray)
{
	ray->start_agl = (ray->dir + VIEV_ANGLE / 2)
		- ((float)ray->colom / (float)all->parsed.res.width) * VIEV_ANGLE;
	ray->start_agl = keep_angle_in_range(ray->start_agl);
	get_ray_len(all, ray);
	fix_fisheye(all, ray);
	side_wall(ray);
	fill_picture(all, ray);
	return (ray->ray_len);
}

int				draw_new_frame(t_all *all)
{
	t_pl	ray;
	float	rays[(int)all->parsed.res.width];

	move_player(all);
	ray = get_ray_info(all);
	while (++ray.colom < (int)all->parsed.res.width)
		rays[ray.colom] = draw_background(all, &ray);
	if (all->parsed.amt_spr != 0)
		draw_sprite(all, &ray, rays);
	mlx_put_image_to_window(all->vars.mlx, all->vars.win, all->img.img, 0, 0);
	mlx_do_sync(all->vars.mlx);
	return (0);
}
