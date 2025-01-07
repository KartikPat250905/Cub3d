/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:42:53 by motuomin          #+#    #+#             */
/*   Updated: 2025/01/07 14:42:20 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	background_color(t_mlx *mlx, unsigned int color)
{
	uint32_t	y;
	uint32_t	x;

	y = 0;
	x = 0;
	while (y < mlx -> img -> height)
	{
		x = 0;
		while (x < mlx -> img -> width)
		{
			mlx_put_pixel(mlx -> img, x, y, color);
			x++;
		}
		y++;
	}
}

static void	draw_ceiling(t_game *game, int x, int draw_start)
{
	int	i;

	i = 0;
	while (i < draw_start)
			mlx_put_pixel(game->mlx->img, x, i++, BLUE);
			//mlx_put_pixel(game->mlx->img, x, i++, *game->scene->cieling_color);
}

static void	draw_floor(t_game *game, int x, int y)
{
	while (y < SCREEN_H - 1)
			mlx_put_pixel(game->mlx->img, x, y++, GRAY);
			//mlx_put_pixel(game->mlx->img, x, y++, *game->scene->floor_color);
}

void	draw_column(t_game *game, int x)
{
	int	line_height;
	int	draw_start;
	int	draw_end;

	line_height = (int)(SCREEN_H / game->ray.p_dist);
	draw_start = -line_height / 2 + SCREEN_H / 3;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + SCREEN_H / 2;
	if (draw_end > SCREEN_H)
		draw_end = SCREEN_H - 1;
	draw_ceiling(game, x, draw_start);
	while (draw_start < draw_end)
	{
		if (game->ray.side == 1)
			mlx_put_pixel(game->mlx->img, x, draw_start, RED);
		else
			mlx_put_pixel(game->mlx->img, x, draw_start, BLACK);
		draw_start++;
	}
	draw_floor(game, x, draw_start);
}
