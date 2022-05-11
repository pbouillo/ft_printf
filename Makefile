# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbouillo <pbouillo@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 13:32:18 by pbouillo          #+#    #+#              #
#    Updated: 2022/05/11 13:46:06 by pbouillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a

SRCS 		= 


CC 			= cc
CFLAGS	 	= -Wall -Werror -Wextra
RM 			= rm -rf
LIBFTPATH 	= ./libft/
LIBFTFLAGS 	= -Ilibft -Llibft
LIBFTA 		= libft/libft.a
OBJS 		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	ar -rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) !$(NAME)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus