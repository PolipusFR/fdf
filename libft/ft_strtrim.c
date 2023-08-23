/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabatie <lsabatie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:38:17 by lsabatie          #+#    #+#             */
/*   Updated: 2022/11/24 15:47:25 by lsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_is_in_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	check_front(char *s1, char *set)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		if (!char_is_in_charset(s1[i], set))
			break ;
		i++;
	}
	return (i);
}

static int	check_back(char *s1, char *set)
{
	int	i;

	i = (ft_strlen (s1) - 1);
	while (char_is_in_charset(s1[i], set) && i != 0)
		i--;
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		front;
	int		back;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	front = check_front((char *)s1, (char *)set);
	back = check_back((char *)s1, (char *)set);
	if (front >= back)
		return (ft_strdup (""));
	ret = malloc ((back - front + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1 + front, back - front + 1);
	return (ret);
}
