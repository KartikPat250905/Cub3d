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

static void	set_starting_pos(t_game *game)
{
	/*
	game->plr->pos_x = // From parsed map
	game->plr->pos_y = // From parsed map
	game->p1r->dir_x = -1; // From parsed map
	game->p1r->dir_y = 0; // From parsed map
	*/

	/*
	game->plr->pln_x = // Perpindicular to starting pos
	game->plr->pln_y = // Perpindicular to starting pos
	*/
}

int	init_game(t_game *game)
{
	game->scene = parsing_main(av);
	if (!game->scene)
		return (0);
	set_starting_pos(game);
	init_mlx(game->scene, game->mlx);
	return (1);
}
