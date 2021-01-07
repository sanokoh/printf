/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 22:29:23 by ksano             #+#    #+#             */
/*   Updated: 2021/01/06 20:24:54 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_put_conversion(t_args *args, va_list ap)
{
	if (args->c == 'c')
		return (ft_put_c(args, ap));
	else if (args->c == 's')
		return (ft_put_s(args, ap));
	else if (args->c == 'p')
		return (ft_put_p(args, ap));
	else if (args->c == 'd' || args->c == 'i')
		return (ft_put_d(args, ap));
	else if (args->c == 'u')
		return (ft_put_u(args, ap));
	else if (args->c == 'x' || args->c == 'X')
		return (ft_put_x(args, ap));
	else if (args->c == '%')
		return (ft_put_percent(args));
	return (0);
}
