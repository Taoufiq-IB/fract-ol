NAME = fractol

SRC = src/main.c src/mandelbrot.c src/events.c src/utils.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
    $(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

clean:
    rm -f $(OBJ)

fclean: clean
    rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re