/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karpatel <karpatel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:07:06 by karpatel          #+#    #+#             */
/*   Updated: 2025/01/08 16:07:07 by karpatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_textures_mlx(t_mlx *mlx)
{
	if (mlx->t_n)
		mlx_delete_image(mlx->mlx, mlx->t_n);
	if (mlx->t_s)
		mlx_delete_image(mlx->mlx, mlx->t_s);
	if (mlx->t_e)
		mlx_delete_image(mlx->mlx, mlx->t_e);
	if (mlx->t_w)
		mlx_delete_image(mlx->mlx, mlx->t_w);
}
