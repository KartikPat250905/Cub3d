/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karpatel <karpatel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:34:09 by karpatel          #+#    #+#             */
/*   Updated: 2025/01/08 11:34:10 by karpatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	trim_spaces(t_scene *scene, char **line)
{
	size_t		start;
	size_t		end;
	size_t		len;
	char		*str;

	start = 0;
	end = ft_strlen(*line) - 1;
	while (start < end && ft_isspace((*line)[start]))
		start++;
	while (end > start && ft_isspace((*line)[end]))
		end--;
	if (start == 0 && end == ft_strlen(*line) - 1)
		return ;
	len = end - start;
	str = malloc(sizeof(char) * (len + 2));
	if (!str)
		perror_and_exit(scene, "Error malloc failed.", 1);
	ft_strlcpy(str, *line + start, len + 2);
	free(*line);
	*line = str;
}

int	empty_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t'
			&& line[i] != '\n' && line[i] != '\r')
			return (0);
		i++;
	}
	return (1);
}

int	ft_count_flines(t_scene *scene, char *file)
{
	int		fd;
	int		result;
	char	*line;

	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (0);
	}
	result = 0;
	while (get_line(&line, fd))
	{
		trim_spaces(scene, &line);
		if (!empty_line(line))
			result++;
		free(line);
	}
	close(fd);
	return (result);
}

void	add_line_to_scene(t_scene *scene, char *line, int i)
{
	trim_spaces(scene, &line);
	scene -> file[i] = line;
}

int	compress_file(t_scene *scene, char *file)
{
	int		fd;
	char	*line;
	int		i;

	scene->file = ft_calloc((ft_count_flines(scene, file) + 2), sizeof(char *));
	if (!scene -> file)
		perror_and_exit(scene, "Error malloc failed.", 1);
	fd = open(file, O_RDONLY);
	i = 0;
	while (get_line(&line, fd))
	{
		if (!empty_line(line))
		{
			add_line_to_scene(scene, line, i);
			i++;
		}
		else
			free(line);
	}
	close(fd);
	return (i);
}
