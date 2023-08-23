/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabatie <lsabatie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:39:12 by lsabatie          #+#    #+#             */
/*   Updated: 2022/12/05 14:36:52 by lsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*tmpdst;
	char		*tmpsrc;

	if (!dst && !src)
		return (NULL);
	i = 0;
	tmpdst = (char *)dst;
	tmpsrc = (char *)src;
	if (tmpdst > tmpsrc)
		while (len-- > 0)
			tmpdst[len] = tmpsrc[len];
	else
	{
		while (i < len)
		{
			tmpdst[i] = tmpsrc[i];
			i++;
		}
	}
	return (dst);
}
