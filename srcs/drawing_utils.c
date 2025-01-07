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

int rgb_to_int(int r, int g, int b)
{
	if (r < 0) r = 0;
	if (r > 255) r = 255;
	if (g < 0) g = 0;
	if (g > 255) g = 255;
	if (b < 0) b = 0;
	if (b > 255) b = 255;

	return (r << 16) | (g << 8) | b;
}


static void draw_ceiling(t_game *game, int x, int draw_start)
{
	int i;
	int color;

	i = 0;
	color = rgb_to_int(game->scene->cieling_color[0],
					game->scene->cieling_color[1],
					game->scene->cieling_color[2]);
	while (i < draw_start)
	{
		printf("The color for cieling is %d , %d and %d\nThe color is %d\n",game->scene->cieling_color[0],
					game->scene->cieling_color[1],
					game->scene->cieling_color[2], color);
		if (x >= 0 && x < SCREEN_W && i >= 0 && i < SCREEN_H)
			mlx_put_pixel(game->mlx->img, x, i, color);
		i++;
	}
}

static void draw_floor(t_game *game, int x, int y)
{
	int color;

	color = rgb_to_int(game->scene->floor_color[0],
						game->scene->floor_color[1],
						game->scene->floor_color[2]);
	printf("The color for floor is %d, %d and %d\nThe color is %d\n", game->scene->floor_color[0],
						game->scene->floor_color[1],
						game->scene->floor_color[2], color);
	while (y < SCREEN_H)
	{
		if (x >= 0 && x < SCREEN_W && y >= 0 && y < SCREEN_H)
			mlx_put_pixel(game->mlx->img, x, y, color);
		y++;
	}
}

void	draw_column(t_game *game, int x)
{
	int	line_height;
	int	draw_start;
	int	draw_end;

	line_height = (int)(SCREEN_H / game->ray.p_dist);
	draw_start = -line_height / 2 + SCREEN_H / 2;
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
