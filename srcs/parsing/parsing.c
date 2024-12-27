#include "cub3d.h"

/*
1. The map must be closed i.e surrounded by walls.
2. Except for the map content(0 and 1), each type of element can be separated by one or more empty line(s).
3. Except for the map content which always has to be the last, each type of element(texture and floor color) can be set in any order in the file.
4. Except for the map, each type of information from an element can be separated by one or more space(s).
5. Identifier is the first thing on the line followed by spaces and then the path or color
6. rgb range is [0,255]
7. Map might contain exmpty spaces.
*/

int	file_valid(char *file)
{
	int	i;
	int	fd;

	i = 0;
	while(file[i])
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
			perror("Error opening file");
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
	if (!ft_strcmp(line, "NO"))
		type = PARSE_NORTH;
	else if (!ft_strcmp(line, "SO"))
		type = PARSE_SOUTH;
	else if (!ft_strcmp(line, "EA"))
		type = PARSE_EAST;
	else if (!ft_strcmp(line, "WE"))
		type = PARSE_WEST;
	else if (!ft_strcmp(line, "F"))
		type = PARSE_FLOOR;
	else if (!ft_strcmp(line, "C"))
		type = PARSE_CEILING;
	else if (line[0] && line[0] == '0' || line[0] == '1')
		type = PARSE_MAP;
	return (type);
}

void	fetch_file(t_scene *scene)
{
	char	*line;
	t_etype	type;
	int		i;

	while (scene->file[i])
	{
		trim_spaces(&line);
		if (line == NULL)
			return ;
		type = get_element_type(line);
		if (type == PARSE_UNKNOWN)
		{
			//free and exit
			return;
		}
		fill_data(scene, type, line);
		i++;
	}
}

t_scene	*parsing_main(char **argv)
{
	t_scene	*scene;
	//int		fd;

	if (!file_valid(argv[1]))
		return (NULL);
	scene = malloc(sizeof(t_scene));
	compress_file(scene, argv[1]);
	fetch_file(scene);
	return (scene);
}