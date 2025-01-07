#include "cub3d.h"

void	print_map(char **map)
{
	for (int i = 0; map[i]; i++)
	{
		for (int j = 0; map[i][j]; j++)
			printf("%c ", map[i][j]);
		printf("\n");
	}
	printf("\n");
}

static void	move_plr(float move_x, float move_y, t_player *p, t_scene *s)
{
	if (s->map[(int)p->pos_y][(int)(p->pos_x + move_x)] == '0')
	{
		s->map[(int)p->pos_y][(int)p->pos_x] = '0';
		p->pos_x += move_x ;
		s->map[(int)p->pos_y][(int)p->pos_x] = 'C';
	}
	if (s->map[(int)(p->pos_y + move_y)][(int)p->pos_x] == '0')
	{
		s->map[(int)p->pos_y][(int)p->pos_x] = '0';
		p->pos_y += move_y;
		s->map[(int)p->pos_y][(int)p->pos_x] = 'C';
	}
	print_map(s->map);
}


void	move(t_scene *s, t_player *p, t_dir dir)
{
	float move_x;
	float move_y;

	if (dir == UP || dir == DOWN)
	{
		move_x = p->dir_x;
		move_y = p->dir_y;
	}
	else
	{
		move_x = p->pln_x;
		move_y = p->pln_y;
	}
	if (dir == DOWN || dir == LEFT)
	{
		move_x *= -SPEED;
		move_y *= -SPEED;
	}
	else
	{
		move_x *= SPEED;
		move_y *= SPEED;
	}
	move_plr(move_x, move_y, p, s);
}

void	rotate(t_scene *s, t_player *p, t_dir dir)
{
	float	old_dir_x;
	float	old_pln_x;

	old_dir_x = p->dir_x;
	old_pln_x = p->pln_x;
	if (dir == LEFT)
	{
		p->dir_x = p->dir_x * cos(-SPEED) - p->dir_y * sin(SPEED);
		p->dir_y = old_dir_x * sin(-SPEED) + p->dir_y + cos(SPEED);
		p->pln_x = p->pln_x * cos(-SPEED) - p->pln_y * sin(SPEED);
		p->pln_y = old_pln_x * sin(-SPEED) + p->dir_y + cos(SPEED);
	}
	else
	{
		p->dir_x = p->dir_x * cos(SPEED) - p->dir_y * sin(SPEED);
		p->dir_y = old_dir_x * sin(SPEED) + p->dir_y + cos(SPEED);
		p->pln_x = p->pln_x * cos(SPEED) - p->pln_y * sin(SPEED);
		p->pln_y = old_pln_x * sin(SPEED) + p->dir_y + cos(SPEED);
	}
}
