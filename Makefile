PARSER	= ./parser/ft_parser.c \
		./parser/get_data.c \
		./parser/ft_parse_res.c \
		./parser/ft_parse_flor.c \
		./parser/ft_parse_ceil.c \
		./parser/ft_parse_elements.c \
		./parser/ft_parse_texture.c \
		./parser/ft_parse_map.c \
		./parser/ft_parse_map2.c \
		./parser/flood_fill.c \
		./parser/walidate_back_walls.c

UTILS	= ./utils/pixel_put.c ./utils/validation.c ./utils/set_player.c ./utils/encoding_decoding_colors.c \
		./utils/get_colors.c ./utils/key_status.c ./utils/get_sprites_info.c ./utils/error_exit.c ./utils/exit_game.c \
		./utils/atoi_cub.c

BASE	= ./base/cub3d.c ./base/new_frame.c ./base/moving.c ./base/new_frame_utils.c ./base/find_ray_len.c ./base/draw_colom.c \
		./base/load_tex.c ./base/draw_floor.c ./base/draw_ceiling.c  ./base/draw_sprite.c ./base/draw_sprite_utils.c \
		./base/create_bmp.c ./base/moving_utils.c

OBJS	= $(PARSER:.c=.o) $(BASE:.c=.o) $(UTILS:.c=.o)

FLAGS	= -Wall -Wextra -Werror -g 

MLX		= libmlx.dylib

LIBFT	= ./libft/libft.a

NAME	= cub3D

%.o: %.c
	gcc $(FLAGS) $< -c -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	gcc $(FLAGS) -framework OpenGL -framework Appkit -o $(NAME) $(LIBFT) $(MLX) $(OBJS)

$(MLX):
	$(MAKE) -C minilibx_mms_20200219; \
	cd minilibx_mms_20200219; \
	mv $(MLX) ../;

$(LIBFT):
	$(MAKE) -C libft

clean:
	$(MAKE) -C libft fclean; \
	$(MAKE) -C minilibx_mms_20200219 clean; \
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(MLX)
	rm -rf first_frame.bmp

re: fclean $(NAME)

.PHONY: all clean fclean re norm

norm:
	echo LIBFT; \
	cd libft; \
	norminette *.c *.h; \
	cd ../base; \
	echo BASE; \
	norminette *.c; \
	cd ../utils; \
	echo UTILS; \
	norminette *.c; \
	cd ../parser; \
	echo PARSER; \
	norminette *.c; \
	cd ../headers; \
	echo HEADERS; \
	norminette *.h; \
