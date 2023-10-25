/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hosonu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:05:37 by hoyuki            #+#    #+#             */
/*   Updated: 2023/10/25 17:31:18 by hosonu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

bool	is_digits(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

size_t	ft_atoi(char *str, t_list *format)
{
	size_t	nb;

	nb = 0;
	while (*str && is_digits(*str))
	{
		nb = nb * 10 + *str - '0';
		str++;
		format->p_move++;
	}
	return (nb);
}

void	check_precision(char *str, t_list *format)
{
	format->p_move = 0;
	if (*str == '.')
	{
		format->precision = 1;
		format->p_move += 1;
		str++;
		format->prec_width = ft_atoi(str, format);
	}
}

void	check_flags(char *str, t_list *format)
{
	while (*str == '#' || *str == '+' || *str == '-' || *str == ' '
		|| *str == '0')
	{
		format->flags = 1;
		if (*str == '#')
			format->sharp = 1;
		else if (*str == '+')
			format->plus = 1;
		else if (*str == '-')
			format->minus = 1;
		else if (*str == ' ')
			format->space = 1;
		else if (*str == '0')
			format->zero = 1;
		str++;
		format->p_move += 1;
	}
	if (is_digits(*str))
		format->flags = 1;
	if (format->flags == 1)
		format->fields_width = ft_atoi(str, format);
}
