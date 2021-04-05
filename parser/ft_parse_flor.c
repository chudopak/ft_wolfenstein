#include "../headers/overall.h"

static int	assign_nb(t_parse *parsed, char **data)
{
	if (parsed->flor.r == -1)
	{
		parsed->flor.r = atoi_cub(data);
		if (parsed->flor.r < 0 || parsed->flor.r > 255)
			return (1);
	}
	else if (parsed->flor.g == -1)
	{
		parsed->flor.g = atoi_cub(data);
		if (parsed->flor.g < 0 || parsed->flor.g > 255)
			return (1);
	}
	else if (parsed->flor.b == -1)
	{
		parsed->flor.b = atoi_cub(data);
		if (parsed->flor.b < 0 || parsed->flor.b > 255)
			return (1);
	}
	return (0);
}

static int	get_color_nb(t_parse *parsed, char **data)
{
	if (parsed->flor.r != -1 && parsed->flor.g != -1 && parsed->flor.b != -1)
		return (1);
	if (assign_nb(parsed, data) == 1)
		return (1);
	while (**data == ' ')
		++*data;
	if (**data != ',' && (parsed->flor.r == -1 || parsed->flor.g == -1
			|| parsed->flor.b == -1))
		return (1);
	if ((parsed->flor.r == -1 || parsed->flor.g == -1
			|| parsed->flor.b == -1) && **data == ',')
		++*data;
	return (0);
}

static int	check_repiting(t_parse parsed)
{
	if (parsed.flor.r != -1)
		return (1);
	if (parsed.flor.g != -1)
		return (1);
	if (parsed.flor.b != -1)
		return (1);
	return (0);
}

static int	check_empty(t_parse parsed)
{
	if (parsed.flor.r == -1)
		return (1);
	if (parsed.flor.g == -1)
		return (1);
	if (parsed.flor.b == -1)
		return (1);
	return (0);
}

int			ft_parse_flor(t_parse *parsed, char **data)
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
		if ((**data < '0' || **data > '9') && **data != ',')
			if (**data != '\n' || (**data == '\n' && (parsed->flor.r == -1
					|| parsed->flor.b == -1 || parsed->flor.g == -1)))
				return (1);
		if ((get_color_nb(parsed, data)) == 1)
			return (1);
	}
	if (check_empty(*parsed) == 1)
		return (1);
	return (0);
}
