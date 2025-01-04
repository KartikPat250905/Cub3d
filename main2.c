#include "includes/cub3d.h"

static int	gameloop(t_game *game);

int	main(int ac, char **av)
{
	t_game	game;

	if (!init_game(&game))
		return (1);
	return(gameloop(&game));
}

static int	gameloop(t_game *game, t_player *pl)
{

	while(1)
	{
		pl->cameraX = 2 * x / float(w) - 1;
	}
}

static	int	raycast_loop(t_player *pl)
{
	
	pl->cameraX = 2 * x / float(w) - 1;
	pl->rayDirX = pl->dirX + pl->planeX * pl->cameraX;
	pl->rayDirY = pl->dirY + pl->planeY * pl->cameraX;
}
