/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_res.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:30:19 by pmarash           #+#    #+#             */
/*   Updated: 2021/01/25 16:14:38 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

static int	get_res(t_parse *parsed, char **data)
{
	if (parsed->res.width == 0)
	{
		(*parsed).res.width = ft_atoi_dbl_ptr(data);
		if (parsed->res.width <= 0)
			return (1);
	}
	else if (parsed->res.height == 0)
	{
		parsed->res.height = ft_atoi_dbl_ptr(data);
		if (parsed->res.height <= 0)
			return (1);
	}
	return (0);
}

static int	check_repiting(t_parse parsed)
{
	if (parsed.res.width != 0)
		return (1);
	if (parsed.res.height != 0)
		return (1);
	return (0);
}

int			ft_parse_res(t_parse *parsed, char **data)
{
	++*data;
	if ((check_repiting(*parsed)))
		return (1);
	if (**data != ' ')
		return (1);
	while (**data != '\n')
	{
		while (**data == ' ')
			++*data;
		if (**data < '0' || **data > '9')
			if (**data != '\n' || (**data == '\n'
					&& (!parsed->res.width || !parsed->res.height)))
				return (1);
		if ((get_res(parsed, data)) == 1)
			return (1);
	}
	return (0);
}
