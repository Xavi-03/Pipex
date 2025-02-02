/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:56:54 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/10/11 14:45:14 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_gnl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (&str[i + 1]);
		i++;
	}
	return (NULL);
}

char	*ft_trimmer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] != '\0')
			str[i + 1] = '\0';
		i++;
	}
	return (str);
}

t_list	*ft_addnode(t_list **list, char *text)
{
	t_list	*iteri;
	t_list	*new_node;
	char	*new_text;

	iteri = *list;
	if (!text)
		return (NULL);
	if (ft_memorymanager((void *)&new_text, BUFFER_SIZE))
		return (NULL);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	ft_strcpy(new_text, text);
	free(text);
	new_node->text = new_text;
	new_node->next = NULL;
	if (!iteri)
		return (*list = new_node);
	while (iteri->next)
		iteri = iteri->next;
	iteri->next = new_node;
	return (new_node);
}

int	ft_listlen(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

char	*ft_strcpy(char *dst, char *src)
{
	int	i;
	int	j;

	if (!src)
	{
		dst = NULL;
		return (dst);
	}
	i = 0;
	j = 0;
	if (dst[0])
	{
		while (dst[i])
			i++;
	}
	while (src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (ft_strchr_gnl(src));
}
