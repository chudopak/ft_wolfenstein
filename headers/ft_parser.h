#ifndef FT_PARSER_H
# define FT_PARSER_H

typedef struct		s_res {
	unsigned int	width;
	unsigned int	height;
	float			ratio;
}					t_res;

typedef struct		s_ceil {
	int				r;
	int				g;
	int				b;
}					t_ceil;

typedef struct		s_flor {
	int				r;
	int				g;
	int				b;
}					t_flor;

typedef struct		s_texture {
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
}					t_texture;

typedef struct		s_player {
	unsigned int	i;
	unsigned int	j;
	unsigned int	rows;
	unsigned int	coloms;
	char			start_angle;
}					t_player;

typedef struct		s_parse {
	t_res			res;
	t_ceil			ceil;
	t_flor			flor;
	char			**map;
	t_texture		texture;
	int				error_checker;
	t_player		p_coord;
	unsigned int	amt_spr;
}					t_parse;

t_parse				ft_parser(char *file_nm);
char				*get_data(int fd);
int					ft_parse_elements(t_parse *parsed, char **data);
int					ft_parse_ceil(t_parse *parsed, char **data);
int					ft_parse_flor(t_parse *parsed, char **data);
int					ft_parse_res(t_parse *parsed, char **data);
int					ft_parse_texture(t_parse *parsed, char **data);
int					ft_parse_map(t_parse *parsed, char **data);
void				check_for_player(t_parse *parsed, char symb, int i, int j);
void				flood_fill(char **map, int i, int j, t_parse *parsed);
void				coloms_size(t_parse *parsed, unsigned int current_str_len);
int					walidate_back_walls(char **map, t_parse *parsed);

#endif
