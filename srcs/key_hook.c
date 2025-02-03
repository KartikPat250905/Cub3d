/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:19:31 by motuomin          #+#    #+#             */
/*   Updated: 2025/02/03 12:14:21 by jelloster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		free_textures_mlx(game->mlx);
		free_game(game);
		free_and_exit(game->scene, EXIT_SUCCESS);
	}
}

void	movement_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (mlx_is_key_down(game->mlx->mlx, MLX_KEY_W))
		move(game->scene, game->plr, UP);
	if (mlx_is_key_down(game->mlx->mlx, MLX_KEY_S))
		move(game->scene, game->plr, DOWN);
	if (mlx_is_key_down(game->mlx->mlx, MLX_KEY_A))
		move(game->scene, game->plr, LEFT);
	if (mlx_is_key_down(game->mlx->mlx, MLX_KEY_D))
		move(game->scene, game->plr, RIGHT);
	if (mlx_is_key_down(game->mlx->mlx, MLX_KEY_LEFT))
		rotate(game->plr, LEFT);
	if (mlx_is_key_down(game->mlx->mlx, MLX_KEY_RIGHT))
		rotate(game->plr, RIGHT);
}
