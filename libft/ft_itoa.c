/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:57:48 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/10/24 15:15:51 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countnum(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_putnbr_itoa(int n, char *nbr, char *nbr_reset)
{
	char	*int_min;

	int_min = "-2147483648";
	if (n == -2147483648)
	{
		*nbr = '\0';
		nbr = nbr_reset;
		while (*int_min)
			*nbr++ = *int_min++;
		return (nbr);
	}
	if (n > 9)
		ft_putnbr_itoa((n / 10), --nbr, nbr_reset);
	else
		nbr--;
	*nbr = (char)(n % 10) + '0';
	return (nbr);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	char	*nbr_reset;
	int		i;

	i = ft_countnum(n);
	nbr = malloc((i + 1) * sizeof(char));
	if (!nbr)
		return (NULL);
	nbr_reset = nbr;
	if (n < 0 && n != -2147483648)
	{
		n = -n;
		*nbr = '-';
	}
	nbr = ft_putnbr_itoa(n, (nbr + i), nbr_reset);
	nbr = nbr_reset;
	if (n != -2147483648)
		*(nbr + i) = '\0';
	return (nbr);
}
