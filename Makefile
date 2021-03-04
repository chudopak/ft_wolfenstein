PARSER	= ./parser/ft_parser.c \
		./parser/get_data.c \
		./parser/ft_parse_res.c \
		./parser/ft_parse_flor.c \
		./parser/ft_parse_ceil.c \
		./parser/ft_parse_elements.c \
		./parser/ft_parse_texture.c \
		./parser/ft_parse_map.c \
		./parser/ft_parse_map2.c \
		./parser/flood_fill.c

CUB2D	= ./cub2d/get_2dmap.c ./cub2d/move_player.c ./cub2d/print_map.c ./cub2d/increase_part_wall.c \
		./cub2d/player_init.c ./cub2d/auxiliary.c

UTILS	= ./utils/pixel_put.c ./utils/validation.c ./utils/set_player.c ./utils/encoding_decoding_colors.c \
		./utils/get_colors.c ./utils/key_status.c ./utils/get_sprites_info.c

BASE	= ./base/cub3d.c ./base/new_frame.c ./base/moving.c ./base/new_frame_utils.c ./base/find_ray_len.c ./base/draw_colom.c \
		./base/load_tex.c ./base/draw_floor.c ./base/draw_ceiling.c  ./base/draw_sprite.c ./base/draw_sprite_utils.c

OBJS	= $(PARSER:.c=.o) $(BASE:.c=.o) $(UTILS:.c=.o)

FLAGS	= -Wall -Wextra -Werror -g -framework OpenGL -framework Appkit

MLX		= libmlx.dylib

LIBFT	= ./libft/libft.a

NAME	= cub3d

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(LIBFT) $(MLX) $(UTILS) $(BASE) $(PARSER)

$(MLX):
	$(MAKE) -C minilibx_mms_20200219; \
	cd minilibx_mms_20200219; \
	mv $(MLX) ../;

$(LIBFT):
	$(MAKE) -C libft

compile_window: $(NAME) $(LIBFT)
	$(CC) $(FLAGS) -o $(NAME) $(LIBFT) $(MLX) $(UTILS) $(CUB2D) $(PARSER)

clean:
	$(MAKE) -C libft fclean; \
	$(MAKE) -C minilibx_mms_20200219; \
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(MLX)

re: fclean $(NAME)

.PHONY: all clean fclean re