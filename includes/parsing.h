#ifndef PARSING_H
# define PARSING_H

typedef struct s_scene
{
	char	**map;
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	int		floor_color[3];
	int		cieling_color[3];
	char	**file;
}				t_scene;


#endif
