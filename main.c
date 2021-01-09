/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 20:13:28 by ksano             #+#    #+#             */
/*   Updated: 2021/01/09 19:33:20 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

#ifdef FT_PRINTF
# define F(...) \
    res = ft_printf(__VA_ARGS__); \
    printf("%d\n", res);
#else
# define F(...) \
    res = printf(__VA_ARGS__); \
	printf("%d\n", res);
#endif
int     main()
{
    int res = 0;
	setvbuf(stdout, 0, _IONBF, 0);

	F("%20.1p\n", NULL);
	F("%020.1p\n", NULL);
	F("%020.30p\n", NULL);
	F("%20.1p\n", &res);
	F("%20.0p\n", &res);
	F("%5.30p\n", &res);
    F("%5.p\n", NULL);
    return(0);
}
