/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 17:44:17 by ksano             #+#    #+#             */
/*   Updated: 2021/01/06 20:24:14 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char		*ft_get_precision(t_args *args, char *itr, va_list ap)
{
	if (!args)
		return (itr);
	if (*itr == '*')
	{
		args->has_precision = 1;
		args->precision = va_arg(ap, int);
		if (args->precision < 0)
			args->has_precision = 0;
		itr++;
	}
	else if (!(ft_isdigit(*itr)))
	{
		args->has_precision = 1;
		args->precision = 0;
	}
	else
	{
		args->has_precision = 1;
		args->precision = ft_atoi(itr);
		while (ft_isdigit(*itr))
			itr++;
	}
	return (itr);
}
