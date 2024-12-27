NAME = cub3D
CC = cc
INCLUDES = -Iincludes
CFLAGS = -g -Wall -Wextra -Werror
LIBFT = ./libft

SOURCES = srcs/parsing/parsing.c \
		  srcs/parsing/clean_file.c \
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