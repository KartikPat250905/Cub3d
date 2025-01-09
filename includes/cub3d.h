/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:46:15 by motuomin          #+#    #+#             */
/*   Updated: 2025/01/09 15:13:46 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// -- Includes --

// Libraries
#include <fcntl.h>        // open
#include <unistd.h>       // close, read, write
#include <stdio.h>        // printf, perror
#include <stdlib.h>       // malloc, free, exit
#include <string.h>       // strerror
#include <sys/time.h>     // gettimeofday
#include <math.h>         // All functions of the math library

// Header files
# include "parsing.h"
# include "libft.h"
# include "get_next_line_bonus.h"
# include "../MLX42/include/MLX42/MLX42.h"

// -- TYPEDEFS --

typedef enum e_dir
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}	t_dir;

typedef struct s_draw
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	tex_y;
	int	tex_x;
	int	color;
	mlx_image_t *texture;
} t_draw;

typedef struct s_mlx
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*t_n;
	mlx_image_t	*t_s;
	mlx_image_t	*t_e;
	mlx_image_t	*t_w;
	t_scene	s;
}			t_mlx;

typedef struct s_ray
{
	// X-coordinate in camera space (-1 to 1)
	float	cam_x;

	// Direction of ray
	float	dir_x;
	float	dir_y;

	// coordinates on map grid
	int	map_x;
	int	map_y;

	// Distance to first grid sides
	float	s_dist_x;
	float	s_dist_y;

	// Distance to the next grid sides
	float	d_dist_x;
	float	d_dist_y;

	// Length of the ray
	float	p_dist;

	// Neg or pos direction
	int	step_x;
	int	step_y;

	// If a wall was hit
	int	hit;

	// x-side or y-side
	int	side;

}	t_ray;

typedef struct s_player
{
	// Player's position coordinates
	float	pos_x;
	float	pos_y;

	// The position in front of the player
	float	dir_x;
	float	dir_y;

	// The camera plane (determines FOV)
	float	pln_x;
	float	pln_y;

	// The angle player is looking to in radians reletive to the x axis
	float	angle;
}	t_player;

typedef struct s_game
{
	t_scene		*scene;
	t_player	*plr;
	t_ray		ray;
	t_mlx		*mlx;
}	t_game;

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

// -- MACROS --

# define PI			3.14159265358979323846
# define FOV		PI/3
# define PI_2		PI/2
# define SCREEN_W	700
# define SCREEN_H	500
# define SPEED		1
# define R_SPEED	PI/2
# define TILE_SIZE	64

// COLORS
//					0xRRGGBBAA
# define RED		0xFF0000FF
# define BLUE		0x0000FFFF
# define GREEN		0x00FF00FF
# define BLACK		0x000000FF
# define WHITE		0xFFFFFFFF
# define GRAY		0xFFFFFF00

// -- FUNCTION PROTOTYPES --

//		game_initialization.c
int		init_game(t_game *game, int ac, char **av);

//		game_init_utils.c
void	set_west_and_east(t_player *plr, char dir);
int		load_textures(t_scene *s, t_mlx *mlx);

//		srcs/drawing_utils.c
void	background_color(t_mlx *mlx, unsigned int color);
void	draw_column(t_game *game, int x);

//		srcs/drawing_utils2.c
void 	get_draw_info(t_draw *d, t_game *game);
void    get_texture_pixel(t_draw *d, t_game *game);


//		srcs/key_hook.c
void	key_hook(mlx_key_data_t keydata, void *param);

//		srcs/movement.c
void	move(t_scene *s, t_player *p, t_dir dir);
void	rotate(t_player *p, t_dir dir);

//srcs/free/free_textures.c
void	free_textures_mlx(t_mlx *mlx);

// parsing/*.c
int		compress_file(t_scene *scene, char *file);
int		get_line(char **line, int fd);
t_scene	*parsing_main(char **argv);
void	trim_spaces(char **line);
void	perror_and_exit(t_scene *scene, char *str, int exit);



#endif
