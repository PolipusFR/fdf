/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabatie <lsabatie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:54:54 by lsabatie          #+#    #+#             */
/*   Updated: 2022/11/14 16:56:54 by lsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char		*str;
	char		*to_find;
	size_t		i;
	size_t		j;

	i = 0;
	to_find = (char *)needle;
	str = (char *)haystack;
	if (*needle == 0)
		return (str);
	while (str[i] && i < len)
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while (to_find[j] && str[i + j] == to_find[j] && i + j < len)
				j++;
			if (to_find[j] == 0)
				return (&str[i]);
		}
		i++;
	}
	return (NULL);
}
