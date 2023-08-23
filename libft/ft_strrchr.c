/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabatie <lsabatie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:42:32 by lsabatie          #+#    #+#             */
/*   Updated: 2022/12/09 15:40:41 by lsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	while (*s)
	{
		if (*s == (unsigned char)c)
		{
			last = (char *)s;
		}
		s++;
	}
	if ((char)c == '\0')
	{
		return ((char *)s);
	}
	else
	{
		return (last);
	}
}
