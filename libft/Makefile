# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 14:27:36 by svanmeen          #+#    #+#              #
#    Updated: 2023/02/23 15:04:30 by svanmeen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isascii.c	ft_isprint.c	ft_strlen.c		\
			ft_bzero.c		ft_memcpy.c		ft_strlcpy.c	ft_strlcat.c	ft_toupper.c	ft_tolower.c	\
			ft_strchr.c		ft_strrchr.c	ft_strncmp.c	ft_memchr.c		ft_strnstr.c	ft_memcmp.c		\
			ft_memset.c		ft_memmove.c	ft_atoi.c		ft_calloc.c		ft_strdup.c		ft_substr.c		\
			ft_strjoin.c	ft_strtrim.c	ft_split.c		ft_itoa.c		ft_putchar_fd.c	ft_putstr_fd.c	\
			ft_putendl_fd.c	ft_putnbr_fd.c	ft_strmapi.c	ft_striteri.c	get_next_line.c					\
			get_next_line_utils.c	utils_printf.c	ft_printf.c	ft_printf_hex.c
HSRC	= libft.h
OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

GCC		= gcc
RM		= rm -f
LIB		= ar rcs
FLAGS	= -Wall -Wextra -Werror

%.o: %.c	${HSRC}
			${GCC} ${FLAGS} -c $< -o $@

${NAME}:	${OBJS} ${HSRC}
			${LIB} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}
			${RM} ${HSRC}.gch

fclean:		clean
			${RM} ${NAME}

re:			fclean all
