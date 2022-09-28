/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:01:52 by lter-zak          #+#    #+#             */
/*   Updated: 2022/06/15 13:29:16 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sos_printf(va_list ap, const char str)
{
	int	len;

	len = 0;
	if (str == 'c')
		len += ft_print_char(va_arg(ap, int));
	else if (str == 's')
		len += ft_print_str(va_arg(ap, char *));
	else if (str == 'p')
		len += ft_address_front(va_arg(ap, unsigned long long int));
	else if (str == 'd' || str == 'i')
		len += ft_print_nbr(va_arg(ap, int));
	else if (str == 'u')
		len += ft_print_nnbr(va_arg(ap, unsigned int));
	else if (str == 'x')
		len += ft_convert_to_hex(va_arg(ap, unsigned int), 1);
	else if (str == 'X')
		len += ft_convert_to_hex(va_arg(ap, unsigned int), 0);
	else if (str == '%')
		len += ft_print_char('%');
	return (len);
}

int	ft_printf(const char *argstr,	...)
{
	int		i;
	int		len;
	va_list	ap;

	i = 0;
	len = 0;
	va_start(ap, argstr);
	while (argstr[i])
	{
		if (argstr[i] == '%')
		{
			len += sos_printf(ap, argstr[i + 1]);
			i++;
		}
		else
			len += ft_print_char(argstr[i]);
		i++;
	}
	va_end(ap);
	return (len);
}
