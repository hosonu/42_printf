/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hosonu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:32:31 by hoyuki            #+#    #+#             */
/*   Updated: 2023/10/22 15:01:23 by hosonu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	nb_rec(size_t nb, t_list *format)
{
	if (nb >= 10)
		nb_rec(nb / 10, format);
	print_c(nb % 10 + '0', format);
}

void get_digit(size_t num, t_list *format)
{
	if(num >= 10)
		get_digit(num / 10, format);
	format->output_len++;
}

void	print_d(int num, t_list *format)
{
	long long	nb;
	size_t len;

	nb = num;
	if (nb < 0)
	{
		format->is_minus = 1;
		nb *= -1;
	}
	get_digit(nb, format);
	len = format->output_len;
	if(format->precision == 1 && format->prec_width > format->output_len)
		len = format->prec_width;
	if(format->flags == 1 && format->minus == 0)
		print_fields(len, format);
	if(format->plus == 1 && format->is_minus == 0)
		print_c('+', format);
	if(num < 0)
		format->cnt += write(1, "-", 1);
	if(format->precision == 1)
		print_pwidth(format->output_len, format);
	nb_rec(nb, format);
}

void	print_u(unsigned int num, t_list *format)
{
	size_t len;

	if(format->plus == 1)
		print_c('+', format);
	get_digit(num, format);
	len = format->output_len;
	if(format->precision == 1 && format->prec_width > format->output_len)
		len = format->prec_width;
	if(format->flags == 1 && format->minus == 0)
		print_fields(len, format);
	if(format->precision == 1)
		print_pwidth(format->output_len, format);
	nb_rec(num, format);
}
