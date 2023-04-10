# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 15:36:43 by junhyupa          #+#    #+#              #
#    Updated: 2023/04/11 03:24:14 by junhyupa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Werror -Wextra -Wall #-g -fsanitize=thread

SRC = main.c init.c philosophers.c util.c free.c monitor.c

SRCS = $(SRC)

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY : all clean fclean re
