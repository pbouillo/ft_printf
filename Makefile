# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbouillo <pbouillo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 13:32:18 by pbouillo          #+#    #+#              #
#    Updated: 2022/05/31 10:57:11 by pbouillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	libftprintf.a

SRCS 		= 	ft_printf.c ft_print_chars.c ft_print_hexa.c \
				ft_print_numbers.c ft_print_ptr.c


CC 			=	cc
CFLAGS	 	=	-Wall -Werror -Wextra
RM 			=	rm -rf
OBJS 		=	$(SRCS:.c=.o)

all: 			$(NAME)

$(NAME):
				$(CC) $(CFLAGS) -c $(SRCS)
				ar -rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) !$(NAME)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY: 		all clean fclean re