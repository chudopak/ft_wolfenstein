#include "../headers/overall.h"

void		draw_floor(t_all *all, t_pl *ray)
{
	while (ray->string < (int)all->parsed.res.height)
	{
		pixel_put(&all->img, ray->string, ray->colom, all->color.flr);
		ray->string++;
	}
}
