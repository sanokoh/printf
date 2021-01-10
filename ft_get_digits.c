/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_digits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 22:28:33 by ksano             #+#    #+#             */
/*   Updated: 2021/01/10 12:32:40 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_get_digits(long d)
{
	int	digits;

	if (d == INT_MIN)
		return (11);
	if (d == 0)
		return (1);
	if (d >= INT_MAX)
		return (10);
	digits = 0;
	if (d < 0)
	{
		digits++;
		d *= -1;
	}
	while (d / 10)
	{
		digits++;
		d /= 10;
	}
	digits++;
	return (digits);
}
