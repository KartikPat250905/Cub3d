/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karpatel <karpatel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:11:10 by karpatel          #+#    #+#             */
/*   Updated: 2025/01/08 11:11:11 by karpatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	valid_map_char(char **file, int index, int j)
{
	if (file[index][j] != '1' && file[index][j] != '0'
			&& file[index][j] != 'N' && file[index][j] != 'S'
			&& file[index][j] != 'W' && file[index][j] != 'E'
			&& file[index][j] != ' ')
		return (0);
	return (1);
}

void	is_valid(t_scene *scene, char **file, int index, int character)
{
	int		j;

	while (file[index])
	{
		j = 0;
		if (get_element_type(file[index]) != 7)
			perror_and_exit(scene, "The data not in format as expected.", 1);
		while (file[index][j])
		{
			if (!valid_map_char(file, index, j))
				perror_and_exit(scene, "Undesired characters in the map.", 1);
			if (file[index][j] == 'N' || file[index][j] == 'S'
					|| file[index][j] == 'W' || file[index][j] == 'E')
			{
				if (character)
					perror_and_exit(scene, "Multiple characters "
						"present on the map.", 1);
				character = 1;
			}
			change_space(file, index, j++, 0);
		}
		index++;
	}
	if (!character)
		perror_and_exit(scene, "No character found on the map.", 1);
}

void	check_map_boundary_sides(t_scene *scene, int i, char **file, int index)
{
	i = index;
	while (file[i] && file[i][0])
	{
		if (file[i][0] != '1')
			perror_and_exit(scene, "The given map is not closed", 1);
		change_space(file, i, 0, 1);
		i++;
	}
	i = index;
	while (file[i] && file[i][ft_strlen(file[i]) - 1])
	{
		if (file[i][ft_strlen(file[i]) - 1] != '1')
			perror_and_exit(scene, "The given map is not closed", 1);
		change_space(file, i, ft_strlen(file[i]) - 1, 1);
		i++;
	}
}

void	check_borders(t_scene *scene, int index, int len)
{
	int		i;
	char	**file;

	file = scene->file;
	i = 0;
	while (file[index][i])
	{
		if (file[index][i] != '1')
			perror_and_exit(scene, "The given map is not closed", 1);
		change_space(file, index, i, 1);
		i++;
	}
	i = 0;
	while (file[len][i])
	{
		if (file[len][i] != '1' && file[len][i] != ' ')
			perror_and_exit(scene, "The given map is not closed", 1);
		change_space(file, len, i, 1);
		i++;
	}
	check_map_boundary_sides(scene, i, file, index);
}

void	parse_map(t_scene *scene, int index, int len)
{
	int	i;

	check_borders(scene, index, len - 1);
	is_valid(scene, scene->file, index, 0);
	scene->map = ft_calloc(len - index + 1, sizeof(char *));
	i = 0;
	while (scene->file[index])
	{
		scene->map[i] = ft_calloc(ft_strlen(scene->file[index]) + 1,
				sizeof(char));
		ft_strlcpy(scene->map[i++], scene->file[index],
			ft_strlen(scene->file[index]) + 1);
		index++;
	}
	scene->map[i] = NULL;
}
