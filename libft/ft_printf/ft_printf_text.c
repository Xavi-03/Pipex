/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_text.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:20:41 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/09/28 20:32:13 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_text_char(va_list args)
{
	int		counter;
	char	char_value;

	char_value = (char)va_arg(args, int);
	counter = ft_putchar(char_value);
	return (counter);
}

int	ft_text_str(va_list args)
{
	int		counter;
	char	*str_value;

	str_value = va_arg(args, char *);
	if (!str_value)
		str_value = "(null)";
	counter = ft_putstr(str_value);
	return (counter);
}
