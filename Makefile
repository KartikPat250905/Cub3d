NAME = cub3D
CC = cc
INCLUDES = -Iincludes
CFLAGS = -g -Wall -Wextra -Werror
LIBFT = ./libft

SOURCES = srcs/parsing/parsing.c \
		  srcs/parsing/clean_file.c \
		  srcs/parsing/fill_data.c \
		  srcs/parsing/parse_textures.c \
		  srcs/parsing/parse_colors.c \
		  srcs/parsing/parse_map.c \
		  srcs/parsing/parse_utils.c \
		  srcs/free/free_parsing.c \
		  srcs/free/error.c \
		  main.c \

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(LIBFT)/libft.a:
	make -C $(LIBFT)

$(NAME): $(OBJECTS) $(LIBFT)/libft.a
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT)/libft.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	rm -f $(OBJECTS)
	make -C $(LIBFT) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re
