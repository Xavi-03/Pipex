/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:18:08 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/09/22 13:41:00 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (len-- && *big)
	{
		if (*big == *little && ++i)
			little++;
		else if (i > 0)
		{
			little += -i;
			len += i;
			big += -i;
			i = 0;
		}
		if (*little == '\0')
		{
			big += -i + 1;
			return ((char *)big);
		}
		big++;
	}
	return (NULL);
}
