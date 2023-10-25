/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hosonu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:56:04 by hoyuki            #+#    #+#             */
/*   Updated: 2023/10/25 17:33:29 by hosonu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		return (6);
	while (s[len] != '\0')
		len++;
	return (len);
}

void	print_c(char c, t_list *format)
{
	format->cnt += write(1, &c, 1);
}

void	print_s(char *s, t_list *format)
{
	size_t	len;

	len = ft_strlen(s);
	if (format->precision == 1 && format->prec_width < len)
		len = format->prec_width;
	format->output_len = len;
	if (format->flags == 1 && format->minus == 0 && format->fields_width > 0)
		print_fields(format->output_len, format);
	if (s == NULL)
		format->cnt += write(1, "(null)", len);
	else
	{
		format->cnt += write(1, s, len);
	}
	if (format->flags == 1 && format->minus == 1 && format->fields_width > 0)
		print_fields(format->output_len, format);
}
