/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabatie <lsabatie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 05:22:20 by lsabatie          #+#    #+#             */
/*   Updated: 2022/11/24 05:22:20 by lsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*blst;

	if (lst && *lst)
	{
		blst = *lst;
		while (blst->next)
			blst = blst->next;
		blst->next = new;
	}
	else
		*lst = new;
}
