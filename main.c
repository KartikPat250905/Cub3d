#include "./includes/cub3d.h"

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

float distance_calc(float x, float y, float x1, float y1)
{
	return (sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y)));
}

// int	is_wall(t_data *data, int x, int y)
// {
// 	int map_x = (int)(x / TILE_SIZE);
// 	int map_y = (int)(y / TILE_SIZE);

// 	if (map_y >= 0 && data->scene->map[map_y] != NULL)
// 	{
// 		int map_width = strlen(data->scene->map[map_y]);
// 		if (map_x >= 0 && map_x < map_width)
// 		{
// 			if (data->scene->map[map_y][map_x] == '1')
// 				return 1;
// 		}
// 	}
// 	return 0;
// }

// float	main_dda(t_data *data, t_dda *vars)
// {
// 	while (1)
// 	{
// 		vars->distance_hor = distance_calc(vars->hor_xn, vars->hor_yn,
// 				vars->hor_xn + vars->hor_step_x, vars->hor_yn + vars->hor_step_y);
// 		vars->hor_xn += vars->hor_step_x;
// 		vars->hor_yn += vars->hor_step_y;
// 		if (is_wall(data, vars->hor_xn, vars->hor_yn))
// 			break ;
// 		vars->distance_vert = distance_calc(vars->vert_xn, vars->vert_yn,
// 				vars->vert_xn + vars->vert_step_x, vars->vert_yn + vars->vert_step_y);
// 		vars->vert_xn += vars->vert_step_x;
// 		vars->vert_yn += vars->vert_step_y;
// 		if (is_wall(data, vars->vert_xn, vars->vert_yn))
// 			break ;
// 	}
// 	if (vars->distance_hor > vars->distance_vert)
// 		return (vars->distance_vert);
// 	return (vars->distance_hor);
// }

// float	dda(t_data *data, float angle)
// {
// 	t_dda	vars;

// 	ft_bzero(&vars, sizeof(t_dda));
// 	vars.tile_x = (int)data->player.x / TILE_SIZE;
// 	vars.tile_y = (int)data->player.y / TILE_SIZE;
// 	vars.dx = cos(angle);
// 	vars.dy = sin(angle);
// 	vars.hor_step_y = TILE_SIZE;
// 	vars.hor_step_x = vars.hor_step_y / tan(angle);
// 	if (angle > PI)
// 		vars.hor_step_y *= -1;
// 	if ((angle > PI_2 && angle < 3 * PI_2))
// 		vars.hor_step_x *= -1;
// 	vars.vert_step_x = TILE_SIZE;
// 	vars.vert_step_y = vars.vert_step_x * tan(angle);
// 	if ((angle > PI_2 && angle < 3 * PI_2))
// 		vars.vert_step_x *= -1;
// 	if (angle > PI)
// 		vars.vert_step_y *= -1;

// 	if (angle < PI)
// 		vars.hor_yn = floor(data->player.y / TILE_SIZE) * TILE_SIZE;
// 	else if (angle > PI)
// 		vars.hor_yn = ceil(data->player.y / TILE_SIZE) * TILE_SIZE;
// 	if (angle != 0 && angle != PI)
// 		vars.hor_xn = fabs(vars.hor_yn - data->player.y) / tan(angle);
// 	else
// 		vars.hor_xn = 0;

// 	if ((angle > PI_2 && angle < 3 * PI_2))
// 		vars.vert_xn = floor(data->player.x / TILE_SIZE) * TILE_SIZE;
// 	else
// 		vars.vert_xn = ceil(data->player.x / TILE_SIZE) * TILE_SIZE;
// 	if (angle != PI_2 && angle != 3 * PI_2)
// 		vars.vert_yn = fabs(vars.vert_xn - data->player.x) * tan(angle);
// 	else
// 		vars.vert_yn = 0;

// 	vars.distance_hor = distance_calc(data->player.x, data->player.y, vars.hor_xn, vars.hor_yn);
// 	vars.distance_vert = distance_calc(data->player.x, data->player.y, vars.vert_xn, vars.vert_yn);
// 	return (main_dda(data, &vars));
// }



// void	render_col(t_data *data, int x, float distance, int color)
// {
// 	int	wall_top;
// 	int	wall_bottom;
// 	int	wall_height;
// 	int	y;

// 	wall_height = (TILE_SIZE / distance) * 7;
// 	if (distance > MAX_DISTANCE)
// 		wall_height = 0;
// 	wall_top = (WIN_HEIGHT / 2) - (wall_height / 2);
// 	wall_bottom = (WIN_HEIGHT / 2) + (wall_height / 2);
// 	if (wall_top < 0)
// 		wall_top = 0;
// 	if (wall_bottom >= WIN_HEIGHT)
// 		wall_bottom = WIN_HEIGHT - 1;
// 	y = wall_top;
// 	while (y <= wall_bottom)
// 		mlx_put_pixel(data->img, x, y++, color);
// }

double normalize_angle(double angle)
{
	while (angle < -1 * PI)
		angle += 2 * PI;
	while (angle > PI)
		angle -= 2 * PI;
	return (angle);
}

int	is_wall(t_data *data, float ray_x, float ray_y)
{
	if (data->scene->map[(int)ray_y / TILE_SIZE][(int)ray_x / TILE_SIZE]
		&& data->scene->map[(int)ray_y / TILE_SIZE][(int)ray_x/ TILE_SIZE] == '1')
		return (1);
	return (0);
}

float	calculate_distance(t_data *data, float angle)
{
	float	ray_x;
	float	ray_y;

	ray_x = data->player.x;
	ray_y = data->player.y;
	while (!is_wall(data, ray_x, ray_y))
	{
		ray_x += cos(angle) * TILE_SIZE;
		ray_y += sin(angle) * TILE_SIZE;
	}
	return (distance_calc(data->player.x, data->player.y, ray_x, ray_y));
}

void	draw_wall_column(mlx_image_t *img, int screen_x, int start_y, int end_y)
{
	while (start_y != end_y)
	{
		if (start_y > 0 && start_y < WIN_HEIGHT)
			mlx_put_pixel(img, screen_x, start_y, 0xFFFFFF);
		start_y++;
	}
}

void	draw_rays(t_data *data)
{
	float	angle;
	int		screen_x;
	float	distance;
	float	corrected_distance;
	int		wall_height;
	int		start_y;
	int		end_y;

	angle = normalize_angle(data->player.angle - FOV / 2);
	screen_x = 0;
	while (screen_x < WIN_WIDTH)
	{
		distance = calculate_distance(data, angle);
		corrected_distance = distance * cos(angle - data->player.angle);
		if (corrected_distance < 0.1)
			corrected_distance = 0.1;
		wall_height = (TILE_SIZE / corrected_distance) * 600;
		start_y = (WIN_HEIGHT / 2) - (wall_height / 2);
		end_y = (WIN_HEIGHT / 2) + (wall_height / 2);
		if (start_y < 0)
			start_y = 0;
		if (end_y >= WIN_HEIGHT)
			end_y = WIN_HEIGHT - 1;
		draw_wall_column(data->img, screen_x, start_y, end_y);
		angle += FOV / WIN_WIDTH;
		screen_x++;
	}
}

void	render(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			mlx_put_pixel(data->img, x++, y, 0x0000FF);
		}
		y++;
	}
	draw_rays(data);
}

int	main(int ac, char **av)
{
	t_scene	*scene;
	t_data	data;

	if (ac != 2)
		return 1;
	scene = parsing_main(av);
	printf("The north texture is %s\n", scene -> north);
	printf("The sorth texture is %s\n", scene -> south);
	printf("The east texture is %s\n", scene -> east);
	printf("The west texture is %s\n", scene -> west);
	printf("The floor R=%d G=%d and B=%d\n", scene -> floor_color[0], scene->floor_color[1],scene->floor_color[2]);
	printf("The cieling R=%d G=%d and B=%d\n", scene -> cieling_color[0], scene->cieling_color[1],scene->cieling_color[2]);
	int i = 0;
	data.player.x = 2 * TILE_SIZE;
	data.player.y = 3 * TILE_SIZE;
	data.player.angle = 0.0;
	printf("The direction of the player is %f from x axis\n", data.player.angle);
	while (scene->map[i])
		printf("%s\n",scene->map[i++]);
	data.mlx = mlx_init(WIN_WIDTH, WIN_HEIGHT, "Cub3d", false);
	if (!data.mlx)
		return (1);
	data.img = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data.img)
		return (1);
	data.scene = scene;
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	mlx_loop_hook(data.mlx, (void (*)(void *))render, &data);
	mlx_loop(data.mlx);
	mlx_key_hook(data.mlx, handle_keys, (void *)&data);
	free_and_exit(scene, 0);
}
