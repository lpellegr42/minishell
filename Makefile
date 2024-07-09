#***************** LIVSAUZE AND LPELLEGR MINISHELL'S MAKEFILE *****************#

# **************************************************************************** #
#                                   CONFIG                                     #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = minishell

# **************************************************************************** #
#                                   FILES                                      #
# **************************************************************************** #

MAIN	=	main.c

SRC		= 	utils_libft.c

# **************************************************************************** #
#                                   PATH                                       #
# **************************************************************************** #

SRC_DIR		= srcs/
OBJ_DIR		= objs/
INCLUDE_DIR	= ./includes/

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

$(NAME):	$(OBJS) $(OBJS_MAIN)
	@$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -o $@ $(OBJS) $(OBJS_MAIN)
	@printf "$(COLOR_BLUE)minishell compilation done: [✓]$(NO_COLOR)\n"

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
