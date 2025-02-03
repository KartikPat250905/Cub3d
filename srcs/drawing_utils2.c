/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 18:07:15 by motuomin          #+#    #+#             */
/*   Updated: 2025/02/03 11:38:46 by jelloster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_texture_pixel(t_draw *d, t_game *game)
{
	d->tex_y = (int)((float)d->texture->height * (((float)d->draw_start - \
		((float)SCREEN_H - d->line_height) / 2) / d->line_height));
	if ((unsigned int)d->tex_y >= (unsigned int)d->texture->height)
		d->tex_y = d->texture->height - 1;
	if (game->ray.side == 'h')
		d->tex_x = (int)((1.0 - (float)(game->ray.dir_y * game->ray.final_dist \
		- game->ray.map_y)) * d->texture->width) % d->texture->width;
	else
		d->tex_x = (int)((1.0 - (float)(game->ray.dir_x * game->ray.final_dist \
		- game->ray.map_x)) * d->texture->width) % d->texture->width;
	if ((unsigned int)d->tex_x >= (unsigned int)d->texture->width)
		d->tex_x = d->texture->width - 1;
	if ((unsigned int)d->tex_y >= (unsigned int)d->texture->height)
		d->tex_y = d->texture->height - 1;
}

void	get_draw_info(t_draw *d, t_game *game)
{
	d->line_height = (int)(SCREEN_H / game->ray.final_dist);
	d->draw_start = -d->line_height / 2 + SCREEN_H / 2;
	if (d->draw_start < 0)
		d->draw_start = 0;
	d->draw_end = d->line_height / 2 + SCREEN_H / 2;
	if (d->draw_end > SCREEN_H)
		d->draw_end = SCREEN_H - 1;
	if (game->ray.side == 'h')
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
