# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekuchel <ekuchel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 13:28:25 by ekuchel           #+#    #+#              #
#    Updated: 2023/10/05 15:54:56 by ekuchel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = \
	file/ft_putchar_fd.c \
	file/ft_putendl_fd.c \
	file/ft_putnbr_fd.c \
	file/ft_putstr_fd.c \
	\
	lst/ft_lstadd_back.c \
	lst/ft_lstadd_front.c \
	lst/ft_lstclear.c \
	lst/ft_lstdelone.c \
	lst/ft_lstlast.c \
	lst/ft_lstnew.c \
	lst/ft_lstsize.c \
	lst/ft_lstiter.c \
	lst/ft_lstmap.c \
	\
	mem/ft_memset.c \
	mem/ft_bzero.c \
	mem/ft_calloc.c \
	mem/ft_memchr.c \
	mem/ft_memcmp.c \
	mem/ft_memcpy.c \
	mem/ft_memmove.c \
	\
	nbr/ft_itoa.c \
	nbr/ft_atoi.c \
	\
	others/ft_isprint.c \
	others/ft_isdigit.c \
	others/ft_isalnum.c \
	others/ft_isalpha.c \
	others/ft_isascii.c \
	\
	str/ft_strjoin.c \
	str/ft_strdup.c \
	str/ft_tolower.c \
	str/ft_strtrim.c \
	str/ft_strlcat.c \
	str/ft_substr.c \
	str/ft_strlcpy.c \
	str/ft_strlen.c \
	str/ft_toupper.c \
	str/ft_strmapi.c \
	str/ft_split.c \
	str/ft_strncmp.c \
	str/ft_strchr.c \
	str/ft_strrchr.c \
	str/ft_strnstr.c \
	str/ft_striteri.c \
	\
	gnl/get_next_line_bonus.c\
	gnl/get_next_line_utils_bonus.c\
	\
	ftprintf/ft_check.c \
	ftprintf/ft_printf.c \
	ftprintf/ft_format.c \
	ftprintf/ft_printfc.c \
	ftprintf/ft_printfs.c \
	ftprintf/ft_printfd.c \
	ftprintf/ft_printfu.c \
	ftprintf/ft_printfx.c \
	ftprintf/ft_printfp.c

SRC_OBJ = $(SRC:.c=.o)

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = ar rcs
RM = rm -f

all: $(NAME)

$(NAME): $(SRC_OBJ)
	$(LIB) $(NAME) $(SRC_OBJ)

clean:
	$(RM) $(SRC_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
