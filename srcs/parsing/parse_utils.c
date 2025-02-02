/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karpatel <karpatel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:05:18 by karpatel          #+#    #+#             */
/*   Updated: 2025/01/08 11:05:20 by karpatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	change_space(char **file, int row, int col, int ch)
{
	if (file[row][col] != ' ')
		return ;
	if (ch == 1)
		file[row][col] = '1';
	if (ch == 0)
		file[row][col] = '0';
}

void	check_if_data_fetched(t_scene *scene)
{
	if (!scene->north || !scene->south
		|| !scene->east || !scene->west)
		perror_and_exit(scene, "Some error occured while parsing.", 1);
	if (!scene->cieling_color || !scene->floor_color)
		perror_and_exit(scene, "Some error occured while parsing.", 1);
	if (!scene->map)
		perror_and_exit(scene, "Some error occured while parsing.", 1);
}

int	is_map_line(char *line)
{
	char	*temp;
	size_t	i;

	temp = line;
	i = 0;
	if (empty_line(line))
		return (0);
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'N' && 
			line[i] != 'S' && line[i] != 'E' && line[i] != 'W' && line[i] != ' ' && !ft_isspace(line[i]))
		{
			if (!(i == (ft_strlen(temp) - 1) && temp[ft_strlen(temp) - 1] == '\n'))
				return (0);
		}
		i++;
	}
	return (1);
}

int	count_splits(char **splits)
{
	int	count;

	count = 0;
	while (splits[count])
		count++;
	return (count);
}