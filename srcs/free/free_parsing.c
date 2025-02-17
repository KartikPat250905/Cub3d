/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karpatel <karpatel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:42:44 by karpatel          #+#    #+#             */
/*   Updated: 2025/01/08 11:42:45 by karpatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(t_scene *scene)
{
	int	i;

	i = 0;
	while (scene->map[i])
	{
		free(scene->map[i]);
		scene -> map[i] = NULL;
		i++;
	}
	free(scene->map);
	scene->map = NULL;
}

void	free_textures(t_scene *scene)
{
	if (scene -> north)
	{
		free(scene->north);
		scene->north = NULL;
	}
	if (scene -> south)
	{
		free(scene -> south);
		scene -> south = NULL;
	}
	if (scene -> west)
	{
		free(scene -> west);
		scene -> west = NULL;
	}
	if (scene -> east)
	{
		free(scene -> east);
		scene -> east = NULL;
	}
}

void	free_file(t_scene *scene)
{
	int	i;

	i = 0;
	while (scene->file[i])
	{
		free(scene->file[i]);
		scene -> file[i] = NULL;
		i++;
	}
	free(scene->file);
	scene->file = NULL;
}

void	free_colors(t_scene *scene)
{
	if (scene -> floor_color)
		free(scene -> floor_color);
	if (scene -> cieling_color)
		free(scene -> cieling_color);
	scene -> cieling_color = NULL;
	scene -> floor_color = NULL;
}

void	free_and_exit(t_scene *scene, int code)
{
	if (!scene)
		return ;
	if (scene -> map)
		free_map(scene);
	free_textures(scene);
	if (scene -> file)
		free_file(scene);
	free_colors(scene);
	free(scene);
	scene = NULL;
	exit(code);
}
