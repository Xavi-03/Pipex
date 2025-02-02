/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:27:41 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/09/29 20:27:16 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_hex_void(va_list args)
{
	int		counter;
	char	*ptr_value;

	counter = 0;
	ptr_value = ft_itoa_base_unsigned
		(va_arg(args, unsigned long), "0123456789abcdef");
	if (*ptr_value == '0')
	{
		counter = ft_putstr("(nil)");
		free(ptr_value);
		return (counter);
	}
	counter = ft_putstr("0x");
	counter += ft_putstr(ptr_value);
	free(ptr_value);
	return (counter);
}

int	ft_hex_low(va_list args)
{
	int		counter;
	char	*hex_value;

	counter = 0;
	hex_value = ft_itoa_base_unsigned
		(va_arg(args, unsigned int), "0123456789abcdef");
	if (!hex_value)
		return (0);
	counter = ft_putstr(hex_value);
	free(hex_value);
	return (counter);
}

int	ft_hex_up(va_list args)
{
	int		counter;
	char	*hex_up_value;

	counter = 0;
	hex_up_value = ft_itoa_base_unsigned
		(va_arg(args, unsigned int), "0123456789ABCDEF");
	if (!hex_up_value)
		return (0);
	counter = ft_putstr(hex_up_value);
	free(hex_up_value);
	return (counter);
}
