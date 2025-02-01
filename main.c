/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:46:11 by motuomin          #+#    #+#             */
/*   Updated: 2025/01/09 18:03:46 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static void	game_loop(void *ptr)
{
	t_game	*game;

	game = (t_game *)ptr;
	raycast_loop(game, game->scene, game->plr, &game->ray);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (1);
	game = malloc(sizeof(t_game));
	if (!game)
	{
		printf("Error malloc failed.");
		return (1);
	}
	if (!init_game(game, ac, av))
	{
		free(game);
		return (1);
	}
	mlx_loop_hook(game->mlx->mlx, game_loop, (void *)game);
	mlx_key_hook(game->mlx->mlx, key_hook, (void *)game);
	mlx_loop(game->mlx->mlx);
	return (0);
}
