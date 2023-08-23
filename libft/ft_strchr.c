/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabatie <lsabatie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:25:45 by lsabatie          #+#    #+#             */
/*   Updated: 2022/12/09 15:25:17 by lsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char *)s;
	while (ret[i])
	{
		if (ret[i] == (unsigned char)c)
			return (&ret[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&ret[i]);
	else
		return (NULL);
}
