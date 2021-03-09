/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 17:28:55 by chudapak          #+#    #+#             */
/*   Updated: 2021/03/08 22:05:51 by pmarash          ###   ########.fr       */
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
		path, &tex->t_w, &tex->t_h)))
		tex->ptr = mlx_get_data_addr(tex->tex,
			&tex->bpp, &tex->size_line, &tex->endian);
	else
		return (1);
	return (0);
}

int			load_textures(t_all *all)
{
	all->spr_free = NULL;
	all->loaded_tex = -1;
	paths_tex(all);
	while (++(all->loaded_tex) < TEXTURES)
		if ((load_texture(&all->vars, &all->texture[all->loaded_tex],
				all->tex_path[all->loaded_tex])) == 1)
		{
			error_exit(all, 1, "error - some texture didn't loaded\n");
			return (1);
		}
	return (0);
}
