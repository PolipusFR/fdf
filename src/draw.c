/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabatie <lsabatie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 12:18:18 by lsabatie          #+#    #+#             */
/*   Updated: 2023/08/31 19:31:16 by lsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"
#include "../libft/ft_printf/ft_printf.h"

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
	z *= data->move_z;
	z1 *= data->move_z;
	//-------------Color-------------//
	if (z || z1)
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;
	//------------- 3D  -------------//
	perspective(&x, &y, z);
	perspective(&x1, &y1, z1);
	//-------------Shift-------------//
	x += data->move_x;
	x1 += data->move_x;
	y += data->move_y;
	y1 += data->move_y;
	
	x_step = x1 - x;
	y_step = y1 - y;
	max = max_step (abs_val(x_step), abs_val(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		my_mlx_pixel_put(data, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}


void	draw(t_fdf *data)
{
	int	x;
	int	y;

	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
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
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}