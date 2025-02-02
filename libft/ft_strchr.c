/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:36:45 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/09/25 13:14:41 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	c_c;

	c_c = c;
	while (*s)
	{
		if (*s == c_c)
			return ((char *)s);
		s++;
	}
	if (c_c == 0)
		return ((char *)s);
	return (NULL);
}
