# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vfurmane <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/18 15:11:46 by vfurmane          #+#    #+#              #
#    Updated: 2020/09/18 19:35:08 by vfurmane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= main.c ../parser.c ../put.c
INCL		= ..
OBJS		= $(SRCS:.c=.o)
NAME		= insertion-sort
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@ -I $(INCL)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
