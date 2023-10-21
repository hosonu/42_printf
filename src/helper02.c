/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:32:31 by hoyuki            #+#    #+#             */
/*   Updated: 2023/10/21 15:58:02 by hoyuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	nb_rec(size_t nb, t_list *body)
{
	if (nb >= 10)
		nb_rec(nb / 10, body);
	print_c(nb % 10 + '0', body);
}

void	print_d(int num, t_list *format)
{
	long long	nb;

	nb = num;
	if (nb < 0)
	{
		format->minus = 1;
		nb *= -1;
	}
	nb_rec(nb, format);
}
