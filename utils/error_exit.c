#include "../headers/overall.h"

static void	clear_window(t_all *all)
{
	if (all->vars.mlx && all->vars.win)
		mlx_destroy_window(all->vars.mlx, all->vars.win);
	if (all->img.img)
		mlx_destroy_image(all->vars.mlx, all->img.img);
}

static void	clear_parsed(t_all *all)
{
	unsigned int i;

	i = -1;
	if (all->parsed.map)
		while (++i < all->parsed.p_coord.rows && all->parsed.map[i])
			free(all->parsed.map[i]);
	if (all->parsed.texture.no)
		free(all->parsed.texture.no);
	if (all->parsed.texture.so)
		free(all->parsed.texture.so);
	if (all->parsed.texture.ea)
		free(all->parsed.texture.ea);
	if (all->parsed.texture.we)
		free(all->parsed.texture.we);
	if (all->parsed.texture.s)
		free(all->parsed.texture.s);
}

static void	clear_textures(t_all *all)
{
	int		i;

	i = -1;
	while (++i < all->loaded_tex)
	{
		if (all->texture[i].tex)
			mlx_destroy_image(all->vars.mlx, all->texture[i].tex);
		all->texture[i].tex = NULL;
		all->texture[i].ptr = NULL;
	}
}

void		error_exit(t_all *all, int error_code, char *error_massage)
{
	if (error_massage)
		ft_putstr(error_massage);
	if (error_code != 5)
		clear_window(all);
	clear_parsed(all);
	if (all->spr_free != NULL && error_code == 0)
		free(all->spr_free);
	if (error_code != 3)
		clear_textures(all);
	if (error_code != 1 && error_code != 3)
		exit(error_code);
}
