#include "../headers/overall.h"

static void			char_converter(unsigned char *file_header, int value)
{
	file_header[0] = (unsigned char)value;
	file_header[1] = (unsigned char)(value >> 8);
	file_header[2] = (unsigned char)(value >> 16);
	file_header[3] = (unsigned char)(value >> 24);
}

static int			create_header(int fd, t_all *all, int file_size)
{
	int				tmp;
	int				i;
	unsigned char	file_header[54];

	i = -1;
	while (++i < 54)
		file_header[i] = (unsigned char)0;
	file_header[0] = (unsigned char)'B';
	file_header[1] = (unsigned char)'M';
	char_converter(file_header + 2, file_size);
	file_header[10] = (unsigned char)54;
	file_header[14] = (unsigned char)40;
	tmp = (int)all->parsed.res.width;
	char_converter(file_header + 18, tmp);
	tmp = (int)(-all->parsed.res.height);
	char_converter(file_header + 22, tmp);
	file_header[26] = (unsigned char)1;
	file_header[27] = (unsigned char)0;
	file_header[28] = (unsigned char)32;
	return (write(fd, file_header, 54) < 0);
}

static unsigned int	get_color(t_all *all, int width, int height)
{
	unsigned int	color;

	color = *(unsigned int*)(all->img.addr + width
			* all->img.line_length + height
			* (all->img.bits_per_pixel / 8));
	return (color);
}

static int			copy_img(int fd, t_all *all)
{
	int				i;
	int				j;
	unsigned int	color;

	i = -1;
	while (++i < (int)all->parsed.res.height)
	{
		j = -1;
		while (++j < (int)all->parsed.res.width)
		{
			color = get_color(all, i, j);
			if (write(fd, &color, 4) < 0)
				return (1);
		}
	}
	return (0);
}

int					create_bmp(t_all *all)
{
	int		file_size;
	int		fd;

	if ((fd = open("first_frame.bmp", O_WRONLY
			| O_CREAT | O_APPEND | O_TRUNC, S_IRUSR | S_IWUSR)) < 0)
		return (1);
	draw_new_frame(all);
	file_size = 54 + ((int)all->parsed.res.width * 4
			* (int)all->parsed.res.height);
	if ((create_header(fd, all, file_size)) == 1)
		return (1);
	if ((copy_img(fd, all)) == 1)
		return (1);
	close(fd);
	return (0);
}
