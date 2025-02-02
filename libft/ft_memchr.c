/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:53:46 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/09/24 16:52:19 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	val;

	str = (unsigned char *)s;
	val = (unsigned char)c;
	while (n-- > 0)
	{
		if (*str == val)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
