#include "../headers/overall.h"

void	get_colors(t_all *all)
{
	all->color.flr = create_trgb(0, all->parsed.flor.r,
			all->parsed.flor.g, all->parsed.flor.b);
	all->color.clg = create_trgb(0, all->parsed.ceil.r,
			all->parsed.ceil.g, all->parsed.ceil.b);
}
