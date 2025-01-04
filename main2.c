#include "includes/cub3d.h"

static int	gameloop(t_game *game);

int	main(int ac, char **av)
{
	t_game	game;

	if (!init_game(&game))
		return (1);
	return(gameloop(game->scene, game->plr, game->ray));
}

static int	gameloop(t_scene *scene, t_player *plr, t_ray *ray)
{
	// Init MLX somwhere
	while(1)
	{
		raycast_loop();
	}
}

static	int	raycast_loop(t_scene *scene, t_player *plr, t_ray *ray)
{
	int	x;
	int	y;

	x = -1;
	y = 0;
	
	// Goes through every vertical stripe
	while (scene->map[++x]) // ?
	{
		// Set hit bool to 0
		ray->hit = 0;

		// Ray position and direction
		plr->cam_x = 2 * x / float(w) - 1; // ?
		ray->dir_x = plr->dir_x + plr->pln_x * plr->cam_x;
		ray->dir_y = plr->dir_y + plr->pln_y * plr->cam_x;

		// Which box of the map we're in
		ray->map_x = (int)plr->pos_x;
		ray->map_x = (int)plr->pos_y;

		//ray->d_dist_x = ;
		//ray->d_dist_y = ;

		// Calculate step and initial side dist
		if (ray->dir_x < 0)
		{
			ray->step_x = -1;
			ray->s_dist_x = (ray->pos_x - ray->map_x) * ray->d_dist_x;
		}
		else
		{
			ray->step_x = 1;
			ray->s_dist_x = (ray->map_x + 1 - ray->pos_x) * ray->d_dist_x;
		}
		if (ray->dir_y < 0)
		{
			ray->step_y = -1;
			ray->s_dist_y = (ray->pos_y - ray->map_y) * ray->d_dist_y;
		}
		else
		{
			ray->step_y = 1;
			ray->s_dist_y = (ray->map_y + 1 - ray->pos_y) * ray->d_dist_y;
		}
		
	}
}
