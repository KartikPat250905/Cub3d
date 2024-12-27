#include "./includes/cub3d.h"

int	main(int ac, char **av)
{
	t_scene	*scene;

	if (ac != 2)
		return 1;
	scene = parsing_main(av);
	printf("The north texture is %s\n", scene -> north);
	printf("The sorth texture is %s\n", scene -> south);
	printf("The east texture is %s\n", scene -> east);
	printf("The west texture is %s\n", scene -> west);
}
