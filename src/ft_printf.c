/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:48:37 by hoyuki            #+#    #+#             */
/*   Updated: 2023/10/23 16:57:32 by hoyuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	main_print(char *str, va_list args, t_list *format)
{
	if (*str == 'c')
	{
		format->output_len = 1;
		if (format->flags == 1 && format->minus == 0)
			print_fields(1, format);
		print_c(va_arg(args, int), format);
		if (format->flags == 1 && format->minus == 1)
			print_fields(1, format);
	}
	else if (*str == 's')
		print_s(va_arg(args, char *), format);
	else if (*str == 'd' || *str == 'i')
		print_d(va_arg(args, int), format);
	else if (*str == 'u')
		print_u(va_arg(args, unsigned int), format);
	else if (*str == 'x')
		print_x(va_arg(args, unsigned int), format);
	else if (*str == 'X')
		print_cap_x(va_arg(args, unsigned int), format);
	else if (*str == 'p')
		print_p(va_arg(args, void *), format);
	else if (*str == '%')
		print_c('%', format);
}

void	initializer(t_list *format)
{
	format->fields_width = 0;
	format->prec_width = 0;
	format->output_len = 0;
	format->flags = 0;
	format->sharp = 0;
	format->space = 0;
	format->plus = 0;
	format->minus = 0;
	format->zero = 0;
	format->precision = 0;
	format->is_minus = 0;
	format->p_move = 0;
}

void	printf_subfunc(char *str, va_list args, t_list *format)
{
	while (*str != '\0')
	{
		initializer(format);
		if (*str == '%')
		{
			str++;
			check_flags(str, format);
			str += format->p_move;
			check_precision(str, format);
			str += format->p_move;
			main_print(str, args, format);
		}
		else
			print_c(*str, format);
		str++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	t_list	*format;
	size_t	cnt;

	va_start(args, str);
	format = malloc(sizeof(t_list));
	if (format == NULL)
		return (-1);
	format->cnt = 0;
	printf_subfunc((char *)str, args, format);
	cnt = format->cnt;
	free(format);
	va_end(args);
	return (cnt);
}
