NAME		= cub3D

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a

MLX_DIR		= minilibx-linux
MLX_LIB		= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

GNL_DIR		= get_next_line
GNL_SRCS	= $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

PARSER_DIR	= parser
PARSER_SRCS	= $(wildcard $(PARSER_DIR)/*.c)

EXEC_DIR	= executor
EXEC_SRCS	= $(wildcard $(EXEC_DIR)/*.c)

SRCS		= main.c $(PARSER_SRCS) $(EXEC_SRCS) $(GNL_SRCS)
OBJS		= $(SRCS:.c=.o)

INCLUDES	= -I. -I$(LIBFT_DIR) -I$(GNL_DIR) -I$(MLX_DIR)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)/libft.a $(MLX_FLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean

re: fclean all

.PHONY: all clean fclean re