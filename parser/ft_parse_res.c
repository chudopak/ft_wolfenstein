#include "../headers/overall.h"

static int	get_res(t_parse *parsed, char **data)
{
	if (parsed->res.width == 0)
	{
		(*parsed).res.width = atoi_cub(data);
		if (parsed->res.width <= 0)
			return (1);
	}
	else if (parsed->res.height == 0)
	{
		parsed->res.height = atoi_cub(data);
		if (parsed->res.height <= 0)
			return (1);
	}
	else
		return (1);
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

static int	check_empty(t_parse parsed)
{
	if (parsed.res.width == 0)
		return (1);
	if (parsed.res.height == 0)
		return (1);
	return (0);
}

static int	go_convert_res(t_parse *parsed, char **data)
{
	if ((get_res(parsed, data)) == 1)
	{
		while (**data != '\n')
		{
			if (**data != ' ')
				return (1);
			(*data)++;
		}
	}
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
		if (go_convert_res(parsed, data) == 1)
			return (1);
	}
	if (check_empty(*parsed) == 1)
		return (1);
	return (0);
}
