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
		printf("'%s'\n",scene->file[i]);
		i++;
	}
	printf("The north texture is %s", scene -> north);
	printf("The sorth texture is %s", scene -> south);
	printf("The east texture is %s", scene -> east);
	printf("The west texture is %s", scene -> west);
}
