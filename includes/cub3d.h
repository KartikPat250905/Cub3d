#ifndef CUB3D_H
# define CUB3D_H

# include "parsing.h"
# include "libft.h"
# include "get_next_line_bonus.h"

# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>

typedef enum	e_type
{
	PARSE_UNKNOWN = 0,
	PARSE_NORTH,
	PARSE_SOUTH,
	PARSE_WEST,
	PARSE_EAST,
	PARSE_FLOOR,
	PARSE_CEILING,
	PARSE_MAP,
}		t_etype;

int		compress_file(t_scene *scene, char *file);
int		get_line(char **line, int fd);
t_scene	*parsing_main(char **argv);
void	trim_spaces(char **line);

#endif
