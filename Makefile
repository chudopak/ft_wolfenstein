PARSER = ./parser/ft_parser.c \
		./parser/get_data.c \
		./parser/ft_parse_res.c \
		./parser/ft_parse_flor.c \
		./parser/ft_parse_ceil.c \
		./parser/ft_parse_elements.c \
		./parser/ft_parse_texture.c \
		./parser/ft_parse_map.c \
		./parser/ft_parse_map2.c \
		./parser/flood_fill.c

CUB2D = ./cub2d/get_2dmap.c ./cub2d/move_player.c ./cub2d/print_map.c ./cub2d/increase_part_wall.c \
		./cub2d/player_init.c ./cub2d/auxiliary.c

UTILS = ./utils/pixel_put.c ./utils/validation.c

BASE = ./base/cub3d.c

FLAGS = -Wall -Wextra -Werror -g -framework OpenGL -framework Appkit

MLX = libmlx.dylib

LIBFT = ./libft/libft.a

NAME = cub3d

all: start_game

start_game: compile_all

compile_all: $(NAME) $(LIBFT)
	$(CC) $(FLAGS) -o $(NAME) $(LIBFT) $(MLX) $(UTILS) $(BASE) $(PARSER)

2dwindow: compile_window

$(NAME):
	$(MAKE) -C minilibx_mms_20200219; \
	cp minilibx_mms_20200219/libmlx.dylib libmlx.dylib;

$(LIBFT):
	cd libft; \
	make; \

compile_window: $(NAME) $(LIBFT)
	$(CC) $(FLAGS) -o $(NAME) $(LIBFT) $(MLX) $(UTILS) $(CUB2D) $(PARSER)

clean_libft:
	cd libft; \
	make fclean;

clean_all: clean_libft
	cd minilibx_mms_20200219; \
	make clean; \
	rm -rf $(NAME)