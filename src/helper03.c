/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 02:24:08 by hosonu            #+#    #+#             */
/*   Updated: 2023/10/24 21:14:45 by hoyuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	hex_rec(size_t nb, int cap, t_list *format)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (nb >= 16)
		hex_rec(nb / 16, cap, format);
	if (cap == 0)
		print_c(hex[nb % 16], format);
	else if (cap == 1)
	{
		if (hex[nb % 16] >= 'a' && hex[nb % 16] <= 'f')
			print_c(hex[nb % 16] - 32, format);
		else
			print_c(hex[nb % 16], format);
	}
}

void	get_digits_hex(size_t nb, t_list *format)
{
	if (nb == 0 && format->precision == 0 && format->prec_width == 0)
		format->output_len++;
	while (nb > 0)
	{
		nb /= 16;
		format->output_len++;
	}
}

void	print_x(size_t num, t_list *format)
{
	size_t	len;

	get_digits_hex(num, format);
	len = format->output_len;
	if (format->precision == 1 && format->prec_width > format->output_len)
		len = format->prec_width;
	if (format->flags == 1 && format->minus == 0)
		print_fields(len, format);
	if (format->sharp == 1 && num != 0)
		format->cnt += write(1, "0x", 2);
	if (format->precision == 1)
		print_pwidth(format->output_len, format);
	if (!(format->precision == 1 && num == 0))
		hex_rec(num, 0, format);
	if (format->flags == 1 && format->minus == 1)
		put_nback_fields(len, format);
}

void	print_cap_x(size_t num, t_list *format)
{
	size_t	len;

	get_digits_hex(num, format);
	len = format->output_len;
	if (format->precision == 1 && format->prec_width > format->output_len)
		len = format->prec_width;
	if (format->flags == 1 && format->minus == 0)
		print_fields(len, format);
	if (format->sharp == 1 && num != 0)
		format->cnt += write(1, "0X", 2);
	if (format->precision == 1)
		print_pwidth(format->output_len, format);
	if (!(format->precision == 1 && num == 0))
		hex_rec(num, 1, format);
	if (format->flags == 1 && format->minus == 1)
		put_nback_fields(len, format);
}

void	print_p(void *p, t_list *format)
{
	size_t	len;

	get_digits_hex((size_t)p, format);
	format->output_len += 2;
	len = format->output_len;
	if (format->flags == 1 && format->minus == 0)
		print_fields(len, format);
	format->cnt += write(1, "0x", 2);
	hex_rec((size_t)p, 0, format);
	if (format->flags == 1 && format->minus == 1)
		put_nback_fields(len, format);
}
