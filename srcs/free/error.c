/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karpatel <karpatel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 11:42:33 by karpatel          #+#    #+#             */
/*   Updated: 2025/01/08 11:43:04 by karpatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	perror_and_exit(t_scene *scene, char *str, int exit)
{
	printf("Error\n");
	printf("%s\n", str);
	free_and_exit(scene, exit);
}
