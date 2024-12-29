#include "cub3d.h"

void	is_valid(t_scene *scene, int index, int character)
{
	char	**file;
	int		j;

	file = scene -> file;
	while (file[index])
	{
		j = 0;
		while (file[index][j])
		{
			if (file[index][j] != '1' && file[index][j] != '0' && file[index][j] != 'N'
					&& file[index][j] != 'S' && file[index][j] != 'W' && file[index][j] != 'E' && file[index][j] != ' ')
				free_and_exit(scene, 1);
			if (file[index][j] == 'N' || file[index][j] == 'S' || file[index][j] == 'W' || file[index][j] == 'E')
			{
				if (character)
					free_and_exit(scene, 1);
				character = 1;
			}
			j++;
		}
		index++;
	}
	if (!character)
		free_and_exit(scene, 1);
}

/*
	borders : [0][i] [len][i] [i][0] [i][strlen(line)]
	maybe spaces can come in borders
*/
void	check_borders(t_scene *scene, int index, int len)
{
	int		i;
	char	**file;

	file = scene->file;
	i = 0;
	while (file[index][i])
	{
		if (file[index][i] != '1')
			free_and_exit(scene, 1);
		i++;
	}
	i = 0;
	while (file[len][i])
	{
		if (file[len][i] != '1' && file[len][i] != ' ')
			free_and_exit(scene, 1);
		change_space(file, len, i, 1);
		i++;
	}
	i = index;
	while (file[i] && file[i][0])
	{
		if (file[i][0] != '1')
			free_and_exit(scene, 1);
		i++;
	}
	i = index;
	while (file[i] && file[i][ft_strlen(file[i]) - 1])
	{
		if (file[i][ft_strlen(file[i]) - 1] != '1')
			free_and_exit(scene, 1);
		i++;
	}
}

void	check_if_cub_valid(t_scene *scene, int index, int len)
{
	is_valid(scene, index, 0);
	check_borders(scene, index, len - 1);
}

void	parse_map(t_scene *scene, int index, int len)
{
	check_if_cub_valid(scene, index, len);
}