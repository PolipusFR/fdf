/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabatie <lsabatie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 02:02:01 by lsabatie          #+#    #+#             */
/*   Updated: 2023/07/20 02:02:01 by lsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../libft/libft.h"
#include "../libft/ft_printf/ft_printf.h"

int	deal_key(int key, t_fdf *data)
{
	if (key == 65362)
		data->move_y += 20;
	if (key == 65361)
		data->move_x += 20;
	if (key == 65364)
		data->move_y -= 20;
	if (key == 65363)
		data->move_x -= 20;
	if (key == 65451)
		data->zoom += 1;
	if (key == 65453)
		data->zoom -= 1;
	if (key == 106)
		data->move_z -= 1;
	if (key == 107)
		data->move_z += 1;
	if (key == 65307)
	{
		exit (0);
	}
	if (data->zoom < 0)
		data->zoom = 0;
	draw(data);
	return (0);
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

static void	print_error(void)
{
	printf("Error. Usage : ./fdf map\n");
	exit(1);
}

int	main(int ac, char **av)
{
	t_fdf	*data;
	int		i;

	if (ac != 2)
		print_error();
	data = malloc(sizeof(t_fdf));
	if (!data)
		return (0);
	read_file (av[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, av[1]);
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->zoom = 20;
	data->move_x = 0;
	data->move_y = 0;
	data->move_z = 1;
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	while (i < data->height)
		free(data->z_matrix[i++]);
	free(data->z_matrix);
}
