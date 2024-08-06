# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpellegr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/05 15:26:45 by lpellegr          #+#    #+#              #
#    Updated: 2024/06/28 17:34:35 by lpellegr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#*********************** LPELLEGR PIPEX MAKEFILE ******************************#

# **************************************************************************** #
#                                   CONFIG                                     #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = pipex


# **************************************************************************** #
#                                   FILES                                      #
# **************************************************************************** #

MAIN		=	main.c

SRC			= 	error_utils.c ft_split.c get_next_line_utils.c get_next_line.c \
			 	parsing_utils.c string_utils.c sys_utils.c

# SRC_BONUS = 

# **************************************************************************** #
#                                   PATH                                       #
# **************************************************************************** #

SRC_DIR		= src/
OBJ_DIR		= obj/
INCLUDE_DIR	= ./include/

SRCS		= $(addprefix $(SRC_DIR), $(SRC))
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_DIR), $(OBJ))

OBJ_MAIN  	= $(MAIN:.c=.o)
OBJS_MAIN	= $(addprefix $(OBJ_DIR), $(OBJ_MAIN))

# **************************************************************************** #
#                                   COLOR RULES                                #
# **************************************************************************** #

COLOR_BLUE = \033[0;34m
COLOR_GREEN = \033[0;32m
NO_COLOR = \033[m

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all:	$(NAME)

#bonus:	$(NAME_BONUS)

$(NAME):	$(OBJS) $(OBJS_MAIN)
	@$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -o $@ $(OBJS) $(OBJS_MAIN)
	@printf "$(COLOR_BLUE)pipex compilation done: [✓]$(NO_COLOR)\n"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@${CC} ${CFLAGS} -c $< -o $@ -I $(INCLUDE_DIR)

$(OBJ_DIR)%.o: $(MAIN)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	@rm -rf $(OBJ_DIR)
	@printf "$(COLOR_GREEN)clean: [✓]$(NO_COLOR)\n"

fclean: clean
	@rm -rf $(NAME) $(NAME_BONUS)
	@printf "$(COLOR_GREEN)fclean: [✓]$(NO_COLOR)\n"

re: fclean all

.PHONY: all bonus clean fclean re
