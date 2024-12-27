#include "cub3d.h"

int	get_path(t_scene *scene, char *line)
{
	int	start;
	int	i;

	i = 2;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (i == 2)
	{
		printf("Error with the path for the texture\n");
		free_and_exit(scene, 1);
	}
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
	// else if (type == PARSE_CEILING)
	// 	parse_ceiling(scene, line);
	// else if (type == PARSE_FLOOR)
	// 	parse_floor(scene, line);
	// else if (type == PARSE_MAP)
	// 	parse_map(scene, line);
}
