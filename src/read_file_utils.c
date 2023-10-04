/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabatie <lsabatie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:55:29 by lsabatie          #+#    #+#             */
/*   Updated: 2023/10/04 17:45:32 by lsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	malloc_z_matrix(t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		data->z_matrix[i] = malloc(sizeof(int) * (data->width + 1));
		if (data->z_matrix[i] == NULL)
		{
			i--;
			while (i >= 0)
			{
				free(data->z_matrix[i]);
				i--;
			}
			free(data->z_matrix);
			return ;
		}
		i++;
	}
	return ;
}

void	fill_z_matrix(t_fdf *data, int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (i < data->height + 1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		fill_matrix(data->z_matrix[i], line, data->width);
		free(line);
		i++;
	}
}
