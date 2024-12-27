#include "cub3d.h"

void	parse_north(t_scene *scene, char *line)
{
	int	i;
	int	start;

	start = get_path(scene, line);
	i = open(line + start, O_RDONLY);
	if (i < 0)
	{
		printf("Open failed\n");
		free_and_exit(scene, 1);
	}
	close(i);
	scene->north = ft_strdup(line + start);
}

void	parse_south(t_scene *scene, char *line)
{
	int	i;
	int	start;

	start = get_path(scene, line);
	i = open(line + start, O_RDONLY);
	if (i < 0)
	{
		printf("Open failed\n");
		free_and_exit(scene, 1);
	}
	close(i);
	scene->south = ft_strdup(line + start);
}

void	parse_east(t_scene *scene, char *line)
{
	int	i;
	int	start;

	start = get_path(scene, line);
	i = open(line + start, O_RDONLY);
	if (i < 0)
	{
		printf("Open failed\n");
		free_and_exit(scene, 1);
	}
	close(i);
	scene->east = ft_strdup(line + start);
}

void	parse_west(t_scene *scene, char *line)
{
	int	i;
	int	start;

	start = get_path(scene, line);
	i = open(line + start, O_RDONLY);
	if (i < 0)
	{
		printf("Open failed\n");
		free_and_exit(scene, 1);
	}
	close(i);
	scene->west = ft_strdup(line + start);
}