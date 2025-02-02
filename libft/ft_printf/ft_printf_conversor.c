/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:21:53 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/09/30 20:32:29 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_conversor_caller(char type, va_list args)
{
	int	counter;

	counter = 0;
	if (type == 'c')
		counter += ft_text_char(args);
	else if (type == 's')
		counter += ft_text_str(args);
	else if (type == 'p')
		counter += ft_hex_void(args);
	else if (type == 'i' || type == 'd')
		counter += ft_nbr_int(args);
	else if (type == 'u')
		counter += ft_nbr_unsigned(args);
	else if (type == 'x')
		counter += ft_hex_low(args);
	else if (type == 'X')
		counter += ft_hex_up(args);
	else if (type == '%')
		counter += ft_putchar('%');
	return (counter);
}
