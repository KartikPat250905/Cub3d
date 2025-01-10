/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karpatel <karpatel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:43:14 by karpatel          #+#    #+#             */
/*   Updated: 2025/01/10 14:43:15 by karpatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dda(t_ray *ray, t_scene *scene)
{
	while (!ray->hit)
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
