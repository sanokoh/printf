/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:45:10 by ksano             #+#    #+#             */
/*   Updated: 2021/01/07 11:31:12 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int					ft_putchar_u(t_args args, unsigned int u)
{
	int				res;

	res = 0;
	if (args.align_left == 0)
	{
		while ((args.width--) - args.putlen > 0)
			res += ft_putchar(' ');
	}
	if (args.has_precision && args.precision == 0 && u == 0)
		return (res);
	while (args.padding-- > 0)
		res += ft_putchar('0');
	if (u / 10)
		res += ft_putchar_u(args, u / 10);
	res += ft_putchar((u % 10) + '0');
	return (res);
}

int					ft_put_u(t_args *args, va_list ap)
{
	unsigned int	u;
	int				res;

	res = 0;
	u = (unsigned int)va_arg(ap, int);
	args->len = ft_get_digits(u);
	if (args->has_precision == 1 && args->precision == 0)
		args->len = 0;
	args->padding = (args->len < args->precision) ?
		args->precision - args->len : 0;
	args->putlen = args->len + args->padding;
	if (args->zero_filling == 1 && args->has_precision == 0)
		res += ft_putchar_zero_filling(args);
	res += ft_putchar_u(*args, u);
	if (args->align_left == 1)
		res += ft_putchar_align_left(args);
	return (res);
}
