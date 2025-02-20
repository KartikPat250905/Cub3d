/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karpatel <karpatel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:05:11 by karpatel          #+#    #+#             */
/*   Updated: 2025/02/01 16:07:14 by motuomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	file_check(const char *filename, t_scene *scene)
{
	int		fd;
	char	buffer;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		perror_and_exit(scene, "Error opening file", 1);
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer != ' ' && buffer != '\n' && buffer != '\t')
		{
			close(fd);
			return (0);
		}
	}
	close(fd);
	return (1);
}

void	parse_north(t_scene *scene, char *line)
{
	int		i;
	int		start;
	char	*extension;

	scene->has_north = 1;
	start = get_path(scene, line, 2);
	i = open(line + start, O_RDONLY);
	if (i < 0 || !ft_strcmp(line + start, ".png")
		|| file_check(line + start, scene))
		perror_and_exit(scene, "Open failed north", 1);
	close(i);
	scene->north = ft_strdup(line + start);
	if (!scene->north)
		perror_and_exit(scene, "Error malloc failed.", 1);
	extension = ft_strrchr(scene->north, '.');
	if (!extension || ft_strcmp(extension, ".png") != 0)
		perror_and_exit(scene, "West texture must be a .png file.", 1);
}

void	parse_south(t_scene *scene, char *line)
{
	int		i;
	int		start;
	char	*extension;

	scene->has_south = 1;
	start = get_path(scene, line, 2);
	i = open(line + start, O_RDONLY);
	if (i < 0 || !ft_strcmp(line + start, ".png")
		|| file_check(line + start, scene))
		perror_and_exit(scene, "Open failed south", 1);
	close(i);
	scene->south = ft_strdup(line + start);
	if (!scene->south)
		perror_and_exit(scene, "Error malloc failed.", 1);
	extension = ft_strrchr(scene->south, '.');
	if (!extension || ft_strcmp(extension, ".png") != 0)
		perror_and_exit(scene, "West texture must be a .png file.", 1);
}

void	parse_east(t_scene *scene, char *line)
{
	int		i;
	int		start;
	char	*extension;

	scene->has_east = 1;
	start = get_path(scene, line, 2);
	i = open(line + start, O_RDONLY);
	if (i < 0 || !ft_strcmp(line + start, ".png")
		|| file_check(line + start, scene))
		perror_and_exit(scene, "Open failed east", 1);
	close(i);
	scene->east = ft_strdup(line + start);
	if (!scene->east)
		perror_and_exit(scene, "Error malloc failed.", 1);
	extension = ft_strrchr(scene->east, '.');
	if (!extension || ft_strcmp(extension, ".png") != 0)
		perror_and_exit(scene, "West texture must be a .png file.", 1);
}

void	parse_west(t_scene *scene, char *line)
{
	int		i;
	int		start;
	char	*extension;

	scene->has_west = 1;
	start = get_path(scene, line, 2);
	i = open(line + start, O_RDONLY);
	if (i < 0 || !ft_strcmp(line + start, ".png")
		|| file_check(line + start, scene))
		perror_and_exit(scene, "Open failed west", 1);
	close(i);
	scene->west = ft_strdup(line + start);
	if (!scene->west)
		perror_and_exit(scene, "Error malloc failed.", 1);
	extension = ft_strrchr(scene->west, '.');
	if (!extension || ft_strcmp(extension, ".png") != 0)
		perror_and_exit(scene, "West texture must be a .png file.", 1);
}
