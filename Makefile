NAME	= so_long

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf
LIBFT_DIR = libft
LIBFT	= $(LIBFT_DIR)/libft.a

SRC		= mandatory/so_long.c \
		  mandatory/check_map.c \
		  mandatory/errors.c \
		  mandatory/close.c \
		  mandatory/flood_fil.c \
		  mandatory/get_map.c \
		  mandatory/lunch_game.c \
		  mandatory/parsing.c \
		  mandatory/run_game.c \
		  get_next_line/get_next_line.c \
		  get_next_line/get_next_line_utils.c
OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "WOOW.. so_long is compiled successfully 🎉"

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c so_long.h
		@$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	@$(RM) $(OBJ)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean