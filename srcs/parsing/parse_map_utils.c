/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karpatel <karpatel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:01:10 by karpatel          #+#    #+#             */
/*   Updated: 2025/01/08 14:01:11 by karpatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate_row_extension(t_scene *scene, int index)
{
	int	last_len;
	int	x;

	last_len = 0;
	while (scene->file[index])
	{
		x = 0;
		while (scene->file[index][x])
		{
			if (x > last_len && scene->file[index][x] != '1')
				perror_and_exit(scene, "Error the map is open "
					"from the boundaries.", 1);
			x++;
		}
		last_len = ft_strlen(scene->file[index]) - 1;
		index++;
	}
}
