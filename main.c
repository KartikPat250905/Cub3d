#include "./includes/cub3d.h"

int	main(int ac, char **av)
{
	t_scene	*scene;
	int i = 0;

	if (ac != 2)
		return 1;
	scene = parsing_main(av);
	while(scene -> file[i])
	{
		printf("%s",scene->file[i]);
		i++;
	}
}