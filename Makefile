# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ialdidi <ialdidi@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 08:50:47 by ialdidi           #+#    #+#              #
#    Updated: 2023/11/19 07:43:40 by ialdidi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS	= ft_putchar.c ft_putstr.c ft_printf.c ft_putnbr_base.c ft_print_address.c

OBJS	= $(SRCS:.c=.o)

AR 		= ar rc

CFLAGS	= -Wall -Wextra -Werror

NAME 	= libftprintf.a

all		:	$(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o		: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean	:
	$(RM) $(OBJS)
	
fclean:			clean
	@$(RM) $(NAME) $(OBJS)
				
re:				fclean all
	
	