#include "cub3d.h"

void print_map(char **map) {
    for (int i = 0; map[i]; i++) {
        for (int j = 0; map[i][j]; j++) {
                printf("%c ", map[i][j]); // Print the map element with a space
        }
        printf("\n"); // Newline after each row
    }
	printf("\n"); // Newline after each row
}
void	move(t_scene *s, t_player *p, t_dir dir)
{
	if (dir == UP)
	{
		//printf("Player pos before moving x: %f, y: %f\n", p->pos_x, p->pos_y);
		//printf("New x in int : %d\n", (int)(p->pos_x + p->dir_x * SPEED));
		//printf("New pos = %c\n", s->map[(int)(p->pos_x + p->dir_x * SPEED)][(int)p->pos_x]);
		//if (s->map[(int)(p->pos_x + p->dir_x * SPEED)][(int)p->pos_x] == 0)
		//{
		//§	printf("Position edited.\n");
		//
			s->map[(int)(p->pos_y)][(int)p->pos_x] = '0';
			p->pos_x += p->dir_x * SPEED;
		//}
		//if (!s->map[(int)(p->pos_y + p->dir_y * SPEED)][(int)p->pos_y])
		//{
		//	printf("Position edited.\n");
			p->pos_y += p->dir_y * SPEED;
			s->map[(int)p->pos_y][(int)(p->pos_x)] = 'C';
		//printf("%f + %f * %d = %f\n", p->pos_x, p->dir_x, SPEED, p->pos_x);
		//printf("Player pos x: %f, y: %f\n", p->pos_x, p->pos_y);
	}
	if (dir == DOWN)
	{
		//printf("Moving down\n");
		//if (!s->map[(int)(p->pos_x - p->dir_x * SPEED)][(int)p->pos_x])
			p->pos_x -= p->dir_x * SPEED;
		//if (!s->map[(int)(p->pos_y - p->dir_y * SPEED)][(int)p->pos_y])
			p->pos_y -= p->dir_y * SPEED;
		//printf("Player pos x: %f, y: %f\n", p->pos_x, p->pos_y);
	}
	print_map(s -> map);
	/*
	if (dir == LEFT)
	if (dir == RIGHT)*/
}
