#include "libft.h"

int	ft_isspace(char ch)
{
	if (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r')
		return (1);
	return (0);
}