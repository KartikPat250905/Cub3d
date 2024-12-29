#include "cub3d.h"

void	change_space(char **file, int row, int col, int ch)
{
	if (file[row][col] != ' ')
		return ;
	if (ch == 1)
		file[row][col] = '1';
	if (ch == 0)
		file[row][col] = '0';
}