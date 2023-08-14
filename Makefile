NAME = cub3d

SRCS = $(addprefix src/, main.c init.c map.c utils.c utils_2.c ray.c textures.c params.c validate.c draw.c controller.c controller_2.c cub3d.c gnl/get_next_line.c gnl/get_next_line_utils.c)

OBJS = $(SRCS:.c=.o)

LINUX_FRAEMWORKS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm
MACOS_FRAMEWORKS = -Lmlx -lmlx -framework OpenGL -framework AppKit

FLAGS = 

LIBFT = libft/libft.a

.PHONY: all clean fclean re

all: $(LIBFT) $(NAME)

%.o: %.c Makefile
	cc $(FLAGS) -c -Iincludes $< -o $@ 

$(NAME): $(OBJS) includes/cub3d.h
	cc $(FLAGS) $(OBJS) $(LIBFT) $(MACOS_FRAMEWORKS) -o $(NAME)

$(LIBFT):
	make -s -C libft/

clean:
	make -s -C libft/ clean
	rm -rf $(OBJS)

fclean: clean
	make -s -C libft/ fclean
	rm -rf $(NAME)

re: fclean all