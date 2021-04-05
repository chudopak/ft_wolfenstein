#include "../headers/overall.h"

static int	check_side(char **map, int i, int j, t_parse *parsed)
{
	if (i < 0 || j < 0 || i == (int)parsed->p_coord.rows)
		return (1);
	if (map[i][j] == ' ' || map[i][j] == '\0')
		return (1);
	return (0);
}

static int	check_around(char **map, int i, int j, t_parse *parsed)
{
	if (map[i][j] == '1' || map[i][j] == ' ')
		return (0);
	if (check_side(map, i + 1, j, parsed) == 1)
		return (1);
	if (check_side(map, i - 1, j, parsed) == 1)
		return (1);
	if (check_side(map, i, j + 1, parsed) == 1)
		return (1);
	if (check_side(map, i, j - 1, parsed) == 1)
		return (1);
	return (0);
}

int			walidate_back_walls(char **map, t_parse *parsed)
{
	int		i;
	int		j;

	i = -1;
	while (++i < (int)parsed->p_coord.rows)
	{
		j = -1;
		while (map[i][++j] != '\0')
			if (check_around(map, i, j, parsed) == 1)
				return (1);
	}
	return (0);
}
