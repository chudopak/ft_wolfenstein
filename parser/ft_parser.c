#include "../headers/overall.h"

static t_parse	fill_struct(void)
{
	t_parse	parsed;

	parsed.res.width = 0;
	parsed.res.height = 0;
	parsed.ceil.r = -1;
	parsed.ceil.g = -1;
	parsed.ceil.b = -1;
	parsed.flor.r = -1;
	parsed.flor.g = -1;
	parsed.flor.b = -1;
	parsed.texture.ea = NULL;
	parsed.texture.no = NULL;
	parsed.texture.s = NULL;
	parsed.texture.so = NULL;
	parsed.texture.we = NULL;
	parsed.map = NULL;
	parsed.error_checker = 0;
	parsed.p_coord.i = -1;
	parsed.p_coord.j = -1;
	parsed.p_coord.rows = -1;
	parsed.p_coord.coloms = 0;
	parsed.amt_spr = 0;
	return (parsed);
}

static void		parse(t_parse *parsed, char **data)
{
	char	*to_free;

	to_free = *data;
	if ((parsed->error_checker = ft_parse_elements(parsed, data)) == 1)
	{
		free(to_free);
		return ;
	}
	parsed->error_checker = ft_parse_map(parsed, data);
	free(to_free);
}

t_parse			ft_parser(char *file_nm)
{
	int		fd;
	char	*data;
	t_parse parsed;

	parsed = fill_struct();
	if ((fd = open(file_nm, O_RDONLY)) == -1)
	{
		parsed.error_checker = 1;
		return (parsed);
	}
	if (!(data = get_data(fd)))
	{
		parsed.error_checker = 1;
		return (parsed);
	}
	if ((close(fd)) < 0)
	{
		parsed.error_checker = 1;
		return (parsed);
	}
	parse(&parsed, &data);
	return (parsed);
}
