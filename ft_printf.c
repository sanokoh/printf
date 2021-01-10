/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:10:13 by ksano             #+#    #+#             */
/*   Updated: 2021/01/10 13:14:40 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int				ft_printf(const char *format, ...)
{
	char		*itr;
	int			res;
	t_args		args;
	va_list		ap;

	if (!format || *format == '\0')
		return (0);
	itr = (char *)format;
	res = 0;
	va_start(ap, format);
	while (*itr)
	{
		if (*itr == '%')
		{
			itr = read_args(&args, itr, ap);
			if (args.c == 0)
				return (-1);
			res += ft_put_conversion(&args, ap);
			continue ;
		}
		res += ft_putchar(*itr);
		itr++;
	}
	va_end(ap);
	return (res);
}
