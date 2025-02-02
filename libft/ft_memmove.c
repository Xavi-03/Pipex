/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:55:35 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/09/25 11:47:19 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*src_c;
	unsigned char	*dest_c;
	size_t			i;

	i = -1;
	src_c = (unsigned char *)src;
	dest_c = (unsigned char *)dest;
	if (dest <= src)
	{
		while (++i < n)
			dest_c[i] = src_c[i];
	}
	else if (dest > src)
	{
		i = n;
		while (i-- > 0)
			dest_c[i] = src_c[i];
	}
	return (dest);
}
