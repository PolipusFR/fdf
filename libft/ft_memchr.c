/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabatie <lsabatie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 13:46:29 by lsabatie          #+#    #+#             */
/*   Updated: 2022/11/17 17:33:58 by lsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*ret;
	unsigned char	a;

	i = 0;
	a = (unsigned char)c;
	ret = (unsigned char *)s;
	while (n > 0)
	{
		if (ret[i] == a)
			return (&ret[i]);
		i++;
		n--;
	}
	if (c == '\0' && n != 0)
		return (&ret[i]);
	else
		return (NULL);
}
