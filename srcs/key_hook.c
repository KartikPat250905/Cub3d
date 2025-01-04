#include "cub3d.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param->mlx;
	// ESC to escape
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		free_and_exit(param->screen, EXIT_SUCCESS);
	
	// WASD to move
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move(mlx, UP);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move(mlx, DOWN);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move(mlx, LEFT);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move(mlx, RIGHT);

	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		return ;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		return ;
	// draw_image(mlx);
}
