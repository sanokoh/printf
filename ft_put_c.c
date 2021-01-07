/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 22:28:54 by ksano             #+#    #+#             */
/*   Updated: 2021/01/06 20:06:58 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_put_c(t_args *args, va_list ap)
{
	int	res;
	int	c;
	int	width;

	width = args->has_width ? args->width : 0;
	res = 0;
	c = va_arg(ap, int);
	if (!c)
		c = '\0';
	args->putlen = 1;
	if (args->align_left == 0)
	{
		while (width - 1 > 0)
		{
			res += ft_putchar(' ');
			width--;
		}
	}
	res += ft_putchar(c);
	if (args->align_left == 1)
		res += ft_putchar_align_left(args);
	return (res);
}
