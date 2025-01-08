/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karpatel <karpatel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:03:55 by karpatel          #+#    #+#             */
/*   Updated: 2025/01/08 11:03:56 by karpatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_path(t_scene *scene, char *line, int i)
{
	int	start;
	int	j;

	j = i;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (i == j)
		perror_and_exit(scene, "Error with the path for the texture\n", 1);
	start = i;
	return (start);
}

void	fill_data(t_scene *scene, t_etype type, char *line)
{
	if (type == PARSE_NORTH)
		parse_north(scene, line);
	else if (type == PARSE_EAST)
		parse_east(scene, line);
	else if (type == PARSE_WEST)
		parse_west(scene, line);
	else if (type == PARSE_SOUTH)
		parse_south(scene, line);
	else if (type == PARSE_CEILING)
		parse_color(scene, line, 1);
	else if (type == PARSE_FLOOR)
		parse_color(scene, line, 0);
}
