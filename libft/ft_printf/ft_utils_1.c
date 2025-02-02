/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:21:15 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/09/29 15:03:59 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

unsigned long	ft_counter_unsigned(unsigned long int_value, unsigned int base)
{
	int	counter;

	counter = 1;
	while (int_value >= base)
	{
		int_value = int_value / base;
		counter++;
	}
	return (counter);
}

char	*ft_itoa_base_unsigned(unsigned long nbr, char *base_char)
{
	int					size;
	unsigned int		base_size;
	char				*str;

	base_size = ft_strlen_printf(base_char);
	size = ft_counter_unsigned(nbr, base_size);
	str = malloc((size + 1) * sizeof(char));
	str[size] = '\0';
	size--;
	while (nbr >= base_size)
	{
		str[size--] = base_char[nbr % base_size];
		nbr /= base_size;
	}
	str[size] = base_char[nbr];
	return (str);
}
