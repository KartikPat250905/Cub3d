#include "includes/cub3d.h"

static int	gameloop(t_game *game);

int	main(int ac, char **av)
{
	t_game	game;

	// check ac in parsing
	if (!init_game(&game))
		return (1);
	return(gameloop(game->scene, game->plr, game->ray));
}

static int	gameloop(t_scene *scene, t_player *plr, t_ray *ray)
{
	while(1)
	{
		raycast_loop();
	}
}

static void	calculate_step_and_dist(t_player *plr, t_ray *ray, int x)
{
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

static void	update_values(t_player *plr, t_ray *ray, int x)
{
	ray->hit = 0;

	// Our horizontal position on the screen
	plr->cam_x = 2 * x / float(RES_X) - 1;

	// Direction vector of the current ray
	ray->dir_x = plr->dir_x + plr->pln_x * plr->cam_x;
	ray->dir_y = plr->dir_y + plr->pln_y * plr->cam_x;

	// Which box of the map we're in
	ray->map_x = (int)plr->pos_x;
	ray->map_x = (int)plr->pos_y;

	// Distance until next grid side
	if (ray->dir_x == 0)
		ray->d_dist_x = 1e30;
	else
		ray->d_dist_x = abs(1 / ray->dir_x);
	if (ray->dir_y == 0)
		ray->d_dist_y = 1e30;
	else
		ray->d_dist_y = abs(1 / ray->dir_y);

	calculate_step_and_dir(plr, ray, x);
}

static	int	raycast_loop(t_scene *scene, t_player *plr, t_ray *ray)
{
	int	x;

	x = -1;
	// Goes through every vertical stripe (?)
	while (++x < RES_X)
	{
		update_values(plr, ray, x);
		while (!ray->hit) // What if no hit?
		{
			// Jump to next square
			if (ray->s_dist_x < ray->s_dist_y)
			{
				ray->s_dist_x += ray->d_dist_x;
				ray->map_x += ray->step_x;
				ray->side = 0;
			}
			else
			{
				ray->s_dist_y += ray->d_dist_y;
				ray->map_y += ray->step_y;
				ray->side = 1;
			}
			if (scene->map[ray->map_x][ray->map_y] == 1)
				ray->hit = 1;
		}
		if (side == 0)
			ray->p_wall_dist = ray->s_dist_x - ray->d_dist_x);
		else
			ray->p_wall_dist = ray->s_dist_y - ray->d_dist_y);
	}
}
