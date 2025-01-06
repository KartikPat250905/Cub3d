#include "../includes/cub3d.h"

static void	init_mlx(t_scene *scene, t_mlx *mlx)
{
	mlx->mlx = mlx_init(SCREEN_W, SCREEN_H, "cub3d", false);
	if (!mlx)
	{
		free_and_exit(scene, EXIT_FAILURE);
		exit(EXIT_FAILURE);
	}
	mlx->img = mlx_new_image(mlx->mlx, SCREEN_W, SCREEN_H);
	if (!mlx->img)
	{
		mlx_terminate(mlx->mlx);
		free_and_exit(scene, EXIT_FAILURE);
		exit(EXIT_FAILURE);
	}
}

void	get_angle(t_game *game, char ch)
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
	int		x;
	int		y;
	char	ch;

	x = 0;
	while (game->scene->map[x])
	{
		y = 0;
		while (game->scene->map[x][y])
		{
			ch = game->scene->map[x][y];
			if (ch == 'N' || ch == 'S' || ch == 'E' || ch == 'W')
			{
				printf("posx = %f, posy = %f\n", (float)x, (float)y);
				game->plr.pos_x = (float)x;
				game->plr.pos_y = (float)y;
				get_angle(game, ch);
				break ;
			}
			y++;
		}
		x++;
	}
}

int	init_game(t_game *game, int ac, char **av)
{
	if (ac != 2)
		return (0);
	game = malloc(sizeof(t_game));
	game->mlx = malloc(sizeof(t_mlx));
	game->scene = parsing_main(av);
	set_starting_pos(game);
	if (!game->scene)
		return (0);
	init_mlx(game->scene, game->mlx);
	return (1);
}
