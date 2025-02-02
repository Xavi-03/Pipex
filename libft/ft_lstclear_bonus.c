/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:44:15 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/10/01 16:00:05 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*iteri;

	while (*lst)
	{
		iteri = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = iteri;
	}
	free(*lst);
	*lst = NULL;
}
