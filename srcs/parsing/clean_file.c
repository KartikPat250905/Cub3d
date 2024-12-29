#include "cub3d.h"

void	trim_spaces(char **line)
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
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return ;
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
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n' && line[i] != '\r')
			return (0);
		i++;
	}
	return (1);
}

int	ft_count_flines(char *file)
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
		trim_spaces(&line);
		if (!empty_line(line))
			result++;
		free(line);
	}
	close(fd);
	return (result);
}

void	add_line_to_scene(t_scene *scene, char *line, int i)
{
	trim_spaces(&line);
	scene -> file[i] = line;
}

int	compress_file(t_scene *scene, char *file)
{
	int		fd;
	char	*line;
	int		i;

	scene -> file = malloc(sizeof(char *) * (ft_count_flines(file) + 2));
	fd = open(file, O_RDONLY);
	i = 0;
	while (get_line(&line, fd))
	{
		if (!empty_line(line))
		{
			add_line_to_scene(scene, line, i);
			i++;
		}
	}
	close(fd);
	return (i);
}