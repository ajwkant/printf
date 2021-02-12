# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: akant <akant@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/12 13:53:25 by akant         #+#    #+#                  #
#    Updated: 2021/02/04 13:44:06 by akant         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c convert_char.c convert_hex.c convert_int.c \
		convert_percentage.c convert_pointer.c convert_string.c \
		convert_unsigned.c itoa.c utils.c

HEADER_FILES = printf.h
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:%.c=%.o)
LIBFTLIBRARY = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	ar -rcs $(NAME) $(OBJS) $(LIBFTLIBRARY)
	ar -q $(LIBFTLIBRARY) $(OBJS)
	cp $(LIBFTLIBRARY) $(NAME)

%.o: %.c $(HEADER_FILES)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJS)
	$(MAKE) -C ./libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
