/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 22:30:54 by ksano             #+#    #+#             */
/*   Updated: 2021/01/07 11:43:17 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char	*read_args(t_args *args, char *itr, va_list ap)
{
	if (!itr || *itr != '%')
		return (itr);
	itr++;
	init_args(args);
	while (*itr == ' ')
		itr++;
	if (ft_strchr(FLAG, *itr))
		itr = ft_get_flag(args, itr);
	if (ft_isdigit(*itr) || *itr == '*')
		itr = ft_get_width(args, itr, ap);
	if (*itr == '.')
	{
		itr++;
		itr = ft_get_precision(args, itr, ap);
	}
	if (ft_strchr(CONV, *itr))
	{
		itr = ft_get_conversion(args, itr);
		return (itr);
	}
	return (itr);
}
