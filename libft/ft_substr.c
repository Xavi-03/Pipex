/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 11:00:17 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/09/25 19:30:09 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*str_iteri;

	if (!s || ft_strlen(s) <= start)
	{
		str = malloc(1 * sizeof(char));
		*str = '\0';
		return (str);
	}
	if (ft_strlen(s + start) >= len)
		str = malloc((len + 1) * sizeof(char));
	else
		str = malloc((ft_strlen(s + start) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str_iteri = str;
	s += start;
	while (*s && len--)
	{
		*str_iteri++ = *s++;
	}
	*str_iteri = '\0';
	return (str);
}
