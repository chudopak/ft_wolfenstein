# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmarash <pmarash@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/01 14:02:43 by pmarash           #+#    #+#              #
#    Updated: 2021/03/09 17:25:34 by pmarash          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c ft_bzero.c ft_memcpy.c ft_memset.c ft_strlen.c ft_memccpy.c ft_calloc.c ft_memchr.c \
	  ft_memmove.c ft_memcmp.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c \
	  ft_itoa.c ft_strnstr.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putchar.c ft_putstr.c ft_putnbr.c \
	  ft_strcpy.c ft_putnbr_u.c ft_nblen_u.c ft_puthex.c ft_puthex_long.c ft_strcpy.c join_free.c ft_nblen.c \
	  ft_atoi_dbl_ptr.c

OBG = ft_atoi.o ft_bzero.o ft_memcpy.o ft_memset.o ft_strlen.o ft_memccpy.o ft_calloc.o ft_memchr.o \
	  ft_memmove.o ft_memcmp.o ft_isalpha.o ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o \
	  ft_toupper.o ft_tolower.o ft_strchr.o ft_strrchr.o ft_strncmp.o ft_strlcpy.o ft_strlcat.o \
	  ft_itoa.o ft_strnstr.o ft_strdup.o ft_substr.o ft_strjoin.o ft_strtrim.o ft_split.o ft_strmapi.o \
	  ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_putchar.o ft_putstr.o ft_putnbr.o ft_strcpy.o \
	  ft_putnbr_u.o ft_nblen_u.o ft_puthex.o ft_puthex_long.o ft_strcpy.o join_free.o ft_nblen.o \
	  ft_atoi_dbl_ptr.o

SRCBONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBGBONUS = ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o ft_lstiter.o ft_lstmap.o

FLAGS = -Wall -Wextra -Werror

LIBA = libft.a

NAME = libft.a

all: $(NAME)

%.o: %.c
	gcc $(FLAGS) $< -c

bonus: $(OBGBONUS)
	gcc $(FLAGS) -c $(SRCBONUS)
	ar rc $(LIBA) $(OBGBONUS)

$(NAME): $(OBG)
	gcc $(FLAGS) -c $(SRC)
	ar rc  $(LIBA) $(OBG)

clean:
	rm -rf $(OBG) $(OBGBONUS)

fclean: clean
	rm -rf $(LIBA)

re: fclean all
