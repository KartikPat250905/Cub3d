NAME = cub3D
CC = cc
INCLUDES = -Iincludes -I $(MLX)/include
CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address
#CFLAGS = -g
LIBFT = ./libft

# MLX
LIBMLX		:=	MLX42/build/libmlx42.a
MLX		:=	./MLX42
LIBS            :=  $(LIBMLX) -ldl -lglfw -pthread -lm

SOURCES = srcs/parsing/parsing.c \
		  srcs/parsing/clean_file.c \
		  srcs/parsing/fill_data.c \
		  srcs/parsing/parse_textures.c \
		  srcs/parsing/parse_colors.c \
		  srcs/parsing/parse_map.c \
		  srcs/parsing/parse_map_utils.c \
		  srcs/parsing/parse_utils.c \
		  srcs/free/free_parsing.c \
		  srcs/free/free_textures.c \
		  srcs/free/error.c \
		  srcs/game_init_utils.c \
		  main2.c \
		  srcs/game_initialization.c \
		  srcs/key_hook.c \
		  srcs/movement.c \
		  srcs/drawing_utils.c

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(LIBFT)/libft.a:
	make -C $(LIBFT)

$(NAME): $(OBJECTS) $(LIBFT)/libft.a $(LIBMLX)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT)/libft.a $(LIBS) -o $(NAME)

$(LIBMLX): mlx_clone
	@if [ ! -f "$(LIBMLX)" ]; then \
		cmake $(MLX) -B $(MLX)/build && make -C $(MLX)/build -j4; \
	fi

%.o: %.c mlx_clone
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	rm -f $(OBJECTS)
	make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean
	@rm -rf $(MLX)/build

re: fclean all

mlx_clone:
	@if [ ! -d "$(MLX)" ]; then \
		git clone https://github.com/codam-coding-college/MLX42.git $(MLX); \
	fi

.PHONY: all clean fclean re mlx_clone

