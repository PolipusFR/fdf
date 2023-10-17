/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabatie <lsabatie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 20:40:35 by lsabatie          #+#    #+#             */
/*   Updated: 2023/10/17 14:46:34 by lsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	data_setup_line_algo(t_fdf *data, int x, int y, int variation)
{
	if (variation == 1)
	{
		data->x = x;
		data->x1 = x + 1;
		data->y = y;
		data->y1 = y;
		line_algo(data);
	}
	else
	{
		data->x = x;
		data->x1 = x;
		data->y = y;
		data->y1 = y + 1;
		line_algo(data);
	}
	return ;
}

void	line_algo_setup(t_fdf *data)
{
	int	z;
	int	z1;

	z = data->z_matrix[(int)data->y][(int)data->x];
	z1 = data->z_matrix[(int)data->y1][(int)data->x1];
	z *= data->move_z;
	z1 *= data->move_z;
	if (z || z1)
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;
	data->x *= data->zoom;
	data->y *= data->zoom;
	data->x1 *= data->zoom;
	data->y1 *= data->zoom;
	perspective(&data->x, &data->y, z);
	perspective(&data->x1, &data->y1, z1);
	data->x += data->move_x;
	data->x1 += data->move_x;
	data->y += data->move_y;
	data->y1 += data->move_y;
}

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		data->addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel,
				&data->line_length, &data->endian);
		dst = data->addr + (y * data->line_length + x
				* (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
