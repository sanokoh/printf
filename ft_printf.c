/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 12:10:13 by ksano             #+#    #+#             */
/*   Updated: 2021/01/07 11:43:31 by ksano            ###   ########.fr       */
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
			{
				res +=ft_putstr((char *)format);
				break ;
			}
			res += ft_put_conversion(&args, ap);
			continue ;
		}
		res += ft_putchar(*itr);
		itr++;
	}
	va_end(ap);
	return (res);
}

#ifdef TEST
# ifdef FT_PRINTF
#  define F(...) \
    res = ft_printf(__VA_ARGS__); \
    printf("%d\n", res);
# else
#  define F(...) \
    res = printf(__VA_ARGS__); \
	printf("%d\n", res);
# endif
int		main(void)
{
	setvbuf(stdout, 0, _IONBF, 0);
	int res;
	int t;
	char c;

	c = 'a';
	t = 50;

	// F("1unsigned 1 %u unsigned 2 %u\n\n", 42, -42);
	// F("3unsigned 1 %   u unsigned 2 % u\n\n", 42, -42);
	F("4unsigned 1 %-12u unsigned 2 %-12u\n\n", 42, -42);
	F("6unsigned 1 %012u unsigned 2 %012u\n\n", 42, -42);

	// F("%d\n\n", F("1unsigned 1 %u unsigned 2 %u\n\n", 42, -42));
	// F("%d\n\n", F("3unsigned 1 %   u unsigned 2 % u\n\n", 42, -42));
	// F("%d\n\n", F("4unsigned 1 %-12u unsigned 2 %-12u\n\n", 42, -42));
	// F("%d\n\n", F("6unsigned 1 %012u unsigned 2 %012u\n\n", 42, -42));

}
#endif
