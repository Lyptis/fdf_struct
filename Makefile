# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 13:22:21 by svanmeen          #+#    #+#              #
#    Updated: 2023/04/17 11:40:18 by svanmeen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.c		input.c		colors.c	parse.c		fdf.c		utils.c		memory.c	draw.c		calc.c
HSRC	=	fdf.h
OBJS	=	${SRCS:.c=.o}

NAME	= fdf

GCC		= gcc
RM		= rm -f
FLAGS	= -Wall -Wextra -Werror

%.o: %.c	${HSRC}
			${GCC} ${FLAGS} -c $< -o $@

${NAME}:	${OBJS} ${HSRC}
			make -C libft
			make -w -C minilibx
			${GCC} -o ${NAME} ${OBJS} -L libft -lft -L minilibx -lmlx_Linux -L /usr/include/../lib -lXext -lX11 -lm

all:		${NAME}

clean:
			make clean -C libft
			${RM} ${OBJS}
			${RM} ${HSRC}.gch

fclean:		clean
			make clean -C minilibx
			make fclean -C libft
			${RM} ${NAME}

re:			fclean all
