/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 18:31:17 by ksano             #+#    #+#             */
/*   Updated: 2021/01/06 20:25:40 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int			ft_put_percent(t_args *args)
{
	int		res;
	int		width;

	res = 0;
	width = args->has_width ? args->width : 0;
	if (args->zero_filling == 1 && args->has_precision != 1 &&
		args->align_left != 1)
	{
		while (width-- > 1)
			res += ft_putchar('0');
	}
	else if (args->align_left != 1)
	{
		while (width-- > 1)
			res += ft_putchar(' ');
	}
	res += ft_putchar('%');
	if (args->align_left == 1)
	{
		while (width-- > 1)
			res += ft_putchar(' ');
	}
	return (res);
}
