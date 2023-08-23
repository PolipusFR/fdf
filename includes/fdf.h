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

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;

	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

void    read_file(char *file_name, t_fdf *data);

#endif