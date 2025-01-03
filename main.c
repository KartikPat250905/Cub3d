#include "./includes/cub3d.h"

void	draw_square(mlx_image_t *image, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			if (i == 0 || i == TILE_SIZE - 1 || j == 0 || j == TILE_SIZE - 1)
				mlx_put_pixel(image, x + i, y + j, 0xFF0000);
			else
				mlx_put_pixel(image, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	render(t_data *data)
{
	mlx_delete_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	draw_square(data->img, 1, 1, 0x000000);
}

int	main(int ac, char **av)
{
	t_scene	*scene;
	//t_data	data;

	if (ac != 2)
		return 1;
	scene = parsing_main(av);
	printf("The north texture is %s\n", scene -> north);
	printf("The sorth texture is %s\n", scene -> south);
	printf("The east texture is %s\n", scene -> east);
	printf("The west texture is %s\n", scene -> west);
	printf("The floor R=%d G=%d and B=%d\n", scene -> floor_color[0], scene->floor_color[1],scene->floor_color[2]);
	printf("The cieling R=%d G=%d and B=%d\n", scene -> cieling_color[0], scene->cieling_color[1],scene->cieling_color[2]);
	// int i = 0;
	// data.player.x = 1;
	// data.player.y = 1;
	// data.player.angle = 0;
	// while (scene->map[i])
	// 	printf("%s\n",scene->map[i++]);
	// data.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Cub3d", false);
	// if (!data.mlx)
	// 	return (1);
	// data.img = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	// if (!data.img)
	// 	return (1);
	// mlx_image_to_window(data.mlx, data.img, 0, 0);
	// mlx_loop_hook(data.mlx, (void (*)(void *))render, &data);
	// mlx_loop(data.mlx);
	// free_and_exit(scene, 0);
}
