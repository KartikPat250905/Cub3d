#include "includes/cub3d.h"

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
	return (1);
}
