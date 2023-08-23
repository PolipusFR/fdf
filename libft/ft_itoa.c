/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabatie <lsabatie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:38:13 by lsabatie          #+#    #+#             */
/*   Updated: 2022/11/24 15:43:03 by lsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rev_int_tab(char *tab, int size)
{
	int	i;
	int	temp;

	i = 0;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = temp;
		i++;
	}
}

static char	*execptions_handler(char *ret_string, int n)
{
	if (n == INT_MIN)
	{
		ret_string = ft_strdup("-2147483648");
		return (ret_string);
	}
	if (n == 0)
		ret_string = ft_strdup("0");
	return (ret_string);
}

char	*ft_itoa(int n)
{
	char		ret[33];
	int			sign;
	char		*ret_string;
	int			i;

	i = 0;
	sign = 1;
	if (n == INT_MIN || n == 0)
		return (execptions_handler(NULL, n));
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	while (n)
	{
		ret[i++] = n % 10 + 48;
		n = n / 10;
	}
	if (sign == -1)
		ret[i++] = '-';
	ret[i] = 0;
	ft_rev_int_tab(ret, ft_strlen(ret));
	ret_string = ft_strdup(ret);
	return (ret_string);
}
