PARSER = /Users/pmarash/42/cub3d/cub3d/parser/ft_parser.c \
		/Users/pmarash/42/cub3d/cub3d/parser/get_data.c \
		/Users/pmarash/42/cub3d/cub3d/parser/ft_parse_res.c \
		/Users/pmarash/42/cub3d/cub3d/parser/ft_parse_flor.c \
		/Users/pmarash/42/cub3d/cub3d/parser/ft_parse_ceil.c \
		/Users/pmarash/42/cub3d/cub3d/parser/ft_parse_elements.c \
		/Users/pmarash/42/cub3d/cub3d/parser/ft_parse_texture.c \
		/Users/pmarash/42/cub3d/cub3d/parser/ft_parse_map.c \
		/Users/pmarash/42/cub3d/cub3d/parser/ft_parse_map2.c \
		/Users/pmarash/42/cub3d/cub3d/parser/flood_fill.c

CUB2D = ./cub2d/get_2dmap.c ./cub2d/move_player.c ./cub2d/print_map.c ./cub2d/increase_part_wall.c \
		./cub2d/player_init.c ./cub2d/auxiliary.c

UTILS = ./utils/pixel_put.c

FLAGS = -Wall -Wextra -Werror -g -framework OpenGL -framework Appkit

MLX = libmlx.dylib

LIBFT = ./libft/libft.a

NAME = cub3d

2dwindow: compile_window

$(NAME):
	$(MAKE) -C minilibx_mms_20200219; \
	cp minilibx_mms_20200219/libmlx.dylib libmlx.dylib;

$(LIBFT):
	cd libft; \
	make; \


#open empty window
compile_window: $(NAME) $(LIBFT)
	$(CC) $(FLAGS) -o $(NAME) $(LIBFT) $(MLX) $(UTILS) $(CUB2D) $(PARSER)

clean_libft:
	cd libft; \
	make fclean;

clean_all: clean_libft
	cd minilibx_mms_20200219; \
	make clean; \
	rm -rf $(NAME)