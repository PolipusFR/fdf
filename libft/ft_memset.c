/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabatie <lsabatie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:47:17 by lsabatie          #+#    #+#             */
/*   Updated: 2022/11/24 15:43:41 by lsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void	*b, int c, size_t len)
{
	int		i;
	char	*tmp;

	tmp = b;
	i = 0;
	while (len > 0)
	{
		tmp[i] = c;
		i++;
		len--;
	}
	return (b);
}
