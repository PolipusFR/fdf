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

// ------------------------------------------- How to do -------------------------------------------
// 	1. read file
// 		- get height(how many lines) of text
// 		- get width(how many numbers in line)
// 		- allocate memory for **int by using width and height (look your ft_strsplit() )
// 		- read file and write number into **int matrix
// 				by using ft_strsplit() and atoi()
// 	--------------
// 	2. drawing line function (google Bresenham algorithm)
// 		- find by how much we need to increase x and by how much we need to increase y
// 			by using float. Example:
//   		x = 2; x1 = 4;
// 				y = 2; y1 = 6;
//  			steps for x: 2
// 				steps for y: 4
// 				that means that y should grow 2 times faster than x
// 				ewery loop step: y += 1 and x += 0.5
// 				after 4 steps x and y will be equal with x1, y1
// 
// 					real x:y		x:y     pixels				
// 			start:		2.0 : 2.0		2:2        .
// 			step1:		2.5 : 3.0		2:3        .
// 			step2:		3.0 : 4.0		3:4         .
// 			step3:		3.5 : 5.0		3:5         .
// 			step4:		4.0 : 6.0		4:6          .
// 
// 				that works because (float)2.5 turns to (int)2 in func. mlx_pixel_put()
// 	--------------
// 	3. function which draws lines beetwen every dot
// 		- examle:
// 				0.		0.		0.		0
// 				|		|		|		|
// 				
// 				0.		10.            10.            0
// 				|		|		|		|
// 				
// 				0.		10.            10.            0
// 				|		|		|		|
// 				
// 				0.		0.		0.		0
// 			'.' and '|'are lines between dots 
// 			every dot has two lines (right and down):	0.
//                                                                       |
// 	----------------
// 	4. adding 3D
// 		- change coordinates by using isometric formulas:
// 			x` = (x - y) * cos(angle)
// 			y` = (x + y) * sin(angle) - z
// 		- x` and y` are coordintes in 3D format (default angle 0.8)
// 	----------------
// 	5. adding donuses (move, rotation, zoom)
// 		- when you press button on keyboard the func. mlx_key_hook(win_ptr, deal_key, NULL);
// 			call the func. deal_key.
// 		- In the deal key func. you have to change some parametrs, clear the window with
// 			mlx_clear_window(mlx_ptr, win_ptr); and redraw the picture
// 	----------------
// 	6. error handling
// 		- check if argc == 2
// 		- check if file exists: if ((fd = open(file_name, O_RDONLY) > 0))
// 	----------------
// 	7. fix leaks
// 		- type leaks a.out or leaks fdf in your shell

//   ------------------------------- resourses --------------------------------
// 	--------------- 3D ------------------------------------------
// 		x` = (x - y) * cos(angle);
// 		y` = (x + y) * sin(angle) - z;
// 	-------------------------------------------------------------
// 	------- mlx_function ----------------------------------------
// 		void *mlx_ptr;
// 		void *win_prt;
// 
// 		mlx_ptr = mlx_init();
// 		win_prt = mlx_new_window(mlx_ptr, 1000, 1000, "FDF");
// 
// 		mlx_pixel_put(mlx_ptr, win_ptr, (int)x, (int)y, #color);
// 
// 		mlx_key_hook(win_ptr, deal_key, NULL);
// 		mlx_loop(mlx_ptr);
// 	--------------------------------------------------------------
// 	------- deal_key prototype -----------------------------------
// 		int		deal_key(int key, void *data);
// 	--------------------------------------------------------------
// 	colors:
// 		white = 0xffffff
// 		red = 0xe80c0c
// 	----------------------------
// 	frameworks:
// 		-framework OpenGL -framework AppKit

int		deal_key(int key, t_fdf *data)
{
    ft_printf("%d\n", key);
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
        exit (1);
	}
	draw(data);
    return (0);
}

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		data->addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel, &data->line_length,
									&data->endian);
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

int main(int ac, char **av)
{
	t_fdf	*data;

	
	if (ac != 2)
    {
        printf("Error. Usage : ./fdf map\n");
        exit(1);
    }
    data = malloc(sizeof(t_fdf));
    if (!data)
        return(0);
    read_file (av[1], data);

	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, av[1]);
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel, &data->line_length,
								&data->endian);
	data->zoom = 20;
	data->move_z = 1;
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
}
