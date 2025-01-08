/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karpatel <karpatel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:14:42 by karpatel          #+#    #+#             */
/*   Updated: 2025/01/08 12:14:44 by karpatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_west_and_east(t_player *plr, char dir)
{
	if (dir == 'W')
	{
		plr->dir_x = -1;
		plr->dir_y = 0;
		plr->pln_x = 0;
		plr->pln_y = -1;
	}
	else if (dir == 'E')
	{
		plr->dir_x = 1;
		plr->dir_y = 0;
		plr->pln_x = 0;
		plr->pln_y = 1;
	}
}
