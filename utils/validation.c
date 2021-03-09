/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:10:48 by chudapak          #+#    #+#             */
/*   Updated: 2021/03/09 21:51:08 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

void		validate_resalution(t_all *all)
{
	mlx_get_screen_size(all->vars.mlx, &all->tmp_res.screen_width,
			&all->tmp_res.screen_height);
	if ((unsigned int)all->tmp_res.screen_width < all->parsed.res.width)
		all->parsed.res.width = all->tmp_res.screen_width;
	if ((unsigned int)all->tmp_res.screen_height < all->parsed.res.height)
		all->parsed.res.height = all->tmp_res.screen_height;
	all->parsed.res.ratio = (float)all->parsed.res.width
			/ (float)all->parsed.res.height;
}

static int	validate_av(char *arg, char *cub, int i)
{
	int		len;

	len = ft_strlen(arg);
	while (i >= 0)
	{
		if (arg[len] != cub[i])
			return (1);
		len--;
		i--;
	}
	return (0);
}

static int	check_argc(int ac, char **av)
{
	int		option_of_game;

	option_of_game = validate_av(av[1], ".cub", ft_strlen(".cub"));
	if (option_of_game == 1)
	{
		ft_putstr("error - first argument wrong\n");
		return (1);
	}
	if (ac == 3)
	{
		if ((ft_strncmp(av[2], "--save", 7)) == 0)
			option_of_game = 2;
		else
		{
			ft_putstr("error - second argument wrong\n");
			return (1);
		}
	}
	return (option_of_game);
}

int			first_file_validation(int ac, char **av)
{
	if (ac < 2)
	{
		ft_putstr("error - add \"*.cub\" or \"*.cub\" and \"--save\"\n");
		return (1);
	}
	else if (ac > 3)
	{
		ft_putstr("error - to many arguments\n");
		return (1);
	}
	return (check_argc(ac, av));
}

int			second_validation(t_all *all)
{
	if (all->parsed.error_checker == 1)
	{
		error_exit(all, 3, "error - smth wrong with the file\n");
		return (1);
	}
	if (all->parsed.res.width < 200 || all->parsed.res.height < 200)
	{
		error_exit(all, 3, "choose a bigger resalution\n");
		return (1);
	}
	return (0);
}
