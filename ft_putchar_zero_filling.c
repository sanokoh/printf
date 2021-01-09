/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_zero_filling.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:55:20 by ksano             #+#    #+#             */
/*   Updated: 2021/01/09 17:42:10 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int			ft_putchar_zero_filling(t_args *args)
{
	int		res;

	res = 0;
	while ((args->width--) - args->len > 0)
		res += ft_putchar('0');
	return (res);
}
