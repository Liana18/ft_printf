/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_prt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:34:01 by lter-zak          #+#    #+#             */
/*   Updated: 2022/08/02 22:26:24 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (write(1, "(null)", 6));
	while (c[i])
		i++;
	return (write(1, c, i));
}

static int	ft_convert_to_ptr(unsigned long long int nb)
{
	int	i;

	i = 0;
	if (nb < 10)
		i += ft_print_char(nb + 48);
	else if (nb < 16)
		i += ft_print_char(nb + 87);
	else
	{
		i += ft_convert_to_ptr(nb / 16);
		i += ft_convert_to_ptr(nb % 16);
	}
	return (i);
}

int	ft_convert_to_hex(unsigned int nb, int type)
{
	int	i;

	i = 0;
	if (nb > 15)
		i += ft_convert_to_hex(nb / 16, type);
	nb %= 16;
	if (nb < 10)
		i += ft_print_char(nb + 48);
	else if (nb < 16 && type == 0)
		i += ft_print_char (nb + 55);
	else if (nb < 16 && type == 1)
		i += ft_print_char (nb + 87);
	return (i);
}

int	ft_address_front(unsigned long long int nb)
{
	if (!nb)
		return (write(1, "0x0", 3));
	else
	{
		write(1, "0x", 2);
		return (ft_convert_to_ptr(nb) + 2);
	}
}	
