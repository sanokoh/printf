/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 10:34:08 by ksano             #+#    #+#             */
/*   Updated: 2021/01/06 20:07:59 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int			ft_putchar_x(t_args args, char *s)
{
	int		res;

	res = 0;
	if (args.align_left == 0)
	{
		while ((args.width--) - args.putlen > 0)
			res += ft_putchar(' ');
	}
	if (args.has_precision && args.precision == 0 &&
		args.has_width == 1 && *s == '0')
	{
		res += ft_putchar(' ');
		return (res);
	}
	else if (args.has_precision && args.precision == 0 && *s == '0')
		return (res);
	while (args.padding-- > 0)
		res += ft_putchar('0');
	res += ft_putstr(s);
	return (res);
}

int			ft_put_x(t_args *args, va_list ap)
{
	long	x;
	int		res;
	char	*s;

	res = 0;
	s = NULL;
	x = va_arg(ap, unsigned int);
	args->c == 'x' ? s = ft_itoa_base(x, "0123456789abcdef") : 0;
	args->c == 'X' ? s = ft_itoa_base(x, "0123456789ABCDEF") : 0;
	args->len = ft_strlen(s);
	args->padding = (args->len < args->precision) ?
		args->precision - args->len : 0;
	args->putlen = args->len + args->padding;
	if (args->zero_filling == 1 && args->has_precision == 0)
		res += ft_putchar_zero_filling(args);
	res += ft_putchar_x(*args, s);
	if (args->align_left == 1)
		res += ft_putchar_align_left(args);
	return (res);
}
