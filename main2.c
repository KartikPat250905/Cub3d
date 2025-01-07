#include "includes/cub3d.h"


static void	draw_column(t_game *game, int x)
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	color1;
	int	color2;


	line_height = (int)(SCREEN_H / game->ray.p_dist);
	draw_start = -line_height / 2 + SCREEN_H / 3;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + SCREEN_H / 2;
	if (draw_end > SCREEN_H)
		draw_end = SCREEN_H - 1;
	color1 = 0xFF0000FF;
	color2 = 0x00000FF;
	while (draw_start < draw_end)
	{
		if (game->ray.side == 1)
			mlx_put_pixel(game->mlx->img, x, draw_start, color1);
		else
			mlx_put_pixel(game->mlx->img, x, draw_start, color2);
		draw_start++;
	}
}

void	background_color(t_mlx *mlx, unsigned int color)
{
	uint32_t	y;
	uint32_t	x;

	y = 0;
	x = 0;
	while (y < mlx -> img -> height)
	{
		x = 0;
		while (x < mlx -> img -> width)
		{
			mlx_put_pixel(mlx -> img, x, y, color);
			x++;
		}
		y++;
	}
}

static void	calculate_step_and_dist(t_player *plr, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->s_dist_x = (plr->pos_x - ray->map_x) * ray->d_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->s_dist_x = (ray->map_x + 1 - plr->pos_x) * ray->d_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->s_dist_y = (plr->pos_y - ray->map_y) * ray->d_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->s_dist_y = (ray->map_y + 1 - plr->pos_y) * ray->d_dist_y;
	}
}

static void	update_values(t_player *plr, t_ray *ray, int x)
{
	ray->hit = 0;

	// Our horizontal position on the screen
	ray->cam_x = 2 * x / (float)SCREEN_W - 1;

	// Direction vector of the current ray
	ray->dir_x = plr->dir_x + plr->pln_x * ray->cam_x;
	ray->dir_y = plr->dir_y + plr->pln_y * ray->cam_x;

	// Which box of the map we're in
	ray->map_x = (int)plr->pos_x;
	ray->map_y = (int)plr->pos_y;

	// Distance until next vertical grid side
	if (ray->dir_x == 0)
		ray->d_dist_x = 1e30;
	else
		ray->d_dist_x = sqrt(1 + (ray->dir_y * ray->dir_y) / (ray->dir_x * ray->dir_x));
	// Distance until next horizontal grid side
	if (ray->dir_y == 0)
		ray->d_dist_y = 1e30;
	else
		ray->d_dist_y = sqrt(1 + (ray->dir_x * ray->dir_x) / (ray->dir_y * ray->dir_y));
	// Get the absolute value for distance
	if (ray->d_dist_x < 0)
		ray->d_dist_x *= (-1);
	if (ray->d_dist_y < 0)
		ray->d_dist_y *= (-1);

	calculate_step_and_dist(plr, ray);
	
	/*
	printf("---\n");
	printf("ray map_x : %d\n", ray->map_x);
	printf("ray map_y : %d\n", ray->map_y);
	printf("plr_x = %f\n", plr->pos_x);
	printf("plr_y = %f\n", plr->pos_y);
	printf("plr dir_x = %f\n", plr->dir_x);
	printf("plr dir_y = %f\n", plr->dir_y);
	printf("ray dir_x = %f\n", ray->dir_x);
	printf("ray dir_y = %f\n", ray->dir_y);*/
}
static	int	raycast_loop(t_game *game, t_scene *scene, t_player *plr, t_ray *ray)
{
	int	x;

	x = -1;
	background_color(game->mlx, 0x0000FFFF);
	while (++x < SCREEN_W)
	{
		update_values(plr, ray, x);
		while (!ray->hit) // What if no hit?
		{
			if (ray->s_dist_x < ray->s_dist_y)
			{
				ray->s_dist_x += ray->d_dist_x;
				ray->map_x += ray->step_x;
				ray->side = 0;
			}
			else
			{
				ray->s_dist_y += ray->d_dist_y;
				ray->map_y += ray->step_y;
				ray->side = 1;
			}
			if (scene->map && scene->map[ray->map_x] && scene->map[ray->map_x][ray->map_y] == '1')
			if (scene->map && scene->map[ray->map_x] && scene->map[ray->map_x][ray->map_y] == '1')
			{
				printf("A wall was hit!\n");
				printf("x : %d, y : %d\n", ray->map_x, ray->map_y);
				printf("Map location char : %c\n", scene->map[ray->map_x][ray->map_y]);
				printf("ray->s_dist_x : %f, ray->s_dist_y : %f\n", ray->s_dist_x, ray->s_dist_y);
				printf("ray->d_dist_x : %f, ray->d_dist_y : %f\n", ray->d_dist_x, ray->d_dist_y);
				ray->hit = 1;
			}
		}
		if (ray->side == 0)
			ray->p_dist = ray->s_dist_x - ray->d_dist_x;
		else
			ray->p_dist = ray->s_dist_y - ray->d_dist_y;
		draw_column(game, x);
	}
	if (mlx_image_to_window(game->mlx->mlx, game->mlx->img, 0, 0) < 0)
		exit (1);
	return (0);
}

static void game_loop(void *ptr)
{
	t_game *game;

	game = (t_game *)ptr;
	raycast_loop(game, game->scene, game->plr, &game->ray);
}

int	main(int ac, char **av)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!init_game(game, ac, av))
		return (1);
	mlx_loop_hook(game->mlx->mlx, game_loop, (void *)game);
	mlx_key_hook(game->mlx->mlx, key_hook, (void *)game);
	mlx_loop(game->mlx->mlx);
	return (0);
}
