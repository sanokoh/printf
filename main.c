/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksano <ksano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 20:13:28 by ksano             #+#    #+#             */
/*   Updated: 2021/01/10 12:45:52 by ksano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include "libft/libft.h"

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

	// res = printf("%1000000000000000d\n", 999);
	// printf("%d\n", res);

	// res = ft_printf("%1000000000000000d\n", 999);
	// printf("%d\n", res);

	F("%1000000000000000d\n", 999);

	// F("%100000000000000d\n", 999);
	// F("%10000000000000d\n", 999);
	// F("%1000000000000d\n", 999);
	// F("%100000000000d\n", 999);

	// F("%10000000000d\n", 999);
	// F("%1000000000d\n", 999);
	// F("%100000000d\n", 999);
//********************************
	// F("%10000000d\n", 999);
	// F("%1000000d\n", 999);
//********************************

	// F("%100000d\n", 999);
	// F("%10000d\n", 999);
	// F("%10d\n", 999);
	// F("%5d\n", 999);
	// F("%d\n", 999);
	// F("%20.1p\n", NULL);
	// F("%020.1p\n", NULL);
	// F("%020.30p\n", NULL);
	// F("%20.1p\n", &res);
	// F("%20.0p\n", &res);
	// F("%5.30p\n", &res);
	// //↓こいつが差分有り
    // F("%5.p\n", NULL);

//***************************************
    // F("%5\n");
    // F("%05\n");
    // F("%-05\n");
    // F("%-5\n");

	// F("%-5c", '');
	// F("%.*s", -3, "hello");
	// F("%-*.*s", -7, -3, "yolo");
	// F("%0*i", -7, -54);
	// F("%0*i\n", -7, -54);
	// F("%0*i\n", 7, -54);
	// F("%*i\n", -7, -54);
	// F("%5.0x\n", 0);
	// F("%5.0x\n", 1);
	// F("%5x\n", 0);
	// F("%5.x\n", 0);
	// F("%-5.0x\n", 0);
	// F("%-5.x\n", 0);
	// F("%-5.x\n", 1);
	// ("%5.0X", 0);
	// ("%5.X", 0);
	// ("%-5.0X", 0);
	// ("%-5.X", 0);
	// F("-------------\n");


	// F("%7x\n", 33);
	// F("%3x\n", 0);
	// F("%5x\n", 52625);
	// F("%8.5x\n", 34);
	// F("%8.5x\n", 0);
	// F("-------------\n");
	// F("%08.5x\n", 34);
	// F("%08.5x\n", 0);
	// F("%08.3x\n", 8375);
	// F("-------------\n");
	// F("%05x\n", 43);
	// F("%03x\n", 0);
	// F("-------------\n");
	// F("%05d\n", 43);
	// F("%03d\n", 0);
	// F("[%5.p]\n", NULL);
	// F("[%.p]\n", NULL);
	// F("[%2.p]\n", NULL);
	// F("[%.0p]\n", 0);
	// F("%x\n", 15);
	// F("%X\n", 15);
	// F("%u\n", 100);
	// F("%u\n", 2147483648);
	// F("%u\n", 4147483648);
	// F("%u\n", -2147483647);

    // F("%p\n", NULL);
    // F("%5p\n", NULL);
    // F("%2p\n", NULL);
    // F("%.p\n", NULL);
    // F("%5.p\n", NULL);
    // F("%2.p\n", NULL);
    // F("%9.2p\n", 1234);
    // F("%.5p\n", 0);
    // F("%.0p\n", 0);
    // F("%5p\n", 0);

	// F("%3i\n", 0);
	// F("%03i\n", 0);
    // F("%03i\n", 0);
    // F("%0-8.5i\n", 34);
    // F("%0-10.5i\n", -216);
    // F("%0-8.5i\n", 0);
    // F("%0-8.3i\n", 8375);
    // F("%0-8.3i\n", -8473);
    // F("%03d\n", 0);
    // F("%0-8.5d\n", 34);
    // F("%0-10.5d\n", -216);
    // F("%0-8.5d\n", 0);
    // F("%0-8.3d\n", 8375);
    // F("%0-8.3d\n", -8473);

	// F("%-3i\n", 0);
	// F("%3i\n", 1);
	// F("%07i\n", -54);
	// F("%7d\n", -54);

	// F("%.0s\n", "hello");
	// F("%.0s\n", "NULL");
	// F("%-.00s\n", "hoge");

	// F("[%5%]\n");
	// F("[%-5%]\n");
	// F("[%05%]\n");
	// F("[%-05%]\n");
	// F("[%-05]\n");

	// F("%.s\n", "hoge");
	// F("%3.s\n", "hoge");
	// F("%10.s\n", "hoge");

	// F("[%08.3i]\n", -8473);

	// F("%3.s\n", "hoge");
	// F("%10.s\n", "hoge");
	// F("%3.s\n", NULL);
	// F("%10.s\n", NULL);
	// F("%1.s\n", "\0");
	// F("%2.s\n", "\0");
	// F("%9.s\n", "\0");

	// F("%.03s\n", "hoge");
	// F("%.3s\n", "hoge");
	// F("%5.3s\n", "hoge");
	// F("%.09s\n", "hoge");
	// F("%.09s\n", NULL);

	// F("%p\n", &res);
	// F("%20p\n", &res);
	// F("%020p\n", &res);
	// F("%030p\n", &res);
	// F("%-20p\n", &res);
	// F("%-20.30p\n", &res);

	// F("%20p\n", &res);
	// F("%20.30p\n", &res);
	// F("%.30p\n", &res);
	// F("%020.30p\n", &res);

	// F("%20.1p\n", NULL);
	// F("%020.1p\n", NULL);
	// F("%020.30p\n", NULL);
	// F("%20.1p\n", &res);
	// F("%20.0p\n", &res);
	// F("%5.30p\n", &res);

	// F("hogea\n");
	// F("[test%c%c]\n", 'A', 'a');
	// F("[test%s]\n", "hoge");
	// // ******************↓↓ubuntuとMac出力が違う↓↓************************
	// F("[test%010s]\n", "hoge");
	// F("[test%010.2s]\n", "hoge");
	// // ***********************************************************************
	// F("[%-10.2s]\n", "hoge");

	// F("[%d]\n", 1234);
	// F("[%10.5d]\n", 1234);
	// F("[%10.2d]\n", 1234);

	// F("[%10.2d]\n", -1234);
	// F("[%.2d]\n", -1234);
	// F("[%-10d]\n", -1234);
	// F("[%10.5d]\n", 1234);
	// F("[%10.20d]\n", 1234);
	// F("[%-10.20d]\n", 1234);
	// F("[%010.20d]\n", 1234);
	// F("[%010.5d]\n", 1234);
	// F("[%010d]\n", 1234);
	// F("[%-010.20d]\n", 1234);
	// F("[%010d]\n", 1234);
	// F("[%-10.5d]\n", 1234);
	// F("[%-10.5d]\n", -1234);
	// F("[%-10d]\n", 1234);
	// F("[%10d]\n", -2147483648);
	// F("[%10d]\n", 2147483647);
	// F("[%d]\n", -2147483648);
	// F("[%d]\n", 2147483647);
	// F("[test%*.*s]\n", -10, 2, "hoge");
	// F("[%10.2d]\n", 1234);
	// F("[%*.*d]\n", 10, 2, 1234);

    return(0);
}
