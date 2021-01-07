/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 18:00:31 by ksano             #+#    #+#             */
/*   Updated: 2021/01/06 20:32:14 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int			ft_putchar_s(t_args *args, char *s)
{
	int		res;
	int		width;

	if (!s)
		return (0);
	width = (args->has_width) ? args->width : 0;
	res = 0;
	if (args->align_left == 1)
	{
		res += ft_putstrl(s, args->putlen);
		while (((width--) - args->putlen) > 0)
		{
			res += ft_putchar(' ');
		}
	}
	else
	{
		while (((width--) - args->putlen) > 0)
		{
			res += ft_putchar(args->zero_filling ? '0' : ' ');
		}
		res += ft_putstrl(s, args->putlen);
	}
	return (res);
}

int			ft_put_s(t_args *args, va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	if (!s)
		s = "(null)";
	args->len = ft_strlen(s);
	if (args->has_precision)
		args->putlen = (args->len > args->precision) ?
			args->precision : args->len;
	else
		args->putlen = args->len;
	return (ft_putchar_s(args, s));
}
