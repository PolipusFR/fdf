/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabatie <lsabatie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 06:11:02 by lsabatie          #+#    #+#             */
/*   Updated: 2022/11/24 06:11:02 by lsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*clone;

	if (!f || !lst)
		return ;
	clone = lst;
	while (clone)
	{
		(*f)(clone->content);
		clone = clone->next;
	}
}
