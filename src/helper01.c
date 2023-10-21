/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoyuki <hoyuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:56:04 by hoyuki            #+#    #+#             */
/*   Updated: 2023/10/21 16:17:14 by hoyuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		return (6);
	while (s[len] != '\0')
		len++;
	return (len);
}

size_t	ft_atoi(char *str, t_list *format)
{
	size_t	nb;

	nb = 0;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		nb = nb * 10 + *str - '0';
		str++;
        format->p_move++;
	}
	return (nb);
}

void	print_c(char c, t_list *format)
{
	format->cnt += write(1, &c, 1);
}

void	print_s(char *s, t_list *format)
{
    size_t len;

    len = ft_strlen(s);
    
    if(s == NULL)
        format->cnt += write(1, "(null)", 6);
    else
        format->cnt  += write(1, s, len);
}
