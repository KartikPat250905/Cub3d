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

static void	set_angle(t_game *game, char dir)
{
	if (dir == 'N')
	{
		game->plr.dir_x = game->plr.dir_x;
		game->plr.dir_y = game->plr.dir_x + 3;
	}
	else if (dir == 'S')
	{
		game->plr.dir_x = game->plr.dir_x;
		game->plr.dir_y = game->plr.dir_x - 3;
	}
	else if (dir == 'W')
	{
		game->plr.dir_x = game->plr.dir_x + 3;
		game->plr.dir_y = game->plr.dir_x;
	}
	else if (dir == 'E')
	{
		game->plr.dir_x = game->plr.dir_x - 3;
		game->plr.dir_y = game->plr.dir_x;
	}
}

void	get_angle(char ch, t_player *plr)
{
	if (ch == 'N')
		plr->angle = 90 * (M_PI / 180);
	else if (ch == 'E')
		plr->angle = 0;
	else if (ch == 'W')
		plr->angle = 180 * (M_PI / 180);
	else if (ch == 'S')
		plr->angle = 270 * (M_PI / 180);
}

static t_player	*set_starting_pos(t_game *game)
{
	int		x;
	int		y;
	char	ch;
	t_player	*player;

	x = 0;
	player = malloc(sizeof(t_player));
	while (game->scene->map[x])
	{
		y = 0;
		while (game->scene->map[x][y])
		{
			ch = game->scene->map[x][y];
			if (ch == 'N' || ch == 'S' || ch == 'E' || ch == 'W')
			{
				printf("posx = %f, posy = %f\n", (float)x, (float)y);
				player->pos_x = (float)x;
				player->pos_y = (float)y;
				set_angle(game, ch);
				get_angle(ch, player);
				break ;
			}
			y++;
		}
		x++;
	}
	return (player);
}

int	init_game(t_game *game, int ac, char **av)
{
	if (ac != 2)
		return (0);
	game->mlx = malloc(sizeof(t_mlx));
	game->scene = parsing_main(av);
	game->plr = *set_starting_pos(game);
	if (!game->scene)
		return (0);
	init_mlx(game->scene, game->mlx);
	return (1);
}
