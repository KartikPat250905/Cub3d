#ifndef CUB3D_H
# define CUB3D_H

# include "parsing.h"
# include "libft.h"
# include "get_next_line_bonus.h"

# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include "MLX42/MLX42.h"
# include <math.h>

# define PI 3.14159265358979323846
# define WIN_WIDTH 800
# define WIN_HEIGHT 600
# define TILE_SIZE 64
# define FOV PI/3
# define PI_2 PI/2
# define DISTANCE_PROJECTION_PLANE (WIN_WIDTH / 2) / tan(FOV / 2)
# define MAX_DISTANCE (TILE_SIZE * 15)

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

typedef struct	s_dda
{
	int		tile_x;
	int		tile_y;
	float	hor_step_x;
	float	hor_step_y;
	float	vert_step_y;
	float	vert_step_x;
	float	dx;
	float	dy;
	float	distance_hor;
	float	distance_vert;
	float	hor_yn;
	float	hor_xn;
	float	vert_xn;
	float	vert_yn;
	float	min_dist;
}				t_dda;

typedef struct	s_player
{
	double x;
	double y;
	double angle;
}				t_player;

typedef struct	s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_scene		*scene;
	t_player	player;
}				t_data;

int		compress_file(t_scene *scene, char *file);
int		get_line(char **line, int fd);
t_scene	*parsing_main(char **argv);
void	trim_spaces(char **line);
void	perror_and_exit(t_scene *scene, char *str, int exit);

#endif
