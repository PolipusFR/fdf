/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabatie <lsabatie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:59:49 by lsabatie          #+#    #+#             */
/*   Updated: 2022/12/19 14:14:52 by lsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	size_calculator(size_t len, char const *s)
{
	if (len < ft_strlen(s))
		return (len);
	else
		return (ft_strlen(s));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*ret;
	int		size;

	if (start >= ft_strlen(s))
	{
		ret = malloc (sizeof (char));
		if (!ret)
			return (NULL);
		ret[0] = '\0';
		return (ret);
	}
	size = size_calculator(len, s);
	i = 0;
	ret = malloc(sizeof(char) * size + 1);
	if (!ret)
		return (NULL);
	while (s[start + i] && i < size)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
