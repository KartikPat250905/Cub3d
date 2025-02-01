/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karpatel <karpatel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:48:58 by karpatel          #+#    #+#             */
/*   Updated: 2025/02/01 15:55:40 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_mlx(t_scene *scene, t_mlx *mlx)
{
	mlx->mlx = mlx_init(SCREEN_W, SCREEN_H, "cub3d", false);
	if (!mlx)
	{
		free_and_exit(scene, EXIT_FAILURE);
		exit(EXIT_FAILURE);
	}
	mlx->img = mlx_new_image(mlx->mlx, SCREEN_W, SCREEN_H);
	if (!mlx->img || !load_textures(scene, mlx))
	{
		mlx_terminate(mlx->mlx);
		free_and_exit(scene, EXIT_FAILURE);
		exit(EXIT_FAILURE);
	}
}

static void	set_angle(t_player *plr, char dir)
{
	if (dir == 'N')
	{
		plr->dir_x = 0;
		plr->dir_y = -1;
		plr->pln_x = 1;
		plr->pln_y = 0;
	}
	else if (dir == 'S')
	{
		plr->dir_x = 0;
		plr->dir_y = 1;
		plr->pln_x = -1;
		plr->pln_y = 0;
	}
	set_west_and_east(plr, dir);
}

void	get_angle(char ch, t_player *plr)
{
	if (ch == 'N')
		plr->angle = 90 * (M_PI / 180);
	else if (ch == 'E')
		plr->angle = 0;
	else if (ch == 'W')
		plr->angle = 180 * (M_PI / 180);
	else if (ch == 'S')
		plr->angle = 270 * (M_PI / 180);
}

static t_player	*set_starting_pos(t_game *game, t_player *player)
{
	int			x;
	int			y;

	x = 0;
	while (game->scene->map[x])
	{
		y = 0;
		while (game->scene->map[x][y])
		{
			if (game->scene->map[x][y] == 'N' || game->scene->map[x][y] == 'S'
				|| game->scene->map[x][y] == 'E'
				|| game->scene->map[x][y] == 'W')
			{
				player->pos_x = (float)y;
				player->pos_y = (float)x;
				get_angle(game->scene->map[x][y], player);
				set_angle(player, game->scene->map[x][y]);
				break ;
			}
			y++;
		}
		x++;
	}
	return (player);
}

int	init_game(t_game *game, int ac, char **av)
{
	if (ac != 2)
	{
		printf("Use program as follows : \"./cub3D <map_file.cub>\"\n");
		return (0);
	}
	game->scene = parsing_main(av);
	if (!game->scene)
		return (0);
	game->mlx = malloc(sizeof(t_mlx));
	if (!game->mlx)
	{
		printf("Error malloc failed.");
		exit (1);
	}
	game->plr = malloc(sizeof(t_player));
	if (!game->plr)
	{
		free_game(game);
		perror_and_exit(game->scene, "Error malloc failed.", 1);
	}
	game->plr = set_starting_pos(game, game->plr);
	if (!game->scene)
		return (0);
	init_mlx(game->scene, game->mlx);
	return (1);
}
