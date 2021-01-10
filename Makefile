# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/04 14:17:10 by ksano             #+#    #+#              #
#    Updated: 2021/01/10 17:51:12 by ksano            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
SDIR	= ./
FILES	=\
		ft_printf.c init_args.c ft_get_digits.c ft_put_c.c ft_put_conversion.c \
		ft_get_conversion.c ft_get_width.c read_args.c ft_put_s.c \
		ft_get_precision.c ft_get_flag.c ft_put_d.c ft_put_p.c \
		ft_put_percent.c ft_putchar_zero_filling.c ft_putchar_align_left.c \
		ft_put_u.c ft_put_x.c
SOURCES = $(addprefix $(SDIR), $(FILES))
OBJECTS = ${SOURCES:.c=.o}
RM		= rm -rf
AR		= ar rcs
CC		= gcc
INCLUDES= -I includes
CFLAGS	= -Wall -Wextra -Werror $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rc $@ $^

clean:
	$(RM) $(OBJECTS) libft/*.o

fclean:
	$(RM) $(OBJECTS) $(NAME) libft/libft.a libft/*.o

re: fclean all

.PHONY:
	all clean fclean re

