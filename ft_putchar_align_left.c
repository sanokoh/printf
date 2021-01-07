/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_align_left.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 10:56:43 by ksano             #+#    #+#             */
/*   Updated: 2021/01/06 20:08:02 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int			ft_putchar_align_left(t_args *args)
{
	int		res;

	res = 0;
	while ((args->width--) - args->putlen > 0)
		res += ft_putchar(' ');
	return (res);
}
