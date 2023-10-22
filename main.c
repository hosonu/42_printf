/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hosonu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:59:52 by hoyuki            #+#    #+#             */
/*   Updated: 2023/10/22 15:01:59 by hosonu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	char *str = "abc";
	printf("%d\n", printf("real: % 10s\n", str));
	printf("%d\n", ft_printf("mine: % 10s\n", str));
}
