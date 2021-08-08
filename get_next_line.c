#include "get_next_line.h"

int	get_next_line(char **line)
{
	int	i = -1, r = 0, l = 1;
	char 	*temp, c;

	if (!(*line = malloc(l)))
		return (-1);
	(*line)[0] = 0;
	while ((r = read(0, &c, 1)) && l++ && c != '\n')
	{
		if (!(temp = malloc(l)))
		{
			free(*line);
			return (-1);
		}
		i = -1;
		while (++i < l - 2)
			temp[i] = (*line)[i];
		temp[i] = c;
		temp[i + 1] = 0;
		free(*line);
		*line = temp;
	}
	return (r);
}
