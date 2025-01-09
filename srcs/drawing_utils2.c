/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:07:15 by motuomin          #+#    #+#             */
/*   Updated: 2025/01/09 18:30:13 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_texture_pixel(t_draw *d, t_game *game)
{
	d->tex_y = (int)((d->draw_start - SCREEN_H / 2 + d->line_height / 2) * d->texture->height / d->line_height);
	if (d->tex_y < 0)
		d->tex_y = 0;
	if ((unsigned int)d->tex_y >= (unsigned int)d->texture->height)
		d->tex_y = d->texture->height - 1;
	if (game->ray.side == 0)
		d->tex_x = (int)((game->ray.map_y + (1 - game->ray.dir_y * (game->ray.p_dist))) * d->texture->width) % d->texture->width;
	else
		d->tex_x = (int)((game->ray.map_x + (1 - game->ray.dir_x * (game->ray.p_dist))) * d->texture->width) % d->texture->width;
	if (d->tex_x < 0)
		d->tex_x = 0;
	if ((unsigned int)d->tex_x >= (unsigned int)d->texture->width)
		d->tex_x = d->texture->width - 1;
	if (d->tex_y < 0)
		d->tex_y = 0;
	if ((unsigned int)d->tex_y >= (unsigned int)d->texture->height)
		d->tex_y = d->texture->height - 1; 
}

void	get_draw_info(t_draw *d, t_game *game)
{
	d->line_height = (int)(SCREEN_H / game->ray.p_dist);
	d->draw_start = -d->line_height / 2 + SCREEN_H / 2;
	if (d->draw_start < 0)
		d->draw_start = 0;
	d->draw_end = d->line_height / 2 + SCREEN_H / 2;
	if (d->draw_end > SCREEN_H)
		d->draw_end = SCREEN_H - 1;
	if (game->ray.side == 0)
	{
		if (game->ray.dir_x > 0)
			d->texture = game->mlx->t_e;
		else
			d->texture = game->mlx->t_w;
	}
	else
	{
		if (game->ray.dir_y > 0)
			d->texture = game->mlx->t_s;
		else
			d->texture = game->mlx->t_n;
	}
}
