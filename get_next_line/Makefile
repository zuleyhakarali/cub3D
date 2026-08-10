NAME	= get_next_line.a

CC		= cc
CFLAGS	= -Wall -Werror -Wextra

SRC		= get_next_line.c get_next_line_utils.c
OBJ		= $(SRC:.c=.o)

RM		= rm -f

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re