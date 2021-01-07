/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 14:00:39 by ksano             #+#    #+#             */
/*   Updated: 2021/01/07 11:05:51 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int			ft_put_d_minus(int *d)
{
	int		res;

	res = 0;
	res = ft_putchar('-');
	*d *= -1;
	return (res);
}

int			ft_putchar_d_case_intmin(t_args args)
{
	int		res;

	res = 0;
	res += ft_putchar('-');
	while (args.padding-- > 0)
		res += ft_putchar('0');
	res += ft_putstr("2147483648");
	return (res);
}

int			ft_putchar_d(t_args args, int d)
{
	int	res;

	res = 0;
	if (d == -2147483648)
	{
		res += ft_putchar_d_case_intmin(args);
		return (res);
	}
	if (args.align_left == 0)
	{
		while ((args.width--) - args.putlen > 0)
			res += ft_putchar(' ');
	}
	if (d < 0)
		res += ft_put_d_minus(&d);
	if (args.has_precision && args.precision == 0 && d == 0)
		return (res);
	while (args.padding-- > 0)
		res += ft_putchar('0');
	if (d / 10)
		res += ft_putchar_d(args, d / 10);
	res += ft_putchar((d % 10) + '0');
	return (res);
}

int			ft_put_d(t_args *args, va_list ap)
{
	int		d;
	int		res;

	res = 0;
	d = va_arg(ap, int);
	args->len = ft_get_digits(d);
	if (args->has_precision == 1 && args->precision == 0 && d == 0)
		args->len = 0;
	if (d < 0)
		args->padding = ((args->len - 1) < args->precision ?
			args->precision - (args->len - 1) : 0);
	else
		args->padding = (args->len < args->precision) ?
			args->precision - args->len : 0;
	args->putlen = args->len + args->padding;
	if (args->zero_filling == 1 && args->has_precision == 0)
	{
		if (d < 0)
			res += ft_put_d_minus(&d);
		res += ft_putchar_zero_filling(args);
	}
	res += ft_putchar_d(*args, d);
	if (args->align_left == 1)
		res += ft_putchar_align_left(args);
	return (res);
}
