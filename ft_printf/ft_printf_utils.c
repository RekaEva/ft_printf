/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:13:59 by cpollito          #+#    #+#             */
/*   Updated: 2022/01/08 08:04:35 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reverse(int i, int *conter_sim, char *str)
{
	*conter_sim = *conter_sim + i;
	while (--i >= 0)
		write (1, &str[i], 1);
}

int	ft_putnbr(int n)
{
	int		i;
	char	str[11];
	int		counter_sim;

	counter_sim = 0;
	i = 0;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (counter_sim = 11);
	}
	if (n < 0)
	{
		counter_sim += ft_putchar_int('-');
		n = n * -1;
	}
	if (n == 0)
		counter_sim += ft_putchar_int('0');
	while (n > 0)
	{
		str[i++] = (n % 10) + '0';
		n = n / 10;
	}
	ft_reverse(i, &counter_sim, str);
	return (counter_sim);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	int		i;
	char	str[10];
	int		counter_sim;

	counter_sim = 0;
	i = 0;
	if (n == 0)
		counter_sim += ft_putchar_int('0');
	while (n > 0)
	{
		str[i++] = (n % 10) + '0';
		n = n / 10;
	}
	ft_reverse(i, &counter_sim, str);
	return (counter_sim);
}

int	ft_putnbr_hex(unsigned int n, int size_letter)
{
	int		i;
	char	str[10];
	int		counter_sim;

	counter_sim = 0;
	i = 0;
	if (n == 0)
		counter_sim += ft_putchar_int('0');
	while (n > 0)
	{
		if ((n % 16) >= 10)
		{
			if (size_letter == 0)
				str[i] = (n % 16) + 87;
			else
				str[i] = (n % 16) + 55;
		}
		else
			str[i] = (n % 16) + '0';
		n = n / 16;
		i++;
	}
	ft_reverse(i, &counter_sim, str);
	return (counter_sim);
}

int	ft_putnbr_hex_for_p(unsigned long long n)
{
	int		i;
	char	str[20];
	int		counter_sim;

	counter_sim = 0;
	i = 0;
	if (n == 0)
		counter_sim += ft_putchar_int('0');
	while (n > 0)
	{
		if ((n % 16) >= 10)
			str[i++] = (n % 16) + 87;
		else
			str[i++] = (n % 16) + '0';
		n = n / 16;
	}
	ft_reverse(i, &counter_sim, str);
	return (counter_sim);
}
