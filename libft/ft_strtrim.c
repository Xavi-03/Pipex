/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 12:10:19 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/09/26 13:49:59 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_setchecker(char s1, char *set)
{
	while (*set)
	{
		if (*set == s1)
			return (1);
		set++;
	}
	return (0);
}

static	int	ft_counterstart(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (ft_setchecker(*s1, (char *)set))
	{
		i++;
		s1++;
	}
	return (i);
}

static	int	ft_counterend(char const *s1, char const *set)
{
	int	i;

	i = 0;
	s1--;
	while (ft_setchecker(*s1, (char *)set))
	{
		i++;
		s1--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		len;
	int		end;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	len = ft_strlen(s1);
	start = ft_counterstart(s1, (char *)set);
	end = ft_counterend(s1 + len, (char *)set);
	str = ft_substr(s1, start, (len - (start + end)));
	if (!str)
		return (NULL);
	return (str);
}
