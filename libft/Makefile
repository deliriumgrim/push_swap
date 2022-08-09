# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drumfred <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/26 16:49:33 by drumfred          #+#    #+#              #
#    Updated: 2021/10/26 18:34:19 by drumfred         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	libft.a

LIST 	=	ft_atoi.c		ft_bzero.c		ft_calloc.c\
			ft_isalnum.c	ft_isalpha.c	ft_isascii.c\
			ft_isdigit.c	ft_isprint.c	ft_itoa.c\
			ft_memchr.c		ft_memcmp.c		ft_memcpy.c\
			ft_memmove.c	ft_memset.c		ft_putchar_fd.c\
			ft_putendl_fd.c	ft_putnbr_fd.c	ft_putstr_fd.c\
			ft_split.c		ft_strchr.c		ft_strdup.c\
			ft_striteri.c	ft_strjoin.c	ft_strlcat.c\
			ft_strlcpy.c	ft_strlen.c		ft_strmapi.c\
			ft_strncmp.c	ft_strnstr.c	ft_strrchr.c\
			ft_strtrim.c	ft_substr.c		ft_tolower.c\
			ft_toupper.c	get_next_line.c

HEADER	=	libft.h
OBJ		=	$(LIST:%.c=%.o)


CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

.PHONY	:	all clean fclean re bonus

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	ar rcs	$(NAME)	$?

%.o		:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean	:
	rm -rf $(OBJ) $(OBJ_B)

fclean	:	clean
	rm -rf $(NAME)

re		:	fclean all
