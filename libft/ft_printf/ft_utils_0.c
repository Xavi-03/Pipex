/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:21:22 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/09/29 15:08:16 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_utils_nbr_counter(int int_value, int base)
{
	int	counter;

	counter = 1;
	if (int_value < 0)
	{
		counter++;
		int_value = -int_value;
	}
	while (int_value >= base)
	{
		int_value = int_value / base;
		counter++;
	}
	return (counter);
}

char	*ft_itoa_base(int nbr, char *base_char)
{
	int		size;
	int		base_size;
	char	*str;

	base_size = ft_strlen_printf(base_char);
	size = ft_utils_nbr_counter(nbr, base_size);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (nbr < 0)
	{
		nbr = -nbr;
		str[0] = '-';
	}
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

int	ft_putchar(char c)
{
	int	counter;

	counter = 1;
	if (!write(1, &c, 1))
		return (counter - 1);
	return (counter);
}

int	ft_putstr(char *str)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (str[i])
	{
		counter += ft_putchar(str[i]);
		i++;
	}
	return (counter);
}

int	ft_strlen_printf(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
