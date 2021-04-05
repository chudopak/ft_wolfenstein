#include "../headers/overall.h"

t_sprite	*get_sprites_info(t_all *all)
{
	unsigned int	i;
	unsigned int	j;
	t_sprite		*sprite;

	all->counter = 0;
	if (!(sprite = (t_sprite*)malloc(sizeof(t_sprite) * (all->parsed.amt_spr))))
		error_exit(all, 5, "error - memory wasn't allocated for sprites\n");
	i = -1;
	while (++i < all->parsed.p_coord.rows && all->counter < all->parsed.amt_spr)
	{
		j = 0;
		while (all->parsed.map[i][j] != '\0'
				&& all->counter < all->parsed.amt_spr)
		{
			if (all->parsed.map[i][j] == '3')
			{
				sprite[all->counter].i = (float)i + 0.5;
				sprite[all->counter].j = (float)j + 0.5;
				all->parsed.map[i][j] = '2';
				all->counter++;
			}
			j++;
		}
	}
	return (sprite);
}
