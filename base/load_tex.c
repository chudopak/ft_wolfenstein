/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 17:28:55 by chudapak          #+#    #+#             */
/*   Updated: 2021/03/04 15:21:31 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

static void	paths_tex(t_all *all)
{
	all->tex_path[0] = all->parsed.texture.no;
	all->tex_path[1] = all->parsed.texture.so;
	all->tex_path[2] = all->parsed.texture.we;
	all->tex_path[3] = all->parsed.texture.ea;
	all->tex_path[4] = all->parsed.texture.s;
}

static int	load_texture(t_vars *vars, t_textures *tex, char *path)
{
	tex->path = path;
	if ((tex->tex = mlx_xpm_file_to_image(vars->mlx,
		path, &tex->tW, &tex->tH)))
		tex->ptr = mlx_get_data_addr(tex->tex,
			&tex->bpp, &tex->size_line, &tex->endian);
	else
		return (1);
	return (0);
}

int			load_textures(t_all *all)
{
	int		i;

	paths_tex(all);
	i = -1;
	while (++i < TEXTURES)
		if ((load_texture(&all->vars, &all->texture[i], all->tex_path[i])) == 1)
			return (1);
	return (0);
}
