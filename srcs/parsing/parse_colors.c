/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karpatel <karpatel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:27:23 by karpatel          #+#    #+#             */
/*   Updated: 2025/01/08 11:27:24 by karpatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_rgb(t_scene *scene, char **splits, int who)
{
	int	i;
	int	*color;

	i = 0;
	if (who == 1)
		color = scene->floor_color;
	else
		color = scene->cieling_color;
	while (i < 3)
	{
		if (!ft_is_num_str(splits[i]))
			perror_and_exit(scene, "Error the color values "
				"are not integers.", 1);
		color[i] = ft_atoi(splits[i]);
		if (color[i] < 0 || color[i] > 255)
			perror_and_exit(scene, "Error with the color values.", 1);
		i++;
	}
	if (splits[3] != NULL)
		perror_and_exit(scene, "Error the colors have more stuff than RGB", 1);
}

void	get_colors(t_scene *scene, char *line, int who)
{
	char	*no_spaces;
	int		i;
	int		len;
	char	**splits;

	i = 0;
	len = 0;
	while (line[i])
		len += !ft_isspace(line[i++]);
	no_spaces = ft_calloc((len + 1), sizeof(char));
	i = 0;
	len = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			no_spaces[len++] = line[i];
		i++;
	}
	splits = ft_split(no_spaces, ',');
	add_rgb(scene, splits, who);
	free_array((void **)splits);
	free(no_spaces);
}

void	parse_color(t_scene *scene, char *line, int is_cieling)
{
	int	start;

	if (line[ft_strlen(line) - 1] == ',')
		perror_and_exit(scene, "Extra comma at the end of the colors.", 1);
	start = get_path(scene, line, 1);
	get_colors(scene, line + start, is_cieling);
}
