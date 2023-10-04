/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabatie <lsabatie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:06:10 by lsabatie          #+#    #+#             */
/*   Updated: 2023/07/16 15:06:10 by lsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include "fcntl.h"
# include <math.h>

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_data
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;
	int		move_x;
	int		move_y;
	int		move_z;

	float	x;
	float	y;
	float	x1;
	float	y1;

	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	void	*img_ptr;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

void	fill_matrix(int *z_line, char *line, int width);
void	read_file(char *file_name, t_fdf *data);
void	line_algo(t_fdf *data);
void	draw(t_fdf *data);
void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color);
int		get_height(char *file_name);
void	malloc_z_matrix(t_fdf *data);
void	fill_z_matrix(t_fdf *data, int fd);
void	data_setup_line_algo(t_fdf *data, int x, int y, int variation);
void	line_algo_setup(t_fdf *data);
void	perspective(float *x, float *y, int z);

#endif