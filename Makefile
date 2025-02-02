# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 15:26:50 by jtinaut-          #+#    #+#              #
#    Updated: 2024/10/30 16:56:17 by jtinaut-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
LIBFTDIR = libft/
OBJ_DIR = obj/

SRC = src/pipex.c src/pipex_utils.c

OBJ = ${SRC:.c=.o}

INCLUDE = -L ./libft -lft

%.o: %.c Makefile includes/pipex.h libft/libft.a
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

all: make_libs ${NAME}

make_libs:
	make -C $(LIBFTDIR)

${NAME}: ${OBJ}
			${CC} ${FLAGS} ${OBJ} -o ${NAME} ${INCLUDE}

clean:
		${RM} ${OBJ}
		@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
		${RM} ${NAME}
		@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re
