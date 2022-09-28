/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:17:53 by lter-zak          #+#    #+#             */
/*   Updated: 2022/06/13 15:50:35 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int				ft_printf(const char *argstr, ...);

int				ft_print_char(int c);

int				ft_print_str(char *c);

int				ft_convert_to_hex(unsigned int nb, int type);

int				ft_address_front(unsigned long long int nb);

int				ft_print_nbr(int nb);

unsigned int	ft_print_nnbr(unsigned int nb);

#endif
