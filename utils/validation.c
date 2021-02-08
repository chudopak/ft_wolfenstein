/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 17:10:48 by chudapak          #+#    #+#             */
/*   Updated: 2021/02/08 19:37:02 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

//make lib with ft_printf

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

int			first_file_validation(int ac, char **av)
{
	int		option_of_game;

	option_of_game = 0;
	if (ac < 2)
	{
		ft_putstr("error - add \"*.cub\" or \"--save\"\n");
		return (1);
	}
	else if (ac > 2)
	{
		ft_putstr("error - to many arguments\n");
		return (1);
	}
	if ((ft_strncmp(av[1], "--save", 7)) == 0)
		return (2);
	option_of_game = validate_av(av[1], ".cub", ft_strlen(".cub"));
	if (option_of_game == 1)
	{
		ft_putstr("error - input valid argument\n");
		return (1);
	}
	return (option_of_game);
}

int			second_validation(t_all all)
{
	if (all.parsed.error_checker == 1)
	{
		ft_putstr("error - smth wrong with the file\n");
		return (1);
	}
	if (all.parsed.res.width < 200 || all.parsed.res.height < 200)
	{
		ft_putstr("choose a bigger resalution\n");
		return (1);
	}
	return (0);
}