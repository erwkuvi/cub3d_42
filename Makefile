# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekuchel <ekuchel@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/27 13:12:42 by ekuchel           #+#    #+#              #
#    Updated: 2023/11/27 16:51:12 by ekuchel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S = ./src/
HDRS_DIR = ./includes/
LIBFT_DIR	= ./lib/libft/
LIBMLX_DIR = ./lib/minilibx/

NAME = cub3d

SRC = $(S)main.c

# List of object files derived from the source files
OBJ = $(SRC:.c=.o)

HDRS = -I$(HDRS_DIR)
LIBS =	-L$(LIBFT_DIR) -L$(LIBMLX_DIR)
CC = @gcc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -fsanitize=address -g  -framework OpenGL -framework Appkit
RM = /bin/rm -f
RMDIR = /bin/rmdir

#-fsanitize=undefined
#-fsanitize=memory
#-fsanitize=thread

LIBFT = $(LIBFT_DIR)libft.a
LIBMLX = $(LIBMLX_DIR)libmlx.a

define ASCII_ART
                                   .--,-``-.
                                  /   /     '.
                         ,---,   / ../        ;       ,---,
                   ,--,,---.'|   \ ``\  .`-    '    ,---.'|
                 ,'_ /||   | :    \___\/   \   :    |   | :
   ,---.    .--. |  | ::   : :         \   :   |    |   | |
  /     \ ,'_ /| :  . |:     |,-.      /  /   /   ,--.__| |
 /    / ' |  ' | |  . .|   : '  |      \  \   \  /   ,'   |
.    ' /  |  | ' |  | ||   |  / :  ___ /   :   |.   '  /  |
'   ; :__ :  | : ;  ; |'   : |: | /   /\   /   :'   ; |:  |
'   | '.'|'  :  `--'   \   | '/ :/ ,,/  ',-    .|   | '/  '
|   :    ::  ,      .-./   :    |\ ''\        ; |   :    :|
 \   \  /  `--`----'   /    \  /  \   \     .'   \   \  /
  `----'               `-'----'    `--`-,,-'      `----'


endef
export ASCII_ART

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RESET = \033[0m
BANNER_CUB3D = @echo "$$ASCII_ART"

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ)
	@echo "$(RED)";
	$(BANNER_CUB3D)
	@echo "$(GREEN)Cub3d Done!$(RESET)";
	$(CC) $(CFLAGS) $(LIBS) $(LDFLAGS) $(HDRS) $^ -o $@

$(LIBFT):
	make -s -C $(LIBFT_DIR)

$(LIBMLX):
	make -s -C $(LIBMLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(HDRS) -c $< -o $@

#run : $(NAME)
#./$(NAME) 4 410 200 200

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(LIBMLX_DIR)
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f $(NAME)
	@echo "$(BLUE)Cleaning cub3d... $(RESET)";

re: fclean all

git: fclean
	git add ./
	git commit -m "$m"
	git push

.PHONY: all clean fclean re run git
