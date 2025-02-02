/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 15:19:11 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/09/29 15:12:38 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf(char const *format, ...)
{
	int		counter;
	va_list	args;

	counter = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			counter += ft_conversor_caller(*format, args);
		}
		else
		{
			counter += ft_putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (counter);
}
