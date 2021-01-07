/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 10:48:19 by ksano             #+#    #+#             */
/*   Updated: 2021/01/07 11:28:32 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <errno.h>
# include <limits.h>

# define CONV "cspdiuxX%"
# define FLAG "-0"

typedef struct	s_args
{
	int			c;
	int			has_width;
	int			width;
	int			has_precision;
	int			precision;
	int			len;
	int			putlen;
	int			padding;
	int			align_left;
	int			zero_filling;
}				t_args;

int				ft_printf(const char *format, ...);
void			init_args(t_args *args);
char			*read_args(t_args *args, char *itr, va_list ap);
int				ft_get_digits(long d);
int				ft_put_c(t_args *args, va_list ap);
int				ft_put_s(t_args *args, va_list ap);
int				ft_put_p(t_args *args, va_list ap);
int				ft_put_d(t_args *args, va_list ap);
int				ft_put_u(t_args *args, va_list ap);
int				ft_put_x(t_args *args, va_list ap);
int				ft_put_conversion(t_args *args, va_list ap);
int				ft_put_percent(t_args *args);
int				ft_putchar_s(t_args *args, char *s);
int				ft_putchar_d(t_args args, int d);
int				ft_putchar_align_left(t_args *args);
int				ft_putchar_zero_filling(t_args *args);
char			*ft_get_flag(t_args *args, char *itr);
char			*ft_get_conversion(t_args *args, char *itr);
char			*ft_get_width(t_args *args, char *itr, va_list ap);
char			*ft_get_precision(t_args *args, char *itr, va_list ap);

#endif
