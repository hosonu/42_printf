/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hosonu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:42:23 by hoyuki            #+#    #+#             */
/*   Updated: 2023/10/23 02:33:52 by hosonu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct p_list
{
	size_t	cnt;
	size_t	fields_width;
	size_t	prec_width;
	size_t output_len;
	size_t p_move;
	bool	flags;
	bool	sharp;
	bool	space;
	bool	plus;
	bool	minus;
	bool	zero;
	bool	precision;
	bool	is_minus;

}			t_list;

int			ft_printf(const char *str, ...);
void		print_c(char c, t_list *format);
void		print_s(char *s, t_list *format);
void		print_d(int num, t_list *format);
void		print_u(unsigned int num, t_list *format);
void print_x(size_t num, t_list *format);
void print_cap_x(size_t num, t_list *format);
void print_p(void *p, t_list *format);
void print_fields(size_t len, t_list *format);
void put_nback_fields(size_t len, t_list *format);
void print_pwidth(size_t len, t_list *format);

void		check_flags(char *str, t_list *format);
void		check_precision(char *str, t_list *format);
void		get_width(char *str, t_list *format);
size_t		ft_atoi(char *str, t_list *foramt);

#endif
