/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabatie <lsabatie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:47:28 by lsabatie          #+#    #+#             */
/*   Updated: 2022/11/08 13:15:24 by lsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t size)
{
	unsigned int	sl;
	unsigned int	dl;
	unsigned int	i;

	i = 0;
	dl = ft_strlen(dst);
	sl = ft_strlen(src);
	if (size <= 0)
		return (sl);
	if (size < dl)
		return (size + sl);
	while (i < sl && dl + i < size - 1)
	{
		dst[i + dl] = src[i];
		i++;
	}
	dst[i + dl] = '\0';
	return (dl + sl);
}
