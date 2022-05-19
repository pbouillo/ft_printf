# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbouillo <pbouillo@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 13:32:18 by pbouillo          #+#    #+#              #
#    Updated: 2022/05/19 15:17:01 by pbouillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a

SRCS 		= ft_printf.c utils.c


CC 			= cc
CFLAGS	 	= -Wall -Werror -Wextra
RM 			= rm -rf
LIBFTPATH 	= ./libft/
LIBFTFLAGS 	= -Ilibft -Llibft -lft
LIBFTA 		= libft/libft.a
OBJS 		= $(SRCS:.c=.o)

all: $(NAME)

libfta:
	$(MAKE) -C $(LIBFTPATH)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	ar -rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) !$(NAME)
	$(MAKE) -C $(LIBFTPATH) clean

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTPATH) fclean

re:	fclean all

.PHONY: all clean fclean re bonus