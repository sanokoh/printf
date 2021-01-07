/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 18:46:36 by ksano             #+#    #+#             */
/*   Updated: 2021/01/06 20:24:06 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

char	*ft_get_flag(t_args *args, char *itr)
{
	if (!args)
		return (itr);
	while (*itr)
	{
		if (*itr == '-')
		{
			args->align_left = 1;
			itr++;
		}
		else if (*itr == '0')
		{
			args->zero_filling = 1;
			itr++;
		}
		else
			return (itr);
	}
	return (itr);
}
