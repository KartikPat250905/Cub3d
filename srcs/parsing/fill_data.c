#include "cub3d.h"

int	get_path(t_scene *scene, char *line, int i)
{
	int	start;
	int	j;

	j = i;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (i == j)
	{
		printf("Error with the path for the texture\n");
		free_and_exit(scene, 1);
	}
	start = i;
	return (start);
}

void	add_rgb(t_scene *scene, char **splits, int who)
{
	int	i;

	if (who == 0)
	{
		i = 0;
		while (i < 3)
		{
			scene -> floor_color[i] = ft_atoi(splits[i]);
			if (scene->floor_color[i] < 0 || scene->floor_color[i] > 255)
			{
				printf("Error with the color values.\n");
				free_and_exit(scene, 1);
			}
			i++;
		}
	}
}

void	get_colors(t_scene *scene, char *line, int who)
{
	char	*no_spaces;
	int		i;
	int		len;
	char	**splits;

	while (line[i])
	{
		if (!ft_isspace(line[i]))
			len++;
		i++;
	}
	no_spaces = malloc(sizeof(char) * len);
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
	//free the splits and other stuff
}

void	parse_cieling(t_scene *scene, char *line)
{
	int	i;
	int	start;

	start = get_path(scene, line, 1);
	i = open(line + start, O_RDONLY);
	if (i < 0)
	{
		printf("Open failed\n");
		free_and_exit(scene, 1);
	}
	close(i);
	get_colors(scene, line + start, 0);
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
	// else if (type == PARSE_FLOOR)
	// 	parse_floor(scene, line);
	// else if (type == PARSE_MAP)
	// 	parse_map(scene, line);
}
