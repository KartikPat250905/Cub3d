/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:42:53 by motuomin          #+#    #+#             */
/*   Updated: 2025/01/10 14:35:56 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static unsigned int	get_color(int r, int g, int b, int a)
{
	unsigned int	color;

	color = (r << 24) | (g << 16) | (b << 8) | a;
	return (color);
}

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

static void	draw_ceiling(t_game *game, int x)
{
	int	i;
	int	color;

	i = 0;
	color = get_color(game->scene->cieling_color[0], \
					game->scene->cieling_color[1], \
					game->scene->cieling_color[2], 255);
	while (i < SCREEN_H / 2)
	{
		if (x >= 0 && x < SCREEN_W && i >= 0 && i < SCREEN_H)
			mlx_put_pixel(game->mlx->img, x, i, color);
		i++;
	}
}

static void	draw_floor(t_game *game, int x)
{
	int	color;
	int	y;

	color = get_color(game->scene->floor_color[0], \
					game->scene->floor_color[1], \
					game->scene->floor_color[2], 255);
	y = SCREEN_H / 2 + 1;
	while (y < SCREEN_H)
	{
		if (x >= 0 && x < SCREEN_W && y >= 0 && y < SCREEN_H)
			mlx_put_pixel(game->mlx->img, x, y, color);
		y++;
	}
}

void	draw_column(t_game *game, int x)
{
	t_draw	d;

	get_draw_info(&d, game);
	draw_ceiling(game, x);
	draw_floor(game, x);
	while (d.draw_start < d.draw_end)
	{
		get_texture_pixel(&d, game);
		d.color = ((int *)d.texture->pixels) \
			[d.tex_y * d.texture->width + d.tex_x];
		d.a = (d.color >> 24) & 0xFF;
		d.r = (d.color >> 16) & 0xFF;
		d.g = (d.color >> 8) & 0xFF;
		d.b = d.color & 0xFF;
		d.color = get_color(d.r, d.g, d.b, d.a);
		mlx_put_pixel(game->mlx->img, x, d.draw_start, d.color);
		d.draw_start++;
	}
}
