/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:19:31 by motuomin          #+#    #+#             */
/*   Updated: 2025/01/07 14:19:32 by motuomin         ###   ########.fr       */
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
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move(game->scene, game->plr, UP);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move(game->scene, game->plr, DOWN);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move(game->scene, game->plr, LEFT);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move(game->scene, game->plr, RIGHT);
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		rotate(game->plr, LEFT);
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		rotate(game->plr, RIGHT);
}
