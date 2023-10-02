/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabatie <lsabatie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 01:45:07 by lsabatie          #+#    #+#             */
/*   Updated: 2023/07/20 01:45:07 by lsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_wdcounter(char const *str, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

int	get_height(char *file_name)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		exit(1);
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			height++;
			free(line);
		}
		else
			break ;
	}
	close (fd);
	return (height);
}

int	get_width(char *file_name)
{
	char	*line;
	int		fd;
	int		width;

	width = 0;
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		exit(1);
	line = get_next_line(fd);
	width = ft_wdcounter(line, ' ');
	free(line);
	close (fd);
	return (width);
}

void	fill_matrix(int *z_line, char *line, int width)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i] && i < width)
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	while (nums[i])
	{
		free(nums[i]);
		i++;
	}
	free(nums);
}

void	read_file(char *file_name, t_fdf *data)
{
	int		fd;
	int		i;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z_matrix = malloc(sizeof(int *) * (data->height + 1));
	if (data->z_matrix == NULL)
		return ;
	malloc_z_matrix(data);
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
	{
		i = data->height;
		while (i >= 0)
		{
			free(data->z_matrix[i]);
			i--;
		}
		free(data->z_matrix);
		exit(1);
	}
	fill_z_matrix(data, fd);
	close(fd);
}
