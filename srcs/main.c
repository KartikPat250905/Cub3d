/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:46:11 by motuomin          #+#    #+#             */
/*   Updated: 2025/02/04 19:11:03 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	game_loop(void *ptr)
{
	t_game	*game;

	game = (t_game *)ptr;
	raycast_loop(game, game->scene, game->plr, &game->ray);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (av[1] && ft_strlen(av[1]) <= 4)
	{
		printf("Error\nPlease provide a valid file\n");
		return (1);
	}
	game = malloc(sizeof(t_game));
	if (!game)
	{
		printf("Error\nmalloc failed.");
		return (1);
	}
	if (!init_game(game, ac, av))
	{
		free(game);
		return (1);
	}
	// printf("The north texture is %s\n", game->scene -> north);
	// printf("The sorth texture is %s\n", game->scene -> south);
	// printf("The east texture is %s\n", game->scene -> east);
	// printf("The west texture is %s\n", game->scene -> west);
	// printf("The floor R=%d G=%d and B=%d\n", game->scene -> floor_color[0], game->scene->floor_color[1],game->scene->floor_color[2]);
	// printf("The cieling R=%d G=%d and B=%d\n", game->scene -> cieling_color[0], game->scene->cieling_color[1],game->scene->cieling_color[2]);
	mlx_loop_hook(game->mlx->mlx, game_loop, (void *)game);
	mlx_key_hook(game->mlx->mlx, key_hook, (void *)game);
	mlx_loop(game->mlx->mlx);
	return (0);
}
