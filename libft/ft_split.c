/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:50:31 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/09/26 13:53:48 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static	int	ft_countersplits(char const *s, char c)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && !flag)
		{
			i++;
			flag = 1;
		}
		if (*s == c && flag)
			flag = 0;
		s++;
	}
	return (i);
}

char	**ft_splitter(char const *s, char c, char **str, int *i)
{
	i[0] = 0;
	i[1] = 1;
	while (*++s)
	{
		if (*s == c && !i[1])
		{
			*str = ft_substr((s - i[0]), 0, i[0]);
			if (!*str)
				return (NULL);
			str++;
			i[0] = 0;
			i[1] = 1;
		}
		if (*s != c && i[1])
			i[1] = 0;
		if (*s != c)
			i[0]++;
	}
	if (i[0] == 0)
		return (str);
	*str = ft_substr((s - i[0]), 0, i[0]);
	if (!*str)
		return (NULL);
	return (++str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	char	**str_return;
	int		i[2];
	int		splits;

	splits = ft_countersplits(s, c);
	str = malloc((splits + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	str[splits] = ((void *) 0);
	str_return = str;
	if (*s == '\0')
		return (str_return);
	str = ft_splitter(s - 1, c, str, i);
	if (!str)
		return (NULL);
	return (str_return);
}
/*
int	main(int argc, char **argv)
{
	char	**dest;
	if (argc > 0)
	{
		dest = ft_split( (char const *)argv[1], argv[2][0]);
		printf("Arr:\n");
		while(*dest)
		{
			printf("%s\n", *dest);
			dest++;
		}
	}
	return(0);
}
*/
