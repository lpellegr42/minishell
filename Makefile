NAME = minishell
DIR_SRC = src/
DIR_OBJ = obj/
CC = cc 
CFLAGS = -Wall -Wextra -Werror -ggdb
LDFLAGS = -lreadline
RM = rm -f

SRCS =  $(wildcard $(DIR_SRC)*.c) \
		$(wildcard $(DIR_SRC)/exec/*.c) \
		$(wildcard $(DIR_SRC)/builtins/*.c) \
		$(wildcard $(DIR_SRC)/env/*.c) \
		$(wildcard $(DIR_SRC)/parsing/*.c) \
		$(wildcard $(DIR_SRC)/utils/*.c) \
		$(wildcard $(DIR_SRC)/temp/*.c) \

OBJS = $(SRCS:$(DIR_SRC)%.c=$(DIR_OBJ)%.o)

all: $(NAME)
	@clear

$(DIR_OBJ)%.o: $(DIR_SRC)%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	rm -rf $(DIR_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all