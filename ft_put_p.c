/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 10:26:05 by ksano             #+#    #+#             */
/*   Updated: 2021/01/09 19:29:35 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int			ft_putchar_p(t_args args, char *s)
{
	int		res;

	res = 0;
	if (args.align_left == 0)
	{
		while ((args.width--) - args.putlen > 0)
			res += ft_putchar(' ');
	}
	res += ft_putstr("0x");
	if (args.has_precision && args.precision == 0 && *s == '0')
		return (res);
	while (args.padding-- > 0)
		res += ft_putchar('0');
	res += ft_putstr(s);
	if (args.align_left == 1)
		res += ft_putchar_align_left(&args);
	return (res);
}

int			ft_put_p(t_args *args, va_list ap)
{
	long	p;
	int		res;
	char	*s;

	res = 0;
	s = NULL;
	p = va_arg(ap, unsigned long);
	s = ft_itoa_base(p, "0123456789abcdef");
	if (s == NULL)
		return (res);
	if (args->has_precision && args->precision == 0)
		args->len = ft_strlen("0x");
	else
		args->len = ft_strlen(s) + ft_strlen("0x");
	args->padding = (args->len < args->precision) ?
		args->precision - args->len + ft_strlen("0x") : 0;
	args->putlen = args->len + args->padding;
	res += ft_putchar_p(*args, s);
	free(s);
	return (res);
}
