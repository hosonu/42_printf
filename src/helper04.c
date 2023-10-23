/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper04.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 00:57:24 by hosonu            #+#    #+#             */
/*   Updated: 2023/10/23 15:56:48 by hoyuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_space(ssize_t len, t_list *format)
{
	if (format->space == 1 && len == 0 && format->is_minus == 0)
		format->cnt += write(1, " ", 1);
	while (len > 0)
	{
		format->cnt += write(1, " ", 1);
		len--;
	}
}

void	print_zero(ssize_t len, t_list *format)
{
	while (len > 0)
	{
		format->cnt += write(1, "0", 1);
		len--;
	}
}

void	print_fields(size_t len, t_list *format)
{
	ssize_t	lens;

	lens = 0;
	if (format->fields_width > len)
		lens = format->fields_width - len - format->is_minus;
	if (format->sharp == 1)
		lens -= 2;
	if (format->plus == 1)
		lens--;
	if (format->zero == 1 && format->precision == 0)
		print_zero(lens, format);
	else
		print_space(lens, format);
}

void	put_nback_fields(size_t len, t_list *format)
{
	ssize_t	lens;

	lens = 0;
	if (format->fields_width > len)
		lens = format->fields_width - len - format->is_minus;
	if (format->sharp == 1)
		lens -= 2;
	if (format->plus == 1)
		lens--;
	print_space(lens, format);
}

void	print_pwidth(size_t len, t_list *format)
{
	ssize_t	lens;

	lens = 0;
	if (format->prec_width > len)
		lens = format->prec_width - len;
	print_zero(lens, format);
}
