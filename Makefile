NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux -g #-g yi sil

SRC = main.c\
	parser/is_valid.c\
	parser/fir_check.c


OBJS = $(SRC:.c=.o)

LIB = libft/libft.a
MLX = minilibx-linux/libmlx.a
GNL = get_next_line/get_next_line.a

MLX_FLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz

all: $(LIB) $(PRINTF) $(GNL) $(MLX) $(NAME)

$(NAME): $(OBJS) $(GNL) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(GNL) $(LIB) $(MLX_FLAGS) -o $(NAME)

$(LIB):
	$(MAKE) -C libft

$(GNL):
	$(MAKE) -C get_next_line

$(MLX):
	$(MAKE) -C minilibx-linux

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean
	$(MAKE) -C get_next_line clean
	$(MAKE) -C minilibx-linux clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	$(MAKE) -C get_next_line fclean

re: fclean all

.PHONY: all clean fclean re