/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 16:58:41 by chudapak          #+#    #+#             */
/*   Updated: 2021/03/09 16:12:51 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

static int	start_game(t_all *all)
{
	all->vars.mlx = mlx_init();
	validate_resalution(all);
	get_colors(all);
	all->vars.win = mlx_new_window(all->vars.mlx, all->parsed.res.width,
			all->parsed.res.height, "cub3d");
	all->img.img = mlx_new_image(all->vars.mlx, all->parsed.res.width,
			all->parsed.res.height);
	all->img.addr = mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel,
			&all->img.line_length, &all->img.endian);
	if ((load_textures(all)) == 1)
		return (1);
	if (all->way_launch == 2)
	{
		if (!create_bmp(all))
			return (0);
		return (2);
	}
	mlx_hook(all->vars.win, 3, 1L << 1, key_released, all);
	mlx_hook(all->vars.win, 2, 1L << 0, key_pressed, all);
	mlx_hook(all->vars.win, 17, 1L << 2, exit_game, all);
	mlx_loop_hook(all->vars.mlx, draw_new_frame, all);
	mlx_loop(all->vars.mlx);
	return (0);
}

int			main(int ac, char **av)
{
	t_all	all;
	int		error;

	all.way_launch = first_file_validation(ac, av);
	if (all.way_launch == 1)
		return (1);
	all.parsed = ft_parser(av[1]);
	if ((second_validation(&all)) == 1)
		return (1);
	all.sprite = get_sprites_info(&all);
	if ((set_player(&all)) == 1)
		return (1);
	error = start_game(&all);
	if (!error)
		error_exit(&all, 1, "bmp created");
	else if (error == 2)
		error_exit(&all, 1, "bmp creation failed");
	return (0);
}
