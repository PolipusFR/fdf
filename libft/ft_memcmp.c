/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabatie <lsabatie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:06:44 by lsabatie          #+#    #+#             */
/*   Updated: 2022/11/10 17:26:57 by lsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		i;

	while (n > 0)
	{
		i = *(unsigned char *)s1++ - *(unsigned char *)s2++;
		if (i != 0)
			return (i);
		n--;
	}
	return (0);
}
