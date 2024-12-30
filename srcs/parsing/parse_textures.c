#include "cub3d.h"

void	parse_north(t_scene *scene, char *line)
{
	int	i;
	int	start;

	start = get_path(scene, line, 2);
	i = open(line + start, O_RDONLY);
	if (i < 0)
		perror_and_exit(scene, "Open failed north", 1);
	close(i);
	scene->north = ft_strdup(line + start);
}

void	parse_south(t_scene *scene, char *line)
{
	int	i;
	int	start;

	start = get_path(scene, line, 2);
	i = open(line + start, O_RDONLY);
	if (i < 0)
		perror_and_exit(scene, "Open failed south", 1);
	close(i);
	scene->south = ft_strdup(line + start);
}

void	parse_east(t_scene *scene, char *line)
{
	int	i;
	int	start;

	start = get_path(scene, line, 2);
	i = open(line + start, O_RDONLY);
	if (i < 0)
		perror_and_exit(scene, "Open failed east", 1);
	close(i);
	scene->east = ft_strdup(line + start);
}

void	parse_west(t_scene *scene, char *line)
{
	int	i;
	int	start;

	start = get_path(scene, line, 2);
	i = open(line + start, O_RDONLY);
	if (i < 0)
		perror_and_exit(scene, "Open failed west", 1);
	close(i);
	scene->west = ft_strdup(line + start);
}
