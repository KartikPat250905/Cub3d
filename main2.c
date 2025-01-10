/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:46:11 by motuomin          #+#    #+#             */
/*   Updated: 2025/01/09 18:03:46 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	calculate_step_and_dist(t_player *plr, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->s_dist_x = (plr->pos_x - ray->map_x) * ray->d_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->s_dist_x = (ray->map_x + 1 - plr->pos_x) * ray->d_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->s_dist_y = (plr->pos_y - ray->map_y) * ray->d_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->s_dist_y = (ray->map_y + 1 - plr->pos_y) * ray->d_dist_y;
	}
}

static void	update_values(t_player *plr, t_ray *ray, int x)
{
	ray->hit = 0;
	ray->cam_x = 2 * x / (float)SCREEN_W - 1;
	ray->dir_x = plr->dir_x + plr->pln_x * ray->cam_x;
	ray->dir_y = plr->dir_y + plr->pln_y * ray->cam_x;
	ray->map_x = (int)plr->pos_x;
	ray->map_y = (int)plr->pos_y;
	if (ray->dir_x == 0)
		ray->d_dist_x = 1e30;
	else
		ray->d_dist_x = sqrt(1 + (ray->dir_y * ray->dir_y) / (ray->dir_x * ray->dir_x));
	if (ray->dir_y == 0)
		ray->d_dist_y = 1e30;
	else
		ray->d_dist_y = sqrt(1 + (ray->dir_x * ray->dir_x) / (ray->dir_y * ray->dir_y));
	if (ray->d_dist_x < 0)
		ray->d_dist_x *= (-1);
	if (ray->d_dist_y < 0)
		ray->d_dist_y *= (-1);
	calculate_step_and_dist(plr, ray);
}

static	int	raycast_loop(t_game *game, t_scene *scene, t_player *plr, t_ray *ray)
{
	int	x;

	x = -1;
	while (++x < SCREEN_W)
	{
		update_values(plr, ray, x);
		while (!ray->hit) // What if no hit?
		{
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
			if (scene->map && scene->map[ray->map_y]
				&& scene->map[ray->map_y][ray->map_x]
				&& scene->map[ray->map_y][ray->map_x] == '1')
				ray->hit = 1;
		}
		if (ray->side == 0)
			ray->p_dist = ray->s_dist_x - ray->d_dist_x;
		else
			ray->p_dist = ray->s_dist_y - ray->d_dist_y;
		draw_column(game, x);
	}
	if (mlx_image_to_window(game->mlx->mlx, game->mlx->img, 0, 0) < 0)
		exit (1);
	return (0);
}

static void game_loop(void *ptr)
{
	t_game *game;

	game = (t_game *)ptr;
	raycast_loop(game, game->scene, game->plr, &game->ray);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (1);
	game = malloc(sizeof(t_game));
	if (!init_game(game, ac, av))
		return (1);
	printf("The floor R=%d G=%d and B=%d\n", game->scene -> floor_color[0], game->scene->floor_color[1],game->scene->floor_color[2]);
	printf("The cieling R=%d G=%d and B=%d\n", game->scene -> cieling_color[0], game->scene->cieling_color[1],game->scene->cieling_color[2]);
	mlx_loop_hook(game->mlx->mlx, game_loop, (void *)game);
	mlx_key_hook(game->mlx->mlx, key_hook, (void *)game);
	mlx_loop(game->mlx->mlx);
	return (0);
}
