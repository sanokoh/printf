/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 22:27:50 by ksano             #+#    #+#             */
/*   Updated: 2021/01/06 20:08:20 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	init_args(t_args *args)
{
	args->c = 0;
	args->has_width = 0;
	args->width = 0;
	args->has_precision = 0;
	args->precision = 0;
	args->len = 0;
	args->putlen = 0;
	args->padding = 0;
	args->align_left = 0;
	args->zero_filling = 0;
}
