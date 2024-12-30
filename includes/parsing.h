#ifndef PARSING_H
# define PARSING_H

# include <stddef.h>

typedef struct s_scene
{
	int		**map;
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		*floor_color;
	int		*cieling_color;
	char	**file;
}				t_scene;

typedef enum e_type t_etype;

void	free_and_exit(t_scene *scene, int code);
int		get_path(t_scene *scene, char *line, int i);
void	parse_north(t_scene *scene, char *line);
void	parse_south(t_scene *scene, char *line);
void	parse_east(t_scene *scene, char *line);
void	parse_west(t_scene *scene, char *line);
void	fill_data(t_scene *scene, t_etype type, char *line, int num, int len);
void	parse_color(t_scene *scene, char *line, int is_cieling);
void	get_colors(t_scene *scene, char *line, int who);
void	add_rgb(t_scene *scene, char **splits, int who);
void	parse_map(t_scene *scene, int index, int len);
void	change_space(char **file, int row, int col, int ch);


#endif
