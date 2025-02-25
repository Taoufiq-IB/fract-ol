CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = fractol.c \
		fractol_utils.c \
		utils.c \
		mlx_destroy.c \
		main.c

OBJECTS = $(SRCS:.c=.o)
NAME = fractol
HEADER = fractol.h

all : $(NAME)

bonus : $(NAME_BON)

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -Lmlx_linux -lmlx_Linux -L/home/tibarike/.local/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -I/home/tibarike/.local/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -rf $(OBJECTS)
fclean: clean
	rm -rf $(NAME)

re: fclean  all