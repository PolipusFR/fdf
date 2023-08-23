/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabatie <lsabatie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 06:06:56 by lsabatie          #+#    #+#             */
/*   Updated: 2022/11/24 06:06:56 by lsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*clone;

	if (!del)
		return ;
	while ((*lst))
	{
		clone = *lst;
		del((*lst)->content);
		(*lst) = clone->next;
		free(clone);
	}
}
