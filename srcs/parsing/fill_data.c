#include "cub3d.h"

void	parse_north(t_scene *scene, char *line)
{

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
		parse_ceiling(scene, line);
	else if (type == PARSE_FLOOR)
		parse_floor(scene, line);
	else if (type == PARSE_MAP)
		parse_map(scene, line);
}