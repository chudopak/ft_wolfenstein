#include "../headers/overall.h"

static char	*cp_dir(char **data)
{
	char	*dir;
	char	*tmp;
	int		size;
	int		i;

	size = 0;
	tmp = *data;
	i = -1;
	while (*tmp != ' ' && *tmp != '\n')
	{
		size++;
		tmp++;
	}
	if (!(dir = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	dir[size] = '\0';
	while (++i < size)
	{
		dir[i] = **data;
		++*data;
	}
	return (dir);
}

static int	get_to_end(char **data)
{
	while (**data != '\n')
	{
		if (**data != ' ')
			return (1);
		(*data)++;
	}
	return (0);
}

static int	get_direction(t_parse *parsed, char *sow, char **data)
{
	char	*dir;

	if (**data == 'S' && *(*data + 1) != 'O')
		++*data;
	else
		*data += 2;
	if (**data != ' ')
		return (1);
	while (**data == ' ')
		++*data;
	if (!(dir = cp_dir(data)))
		return (1);
	if (*sow == 'N' && *(sow + 1) == 'O')
		parsed->texture.no = dir;
	else if (*sow == 'S' && *(sow + 1) == 'O')
		parsed->texture.so = dir;
	else if (*sow == 'W' && *(sow + 1) == 'E')
		parsed->texture.we = dir;
	else if (*sow == 'E' && *(sow + 1) == 'A')
		parsed->texture.ea = dir;
	else if (*sow == 'S')
		parsed->texture.s = dir;
	return (get_to_end(data));
}

int			ft_parse_texture(t_parse *parsed, char **data)
{
	if (**data == 'N' && *(*data + 1) == 'O')
		return (get_direction(parsed, "NO", data));
	else if (**data == 'S' && *(*data + 1) == 'O')
		return (get_direction(parsed, "SO", data));
	else if (**data == 'W' && *(*data + 1) == 'E')
		return (get_direction(parsed, "WE", data));
	else if (**data == 'E' && *(*data + 1) == 'A')
		return (get_direction(parsed, "EA", data));
	else if (**data == 'S')
		return (get_direction(parsed, "S", data));
	else
		return (1);
	return (0);
}
