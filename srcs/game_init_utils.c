/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karpatel <karpatel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:14:42 by karpatel          #+#    #+#             */
/*   Updated: 2025/01/08 14:07:04 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	load_textures(t_scene *s, t_mlx *mlx)
{
	mlx_texture_t *t;

	t = mlx_load_png(s->north);
	if (!t)
		return (0);
	mlx->t_n = mlx_texture_to_image(mlx->mlx, t);
	free(t);
	t = mlx_load_png(s->south);
	if (!t)
		return (0);
	mlx->t_s = mlx_texture_to_image(mlx->mlx, t);
	free(t);
	t = mlx_load_png(s->east);
	if (!t)
		return (0);
	mlx->t_e = mlx_texture_to_image(mlx->mlx, t);
	free(t);
	t = mlx_load_png(s->west);
	if (!t)
		return (0);
	mlx->t_w = mlx_texture_to_image(mlx->mlx, t);
	free(t);
	return (1);
}

void	set_west_and_east(t_player *plr, char dir)
{
	if (dir == 'W')
	{
		plr->dir_x = -1;
		plr->dir_y = 0;
		plr->pln_x = 0;
		plr->pln_y = -1;
	}
	else if (dir == 'E')
	{
		plr->dir_x = 1;
		plr->dir_y = 0;
		plr->pln_x = 0;
		plr->pln_y = 1;
	}
}
