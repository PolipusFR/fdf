/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabatie <lsabatie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:38:32 by lsabatie          #+#    #+#             */
/*   Updated: 2022/12/05 14:38:34 by lsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*tmpdst;
	char	*tmpsrc;

	if (!dst && !src)
		return (NULL);
	i = 0;
	tmpdst = (char *)dst;
	tmpsrc = (char *)src;
	while (n > 0)
	{
		tmpdst[i] = tmpsrc[i];
		n--;
		i++;
	}
	return (dst);
}
