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

int		ft_wdcounter(char const *str, char c)
{
	int i;
	int words;

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

int get_height(char *file_name)
{
	int		fd;
	int		height;

	height = 0;
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		exit(1);
	while (get_next_line(fd))
		height++;
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

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void    read_file(char *file_name, t_fdf *data)
{
	int		fd;
	char	*line;
	int		i;

    data->height = get_height(file_name);
	data->width = get_width(file_name);

	data->z_matrix = malloc(sizeof(int*) * (data->height + 1));
	if (data->z_matrix == NULL)
		return ;
	i = 0;
	while (i <= data->height)
		data->z_matrix[i++] = malloc(sizeof(int) * (data->width + 1));
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		exit(1);
	i = 0;
	while (i < data->height)
	{
		line = get_next_line(fd);
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	close(fd);
	data->z_matrix[i] = NULL;
}
