# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbouillo <pbouillo@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 13:32:18 by pbouillo          #+#    #+#              #
#    Updated: 2022/06/04 20:24:23 by pbouillo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	libftprintf.a

SRCS 		= 	$(wildcard ./*c)


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