/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:50:49 by pmarash           #+#    #+#             */
/*   Updated: 2021/01/21 18:00:35 by pmarash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/overall.h"

static int	first_validation(char *data)
{
	int		player;

	player = 0;
	while (*data)
	{
		if (*(data - 1) == '\n')
			if ((check_string(data)) == 1)
				return (1);
		if (*data == '\n' && *(data + 1) == '\n')
			return (1);
		else if (*data != '0' && *data != '1' && *data != '2' && *data != ' '
				&& *data != '\n' && *data != 'N' && *data != 'S'
				&& *data != 'E' && *data != 'W')
			return (1);
		if (*data == 'N' || *data == 'S' || *data == 'E' || *data == 'W')
			player++;
		if (player > 1)
			return (1);
		++data;
	}
	if (player == 0)
		return (1);
	return (0);
}

static int	map_start(char **data)
{
	char	*tmp;

	++*data;
	tmp = *data;
	while (**data == ' ' || **data == '\n')
	{
		if (**data == '\n')
			tmp = *data + 1;
		++*data;
	}
	if (**data == '\0')
		return (1);
	else if (**data == '0' && *(*data + 1) != '1')
		return (1);
	*data = tmp;
	return (0);
}

static int	get_map(t_parse *parsed, char *data, int rows)
{
	int		i;
	int		j;
	int		size;

	i = -1;
	if (!(parsed->map = malloc(sizeof(char*) * rows)))
		return (1);
	while (++i < rows)
	{
		size = 0;
		j = -1;
		while (*(data + size) != '\n' && *(data + size) != '\0')
			size++;
		if (!(parsed->map[i] = malloc(size + 1)))
			return (1);
		while (++j < size)
		{
			parsed->map[i][j] = *(data + j);
			check_for_player(parsed, *(data + j), i, j);
		}
		parsed->map[i][j] = '\0';
		data += j + 1;
	}
	return (0);
}

static int	allocation_map(t_parse *parsed, char **data)
{
	int		rows;
	char	*tmp;

	tmp = *data;
	rows = 0;
	while (*tmp)
	{
		if (*tmp == '\n')
			rows++;
		tmp++;
	}
	if (*(tmp - 1) != '\n')
		rows++;
	parsed->p_coord.rows = rows;
	if ((get_map(parsed, *data, rows)) == 1)
		return (1);
	return (0);
}

int			ft_parse_map(t_parse *parsed, char **data)
{
	if ((map_start(data)) == 1)
		return (1);
	if ((first_validation(*data)) == 1)
		return (1);
	if ((allocation_map(parsed, data)) == 1)
		return (1);
	flood_fill(parsed->map, parsed->p_coord.i,
			parsed->p_coord.j, parsed);
	if (parsed->error_checker == 1)
		return (1);
	return (0);
}
