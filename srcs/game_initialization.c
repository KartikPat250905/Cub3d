#include "includes/cub3d.h"

static void	init_mlx(t_scene *scene, t_mlx *mlx)
{
	mlx->mlx = mlx_init(RES_X, RES_Y, "cub3d", true);
	if (!mlx)
	{
		free_and_exit(scene, EXIT_FAILURE);
		exit(EXIT_FAILURE);
	}
	mlx->img = mlx_new_image(mlx->mlx, RES_X, RES_Y);
	if (!mlx->img)
	{
		mlx_terminate(mlx->mlx);
		free_and_exit(scene, EXIT_FAILURE);
		exit(EXIT_FAILURE);
	}
}

void	get_angle(t_game *game)
{
	if (ch == 'N')
		game->plr.angle = 90 * (M_PI / 180);
	else if (ch == 'E')
		game->plr.angle = 0;
	else if (ch == 'W')
		game->plr.angle = 180 * (M_PI / 180);
	else if (ch == 'S')
		game->plr.angle = 270 * (M_PI / 180);
}

static void	set_starting_pos(t_game *game)
{
	float		x;
	float		y;
	char		ch;

	x = 0;
	game->plr = malloc(sizeof(t_player));
	while (game->scene->map[x])
	{
		y = 0;
		while (game->scene->map[x][y])
		{
			ch = game->scene->map[x][y];
			if (ch == 'N' || ch == 'S' || ch == 'E' || ch == 'W')
			{
				game->plr.pos_x = x * TILE_SIZE;
				game->plr.pos_y = y * TILE_SIZE;
				get_angle(game, ch);
				break ;
			}
			y++;
		}
		x++;
	}
}

int	init_game(t_game *game)
{
	game->scene = parsing_main(av);
	game->plr = get_player_info(game);
	if (!game->scene)
		return (0);
	set_starting_pos(game);
	init_mlx(game->scene, game->mlx);
	return (1);
}
