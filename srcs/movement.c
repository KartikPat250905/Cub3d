/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motuomin <motuomin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:35:56 by motuomin          #+#    #+#             */
/*   Updated: 2025/02/03 11:57:59 by jelloster        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	move_plr(float move_x, float move_y, t_player *p, t_scene *s)
{
	if (s->map[(int)p->pos_y][(int)(p->pos_x + move_x)] != '0'
		&& s->map[(int)p->pos_y][(int)(p->pos_x + move_x)] != '1')
		s->map[(int)p->pos_y][(int)(p->pos_x + move_x)] = '0';
	if (s->map[(int)p->pos_y][(int)(p->pos_x + move_x)] == '0')
		p->pos_x += move_x ;
	if (s->map[(int)(p->pos_y + move_y)][(int)p->pos_x] == '0')
		p->pos_y += move_y;
}

void	move(t_scene *s, t_player *p, t_dir dir)
{
	float	move_x;
	float	move_y;

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

void	rotate(t_player *p, t_dir dir)
{
	float	old_dir_x;
	float	old_pln_x;

	old_dir_x = p->dir_x;
	old_pln_x = p->pln_x;
	if (dir == LEFT)
	{
		p->dir_x = p->dir_x * cos(-R_SPEED) - p->dir_y * sin(-R_SPEED);
		p->dir_y = old_dir_x * sin(-R_SPEED) + p->dir_y * cos(-R_SPEED);
		p->pln_x = p->pln_x * cos(-R_SPEED) - p->pln_y * sin(-R_SPEED);
		p->pln_y = old_pln_x * sin(-R_SPEED) + p->pln_y * cos(-R_SPEED);
	}
	else
	{
		p->dir_x = p->dir_x * cos(R_SPEED) - p->dir_y * sin(R_SPEED);
		p->dir_y = old_dir_x * sin(R_SPEED) + p->dir_y * cos(R_SPEED);
		p->pln_x = p->pln_x * cos(R_SPEED) - p->pln_y * sin(R_SPEED);
		p->pln_y = old_pln_x * sin(R_SPEED) + p->pln_y * cos(R_SPEED);
	}
}
