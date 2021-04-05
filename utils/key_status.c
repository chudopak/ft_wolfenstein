#include "../headers/overall.h"

int		key_pressed(int keycode, t_all *all)
{
	if (keycode == 53)
		exit_game(all);
	if (keycode == 13)
		all->key.w = 1;
	else if (keycode == 0)
		all->key.a = 1;
	else if (keycode == 1)
		all->key.s = 1;
	else if (keycode == 2)
		all->key.d = 1;
	else if (keycode == 124)
		all->key.right = 1;
	else if (keycode == 123)
		all->key.left = 1;
	return (0);
}

int		key_released(int keycode, t_all *all)
{
	if (keycode == 13)
		all->key.w = 0;
	else if (keycode == 0)
		all->key.a = 0;
	else if (keycode == 1)
		all->key.s = 0;
	else if (keycode == 2)
		all->key.d = 0;
	else if (keycode == 124)
		all->key.right = 0;
	else if (keycode == 123)
		all->key.left = 0;
	return (0);
}
