/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabatie <lsabatie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:18:18 by lsabatie          #+#    #+#             */
/*   Updated: 2023/08/25 13:25:50 by lsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static float	abs_val(float a)
{
	if (a >= 0)
		return (a);
	else
		return (-a);
}

static int		max_step(float x, float y)
{
	if (x >= y)
		return (x);
	else
		return (y);
}

void	perspective(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void    line_algo(float x, float y, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];
	//-------------Zoom--------------//
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	
	//-------------Color-------------//
	data->color = (z || z1) ? 0xe80c0c : 0xffffff;
	//------------- 3D  -------------//
	perspective(&x, &y, z);
	perspective(&x1, &y1, z1);
	//-------------Shift-------------//
	x += 150;
	y += 150;
	x1 += 150;
	y1 += 150;
	
	x_step = x1 - x;
	y_step = y1 - y;
	max = max_step (abs_val(x_step), abs_val(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	draw(t_fdf *data)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				line_algo(x, y, x + 1, y, data);
			if (y < data->height - 1)
				line_algo(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
}