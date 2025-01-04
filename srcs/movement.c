#include "cub3d.h"



void	move(t_game *game, t_screen *s, t_player *p, t_dir dir)
{
	int	dx;
	int	dy;

	dx = 0;
	dy = 0;
	if (dir == UP)
	{
		if (!s->map[int(p->pos_x + p->dir_x * SPEED)][int(p->pos_y)])
			p->pos_x += p->dir_x * SPEED;
		if(worldMap[int(posX)][int(posY + dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
		dy = 1;
	}
	if (dir == DOWN)
		dy = -1;
	if (dir == LEFT)
		dx = 1;
	if (dir == RIGHT)
		dx = -1;
}
