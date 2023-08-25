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
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "fcntl.h"
# include <math.h>

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;

	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

void    read_file(char *file_name, t_fdf *data);
void    line_algo(float x, float y, float x1, float y1, t_fdf *data);
void	draw(t_fdf *data);

#endif