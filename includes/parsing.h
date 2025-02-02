/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karpatel <karpatel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:56:35 by karpatel          #+#    #+#             */
/*   Updated: 2025/01/10 14:56:37 by karpatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stddef.h>

typedef struct s_scene
{
	char	**map;
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		*floor_color;
	int		*cieling_color;
	char	**file;
	int		total_attr;
	int		has_map;
	int		has_north;
	int		has_south;
	int		has_east;
	int		has_west;
	int		has_floor;
	int		has_ciel;
	int		map_started;
}				t_scene;

typedef enum e_type	t_etype;

void	check_if_data_fetched(t_scene *scene);
void	free_and_exit(t_scene *scene, int code);
int		get_path(t_scene *scene, char *line, int i);
void	parse_north(t_scene *scene, char *line);
void	parse_south(t_scene *scene, char *line);
void	parse_east(t_scene *scene, char *line);
int		check_duplicates(t_scene *scene);
void	parse_west(t_scene *scene, char *line);
int		is_map_line(char *line);
void	fill_data(t_scene *scene, t_etype type, char *line);
void	parse_color(t_scene *scene, char *line, int is_cieling);
void	get_colors(t_scene *scene, char *line, int who);
void	add_rgb(t_scene *scene, char **splits, int who, char *no_spaces);
void	parse_map(t_scene *scene, int index, int len);
void	validate_row_extension(t_scene *scene, int index);
void	change_space(char **file, int row, int col, int ch);
int		empty_line(char *line);
int		get_element_type(char *line);
void	reset_scene_attributes(t_scene *scene);

#endif
