/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 18:05:13 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/09/30 18:16:53 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		counter;
	t_list	*iteri;

	counter = 0;
	iteri = lst;
	while (iteri != NULL)
	{
		counter++;
		iteri = iteri->next;
	}
	return (counter);
}
