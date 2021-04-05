#include "../headers/overall.h"

void	draw_ceil(t_all *all, t_pl *ray)
{
	while (ray->string < ray->ceiling)
	{
		pixel_put(&all->img, ray->string, ray->colom, all->color.clg);
		ray->string++;
	}
}
