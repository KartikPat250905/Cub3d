#include "cub3d.h"

//create get path to get the texture and check it
void	parse_north(t_scene *scene, char *line)
{
	int	i;
	int	start;

	i = 2;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (i == 2)
		return ;
	start = i;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			i++;
		else
		{
			printf("Error with path of the north texture");
			//free and exit
		}
	}
	i = open(line + start, O_RDONLY);
	if (i < 0)
		//free and exit
	close(i);
	scene->north = ft_strdup(line + start);
	if (!scene -> north)
		return ;
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