# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mspinnet <mspinnet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/19 16:24:11 by mspinnet          #+#    #+#              #
#    Updated: 2021/01/21 22:06:37 by mspinnet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= get_next_line.c get_move_utils2.c print_screen.c cub3d.c get_color.c get_move_utils.c get_move.c init_player.c main.c parser.c parser1.c parser2.c raycast_utils.c sprites.c

OBJS	= ${SRCS:.c=.o}

NAME	= cub3D

GCC		= gcc

CFLAGS	= -Wall -Wextra -Werror -I. 

RM		= rm -f

ARRC	= ar rc

LIBFT 	= make -C ./libft/

LIBMLX	= make -C ./minilibx_opengl_20191021/

FT_H	= header.h

LIB		= libft.a libmlx.a

all:	${NAME}

.c.o:
		${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:${OBJS} header.h
		${LIBFT}
		cp ./libft/libft.a .
		${LIBMLX}
		cp ./minilibx_opengl_20191021/libmlx.a .
		${GCC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIB} -framework OpenGL -framework Appkit

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}
		${RM} ${LIB}
		make fclean -C ./libft/
		make clean -C ./minilibx_opengl_20191021/
		${RM} img.bmp

bonus:	all

re:		fclean all
