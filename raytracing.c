/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karpatel <karpatel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:43:14 by karpatel          #+#    #+#             */
/*   Updated: 2025/02/01 14:17:01 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
	len_x_stp = the length of the ray between 2 vertical grid lines
	len_y_stp = the length of the ray between 2 horizontal grid lines
	plr_len_x = The lenght of the ray from the plrs pos to next vertical line
	plr_len_y = The lenght of the ray from the plrs pos to next horizontal line
*/

static void	calculate_step_and_dist(t_player *plr, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_dir_x = -1;
		ray->plr_len_x = (plr->pos_x - ray->map_x) * ray->len_x_stp;
	}
	else
	{
		ray->step_dir_x = 1;
		ray->plr_len_x = (ray->map_x + 1 - plr->pos_x) * ray->len_x_stp;
	}
	if (ray->dir_y < 0)
	{
		ray->step_dir_y = -1;
		ray->plr_len_y = (plr->pos_y - ray->map_y) * ray->len_y_stp;
	}
	else
	{
		ray->step_dir_y = 1;
		ray->plr_len_y = (ray->map_y + 1 - plr->pos_y) * ray->len_y_stp;
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
		ray->len_x_stp = 1e30;
	else
		ray->len_x_stp = fabs(sqrt(1 + (ray->dir_y * ray->dir_y) \
				/ (ray->dir_x * ray->dir_x)));
	if (ray->dir_y == 0)
		ray->len_y_stp = 1e30;
	else
		ray->len_y_stp = fabs(sqrt(1 + (ray->dir_x * ray->dir_x) \
				/ (ray->dir_y * ray->dir_y)));
	calculate_step_and_dist(plr, ray);
}

void	dda(t_ray *ray, t_scene *scene)
{
	while (!ray->hit)
	{
		if (ray->plr_len_x < ray->plr_len_y)
		{
			ray->plr_len_x += ray->len_x_stp;
			ray->map_x += ray->step_dir_x;
			ray->side = 'h';
		}
		else
		{
			ray->plr_len_y += ray->len_y_stp;
			ray->map_y += ray->step_dir_y;
			ray->side = 'v';
		}
		if (scene->map && scene->map[ray->map_y]
			&& scene->map[ray->map_y][ray->map_x]
			&& scene->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

int	raycast_loop(t_game *game, t_scene *scene,
	t_player *plr, t_ray *ray)
{
	int	x;

	x = -1;
	while (++x < SCREEN_W)
	{
		update_values(plr, ray, x);
		dda(ray, scene);
		if (ray->side == 'h')
			ray->final_dist = ray->plr_len_x - ray->len_x_stp;
		else
			ray->final_dist = ray->plr_len_y - ray->len_y_stp;
		draw_column(game, x);
	}
	if (mlx_image_to_window(game->mlx->mlx, game->mlx->img, 0, 0) < 0)
		exit (1);
	return (0);
}
