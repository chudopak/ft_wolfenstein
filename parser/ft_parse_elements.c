/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:33:55 by pmarash           #+#    #+#             */
/*   Updated: 2021/03/09 22:37:44 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

static int	validate_texture(t_parse *parsed)
{
	if (parsed->texture.no == NULL || parsed->texture.so == NULL
			|| parsed->texture.we == NULL
			|| parsed->texture.s == NULL || parsed->texture.ea == NULL)
		return (1);
	return (0);
}

int			ft_parse_elements(t_parse *parsed, char **data)
{
	int		parsed_elements;
	int		error;

	parsed_elements = 0;
	error = 1;
	while (parsed_elements < 8)
	{
		while (**data == '\n')
			++*data;
		if (**data == 'R')
			error = ft_parse_res(parsed, data);
		else if (**data == 'F')
			error = ft_parse_flor(parsed, data);
		else if (**data == 'C')
			error = ft_parse_ceil(parsed, data);
		else if (**data == 'N' || **data == 'S'
				|| **data == 'W' || **data == 'E')
			error = ft_parse_texture(parsed, data);
		if (error == 1)
			return (1);
		parsed_elements++;
	}
	if ((validate_texture(parsed)) == 1)
		return (1);
	return (0);
}
