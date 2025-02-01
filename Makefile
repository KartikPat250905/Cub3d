NAME = cub3D
CC = cc
INCLUDES = -Iincludes -I $(MLX)/include
CFLAGS = -Wall -Wextra -Werror
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
		  srcs/main.c \
		  srcs/raytracing.c \
		  srcs/game_initialization.c \
		  srcs/key_hook.c \
		  srcs/movement.c \
		  srcs/drawing_utils.c \
		  srcs/drawing_utils2.c

OBJECTS = $(SOURCES:.c=.o)
DEPENDS = $(OBJECTS:.o=.d)

all: $(NAME)

$(LIBFT)/libft.a:
	make -C $(LIBFT)
	touch $(LIBFT)/libft.a

$(NAME): $(OBJECTS) $(LIBFT)/libft.a $(LIBMLX)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT)/libft.a $(LIBS) -o $(NAME)

$(LIBMLX): mlx_clone
	@if [ ! -f "$(LIBMLX)" ]; then \
		cmake -B $(MLX)/build $(MLX); \
		make -C $(MLX)/build -j4; \
	fi

%.o: %.c $(LIBMLX)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	rm -f $(OBJECTS) $(DEPENDS)
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

-include $(DEPENDS)

.PHONY: all clean fclean re mlx_clone
