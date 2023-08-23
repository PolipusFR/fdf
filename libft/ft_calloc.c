/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabatie <lsabatie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:10:13 by lsabatie          #+#    #+#             */
/*   Updated: 2022/12/08 14:55:52 by lsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	if (count != 0 && size > ULLONG_MAX / count)
		return (NULL);
	mem = malloc (count * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, count * size);
	return (mem);
}
