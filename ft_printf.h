/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hosonu <hosonu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:42:23 by hoyuki            #+#    #+#             */
/*   Updated: 2023/10/25 17:34:48 by hosonu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct p_list
{
	size_t	cnt;
	size_t	fields_width;
	size_t	prec_width;
	size_t	output_len;
	size_t	p_move;
	bool	flags;
	bool	sharp;
	bool	space;
	bool	plus;
	bool	minus;
	bool	zero;
	bool	precision;
	bool	is_minus;

}			t_list;

//ft_printf.c functions
int			ft_printf(const char *str, ...);
void		main_print(char *str, va_list args, t_list *format);
void		printf_subfunc(char *str, va_list args, t_list *format);
void		initializer(t_list *format);

//helper01.c functions
void		print_c(char c, t_list *format);
void		print_s(char *s, t_list *format);
size_t		ft_strlen(char *s);

//helper02.c functions
void		print_d(int num, t_list *format);
void		print_u(unsigned int num, t_list *format);
void		put_sign(t_list *format, int num, bool time);
void		get_digit(size_t num, t_list *format);
void		nb_rec(size_t nb, t_list *format);

//helper03.c functions
void		print_x(size_t num, t_list *format);
void		print_cap_x(size_t num, t_list *format);
void		print_p(void *p, t_list *format);
void		get_digits_hex(size_t nb, t_list *format);
void		hex_rec(size_t nb, int cap, t_list *format);

//helper04.c functions
void		print_fields(size_t len, t_list *format);
void		put_nback_fields(size_t len, t_list *format);
void		print_pwidth(size_t len, t_list *format);
void		print_space(ssize_t len, t_list *format);
void		print_zero(ssize_t len, t_list *format);

//check_flags.c functions
void		check_flags(char *str, t_list *format);
void		check_precision(char *str, t_list *format);
bool		is_digits(char c);
size_t		ft_atoi(char *str, t_list *foramt);

#endif
