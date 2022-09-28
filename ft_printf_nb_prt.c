/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nb_prt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:24:04 by lter-zak          #+#    #+#             */
/*   Updated: 2022/06/13 14:08:36 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int nb)
{
	int	str;

	str = 0;
	if (nb < 0)
	{
		str += ft_print_char ('-');
		nb = -nb;
	}
	if (nb == -2147483648)
	{
		str += ft_print_char('2');
		nb = 147483648;
	}
	if (nb < 10)
		str += ft_print_char(nb + '0');
	else
	{
		str += ft_print_nbr(nb / 10);
		str += ft_print_nbr(nb % 10);
	}
	return (str);
}

unsigned int	ft_print_nnbr(unsigned int nb)
{
	int	str;

	str = 0;
	if (nb < 10)
	{
		str += ft_print_char(nb + '0');
	}
	else
	{
		str += ft_print_nnbr(nb / 10);
		str += ft_print_nnbr(nb % 10);
	}
	return (str);
}
