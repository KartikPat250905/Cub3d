/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karpatel <karpatel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:07:06 by karpatel          #+#    #+#             */
/*   Updated: 2025/01/08 16:07:07 by karpatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_game(t_game *game)
{
	if (!game)
		return;
	if (game->plr)
	{
		free(game->plr);
		game->plr = NULL;
	}
	if (game->mlx)
	{
		if (game->mlx->img)
		{
			mlx_delete_image(game->mlx->mlx, game->mlx->img);
			game->mlx->img = NULL;
		}
		if (game->mlx->mlx)
		{
			mlx_terminate(game->mlx->mlx);
			game->mlx->mlx = NULL;
		}
		free(game->mlx);
		game->mlx = NULL;
	}
}

void	free_textures_mlx(t_mlx *mlx)
{
	if (mlx->t_n)
	{
		mlx_delete_image(mlx->mlx, mlx->t_n);
		mlx->t_n = NULL;
	}
	if (mlx->t_s)
	{
		mlx_delete_image(mlx->mlx, mlx->t_s);
		mlx->t_s = NULL;
	}
	if (mlx->t_e)
	{
		mlx_delete_image(mlx->mlx, mlx->t_e);
		mlx->t_e = NULL;
	}
	if (mlx->t_w)
	{
		mlx_delete_image(mlx->mlx, mlx->t_w);
		mlx->t_w = NULL;
	}
}
