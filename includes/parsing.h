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
	int		floor_color[3];
	int		cieling_color[3];
	char	**file;
}				t_scene;

typedef enum e_type t_etype;

void	free_and_exit(t_scene *scene, int code);
int		get_path(t_scene *scene, char *line);
void	parse_north(t_scene *scene, char *line);
void	parse_south(t_scene *scene, char *line);
void	parse_east(t_scene *scene, char *line);
void	parse_west(t_scene *scene, char *line);
void	fill_data(t_scene *scene, t_etype type, char *line);

#endif
