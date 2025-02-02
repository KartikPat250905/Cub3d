/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karpatel <karpatel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:05:59 by karpatel          #+#    #+#             */
/*   Updated: 2025/01/08 11:06:01 by karpatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	file_valid(char *file)
{
	int	i;
	int	fd;

	i = 0;
	while (file[i])
		i++;
	while (i > 0 && file[i] != '.')
	{
		i--;
	}
	if (file[i] && !ft_strcmp(file + i, ".cub"))
	{
		fd = open(file, O_RDONLY);
		if (fd < 0)
		{
			printf("Error\nThe given file might not exist.\n");
			return (0);
		}
		close(fd);
		return (1);
	}
	else
		return (0);
}

int	get_line(char **line, int fd)
{
	*line = get_next_line(fd);
	if (!*line)
		return (0);
	return (1);
}

int	get_element_type(char *line)
{
	t_etype	type;

	type = PARSE_UNKNOWN;
	if (!ft_strncmp(line, "NO", 2))
		type = PARSE_NORTH;
	else if (!ft_strncmp(line, "SO", 2))
		type = PARSE_SOUTH;
	else if (!ft_strncmp(line, "EA", 2))
		type = PARSE_EAST;
	else if (!ft_strncmp(line, "WE", 2))
		type = PARSE_WEST;
	else if (!ft_strncmp(line, "F", 1))
		type = PARSE_FLOOR;
	else if (!ft_strncmp(line, "C", 1))
		type = PARSE_CEILING;
	else if (line[0] && (line[0] == '0' || line[0] == '1'))
		type = PARSE_MAP;
	return (type);
}

void	fetch_file(t_scene *scene, int len)
{
	char	*line;
	t_etype	type;
	int		i;

	i = 0;
	while (scene->file && scene->file[i])
	{
		line = scene -> file[i];
		trim_spaces(scene, &line);
		type = get_element_type(line);
		if (type == PARSE_UNKNOWN)
		{
			perror_and_exit(scene, "The .cub file has some"
				"undesired inputs", 1);
		}
		fill_data(scene, type, line);
		if (type == PARSE_MAP)
		{
			parse_map(scene, i, len);
			break ;
		}
		scene->total_attr++;
		i++;
	}
}

t_scene	*parsing_main(char **argv)
{
	t_scene	*scene;
	int		len;

	if (!file_valid(argv[1]))
		return (NULL);
	scene = ft_calloc(1, sizeof(t_scene));
	if (!scene)
		perror_and_exit(scene, "Error malloc failed.", 1);
	scene->cieling_color = malloc(sizeof(int) * 3);
	if (!scene -> cieling_color)
		perror_and_exit(scene, "Error malloc failed.", 1);
	scene->floor_color = malloc(sizeof(int) * 3);
	if (!scene->floor_color)
		perror_and_exit(scene, "Error malloc failed.", 1);
	len = compress_file(scene, argv[1]);
	fetch_file(scene, len);
	check_if_data_fetched(scene);
	return (scene);
}
