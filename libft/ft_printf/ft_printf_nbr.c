/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:21:42 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/09/30 20:30:26 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_nbr_int(va_list args)
{
	int		counter;
	char	*int_value;
	int		nbr;

	counter = 0;
	nbr = va_arg(args, int);
	if (nbr == -2147483648)
	{
		counter = ft_putstr("-2147483648");
		return (counter);
	}
	int_value = ft_itoa_base(nbr, "0123456789");
	if (!int_value)
		return (0);
	counter = ft_putstr(int_value);
	free(int_value);
	return (counter);
}

int	ft_nbr_unsigned(va_list args)
{
	int		counter;
	char	*unsigned_value;

	counter = 0;
	unsigned_value = ft_itoa_base_unsigned
		(va_arg(args, unsigned int), "0123456789");
	if (!unsigned_value)
		return (0);
	counter = ft_putstr(unsigned_value);
	free(unsigned_value);
	return (counter);
}
