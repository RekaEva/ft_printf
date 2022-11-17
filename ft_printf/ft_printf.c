/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:14:03 by cpollito          #+#    #+#             */
/*   Updated: 2022/01/08 08:01:40 by cpollito         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_int(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != '\0')
	{
		ft_putchar_int(s[i]);
		i++;
	}
	return (i);
}

int	ft_parser_s(va_list ap, int counter_sim)
{
	int		counter_s;

	counter_s = ft_putstr(va_arg(ap, char *));
	if (counter_s >= 0)
		counter_sim += counter_s;
	else
	{
		write(1, "(null)", 6);
		counter_sim += 6;
	}
	return (counter_sim);
}

int	ft_parser(va_list ap, int counter_sim, int i, const char *str)
{
	if (str[i] == '%')
		counter_sim += ft_putchar_int('%');
	if (str[i] == 'c')
		counter_sim += ft_putchar_int(va_arg(ap, int));
	if ((str[i] == 's'))
	{
		counter_sim = ft_parser_s(ap, counter_sim);
	}
	if ((str[i] == 'p'))
	{
		write (1, "0x", 2);
		counter_sim += 2;
		counter_sim += ft_putnbr_hex_for_p(va_arg(ap, unsigned long long));
	}
	if (str[i] == 'd')
		counter_sim += ft_putnbr(va_arg(ap, int));
	if ((str[i] == 'i'))
		counter_sim += ft_putnbr(va_arg(ap, int));
	if ((str[i] == 'u'))
		counter_sim += ft_putnbr_unsigned(va_arg(ap, unsigned int));
	if ((str[i] == 'x'))
		counter_sim += ft_putnbr_hex((va_arg(ap, unsigned int)), 0);
	if ((str[i] == 'X'))
		counter_sim += ft_putnbr_hex((va_arg(ap, unsigned int)), 1);
	return (counter_sim);
}

int	ft_printf(const char *str, ...)
{
	int		counter_sim;
	int		i;
	va_list	ap;

	va_start (ap, str);
	i = 0;
	counter_sim = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			counter_sim = ft_parser(ap, counter_sim, i, str);
		}
		else
			counter_sim += ft_putchar_int(str[i]);
		i++;
	}
	va_end(ap);
	return (counter_sim);
}
