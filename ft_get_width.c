/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 22:30:20 by ksano             #+#    #+#             */
/*   Updated: 2021/01/10 12:55:30 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char	*ft_get_width(t_args *args, char *itr, va_list ap)
{
	if (!args)
		return (itr);
	if (*itr == '*')
	{
		args->has_width = 1;
		args->width = va_arg(ap, int);
		if (args->width < 0)
		{
			args->width *= -1;
			args->align_left = 1;
			args->zero_filling = 0;
		}
		itr++;
	}
	else
	{
		args->has_width = 1;
		args->width = ft_atoi(itr);
		itr += ft_get_digits(args->width);
	}
	return (itr);
}
