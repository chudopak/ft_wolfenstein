#include "../headers/overall.h"

static int	assign_nb(t_parse *parsed, char **data)
{
	if (parsed->ceil.r == -1)
	{
		parsed->ceil.r = atoi_cub(data);
		if (parsed->ceil.r < 0 || parsed->ceil.r > 255)
			return (1);
	}
	else if (parsed->ceil.g == -1)
	{
		parsed->ceil.g = atoi_cub(data);
		if (parsed->ceil.g < 0 || parsed->ceil.g > 255)
			return (1);
	}
	else if (parsed->ceil.b == -1)
	{
		parsed->ceil.b = atoi_cub(data);
		if (parsed->ceil.b < 0 || parsed->ceil.b > 255)
			return (1);
	}
	return (0);
}

static int	get_color_nb(t_parse *parsed, char **data)
{
	if (parsed->ceil.r != -1 && parsed->ceil.g != -1 && parsed->ceil.b != -1)
		return (1);
	if (assign_nb(parsed, data) == 1)
		return (1);
	while (**data == ' ')
		++*data;
	if (**data != ',' && (parsed->ceil.r == -1 || parsed->ceil.g == -1
			|| parsed->ceil.b == -1))
		return (1);
	if ((parsed->ceil.r == -1 || parsed->ceil.g == -1
			|| parsed->ceil.b == -1) && **data == ',')
		++*data;
	return (0);
}

static int	check_repiting(t_parse parsed)
{
	if (parsed.ceil.r != -1)
		return (1);
	if (parsed.ceil.g != -1)
		return (1);
	if (parsed.ceil.b != -1)
		return (1);
	return (0);
}

static int	check_empty(t_parse parsed)
{
	if (parsed.ceil.r == -1)
		return (1);
	if (parsed.ceil.g == -1)
		return (1);
	if (parsed.ceil.b == -1)
		return (1);
	return (0);
}

int			ft_parse_ceil(t_parse *parsed, char **data)
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
			if (**data != '\n' || (**data == '\n' && (parsed->ceil.r == -1
					|| parsed->ceil.b == -1 || parsed->ceil.g == -1)))
				return (1);
		if ((get_color_nb(parsed, data)) == 1)
			return (1);
	}
	if (check_empty(*parsed) == 1)
		return (1);
	return (0);
}
