# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mspinnet <mspinnet@student.21-schoo>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/27 17:02:17 by mspinnet          #+#    #+#              #
#    Updated: 2020/11/08 13:06:47 by mspinnet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_lstadd_front.c ft_putendl_fd.c ft_strncmp.c ft_atoi.c ft_lstlast.c ft_putnbr_fd.c ft_strnstr.c ft_bzero.c ft_lstnew.c ft_putstr_fd.c ft_strrchr.c ft_calloc.c ft_lstsize.c ft_split.c ft_strtrim.c ft_isalnum.c ft_memccpy.c ft_strchr.c ft_substr.c ft_isalpha.c ft_memchr.c ft_strdup.c ft_tolower.c ft_isascii.c ft_memcmp.c ft_strjoin.c ft_toupper.c ft_isdigit.c ft_memcpy.c ft_strlcat.c ft_isprint.c ft_memmove.c ft_strlcpy.c ft_itoa.c ft_memset.c ft_strlen.c ft_lstadd_back.c ft_putchar_fd.c ft_strmapi.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS	= ${SRCS:.c=.o}

NAME	= libft.a

GCC		= gcc

CFLAGS	= -Wall -Wextra -Werror -I.

RM		= rm -f

ARRC	= ar rc

FT_H	= libft.h

all:	${NAME}

.c.o:
		${GCC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:${OBJS}
		${ARRC} ${NAME} ${OBJS}
		${ARRC} ${NAME} ${FT_H}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

bonus:	all

re:		fclean all
