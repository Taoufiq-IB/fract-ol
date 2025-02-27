CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = ./mandatory/fractol.c \
		./mandatory/fractol_utils.c \
		./mandatory/utils.c \
		./mandatory/mlx_destroy.c \
		./mandatory/main.c

BSRCS = ./bonus/burning_ship_bonus.c \
		./bonus/fractol_utils_bonus.c \
		./bonus/fractol_utils2_bonus.c \
		./bonus/utils_bonus.c \
		./bonus/mlx_destroy_bonus.c \
		./bonus/main_bonus.c

OBJECTS = $(SRCS:.c=.o)
B_OBJECTS = $(BSRCS:.c=.o)

NAME = fractol
BNAME = fractol_bonus

HEADER = ./mandatory/fractol.h
BHEADER = ./bonus/fractol_bonus.h

all : $(NAME) clean

bonus : $(BNAME) clean

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -Lmlx_linux -lmlx_Linux -L/home/tibarike/.local/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(BNAME): $(B_OBJECTS)
	$(CC) $(FLAGS) $(B_OBJECTS) -Lmlx_linux -lmlx_Linux -L/home/tibarike/.local/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(BNAME)

./mandatory/%.o: ./mandatory/%.c $(HEADER)
	$(CC) $(FLAGS) -I/home/tibarike/.local/include -Imlx_linux -O3 -c $< -o $@

./bonus/%.o: ./bonus/%.c $(BHEADER)
	$(CC) $(FLAGS) -I/home/tibarike/.local/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -rf $(OBJECTS) $(B_OBJECTS)

fclean: clean
	rm -rf $(NAME) $(BNAME)

re: fclean  all
