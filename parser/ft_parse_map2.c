#include "../headers/overall.h"

void	check_for_player(t_parse *parsed, char symb, int i, int j)
{
	if (symb == 'N' || symb == 'W' || symb == 'S' || symb == 'E')
	{
		parsed->p_coord.i = i;
		parsed->p_coord.j = j;
		parsed->p_coord.start_angle = symb;
	}
}

void	coloms_size(t_parse *parsed, unsigned int current_str_len)
{
	if (parsed->p_coord.coloms < current_str_len)
		parsed->p_coord.coloms = current_str_len;
}
