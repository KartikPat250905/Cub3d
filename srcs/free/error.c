#include "cub3d.h"

void	perror_and_exit(t_scene *scene, char *str, int exit)
{
	printf("Error\n");
	printf("%s\n", str);
	free_and_exit(scene, exit);
}