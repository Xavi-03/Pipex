/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:59:05 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/09/25 11:59:02 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*flag;
	unsigned char	c_c;

	c_c = c;
	flag = 0;
	while (*s)
	{
		if (*s == c_c)
			flag = (char *)s;
		s++;
	}
	if (flag)
	{
		s = (char const *)flag;
		return ((char *)s);
	}
	if (c_c == 0)
		return ((char *)s);
	return (NULL);
}
