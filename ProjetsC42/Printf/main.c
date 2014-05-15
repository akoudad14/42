/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 17:48:06 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/22 18:45:37 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int		main(void)
{
	unsigned long 	i;

	i = 999;
	ft_putnbr(printf("coucou %p\n", "(null)"));
	ft_putchar('\n');
	ft_putnbr(ft_printf("coucou %p\n", "(null)"));
	ft_putchar('\n');
	int a;
	char b;
	void *c = malloc(1);
	printf("   ret(%d)\n", ft_printf("ft_ p: [%p] [%p] [%p] [%p] [%p]\n", NULL, 0, &a, &b, c));
	printf("   ret(%d)\n\n", printf("std p: [%p] [%p] [%p] [%p] [%p]\n", NULL, 0, &a, &b, c));
	void *ptr = NULL;

//	ptr += 9223372036854775807;
	ptr -= 9223372036854775807;
	ft_putnbr(printf("%p\n", ptr));
	ft_putchar('\n');
	ft_putnbr(ft_printf("%p\n", ptr));
	ft_putchar('\n');
	int test;
	char *str_test, str_test2;
	void *p, *p2, *p3, *p4;

	str_test = "couesf4y45re\tcou";
	str_test2 = NULL;
	test = 0;

	p = &test;
	p2 = &str_test;
	p3 = &str_test2;
	p4 = p3;
	ft_putnbr(ft_printf("%p %p %p %p\n", p, p2, p3, p4));
	ft_putchar('\n');
	ft_putnbr(printf("%p %p %p %p\n", p, p2, p3, p4));
	ft_putchar('\n');
	return (0);

}
/*int global_j = 0;

int main()
{
	void        *ptr = NULL;
    int            ret1, ret2, errors = 0;
    int            i = 0;

    ptr += 41939672940;
    for (i = 0; i > -41939672940; i--)
    {
        ret1 = printf("%p\n", ptr);
        ret2 = ft_printf("%p\n", ptr);
        if (ret1 != ret2)
        {
            printf("%d instead of %d\n", ret2, ret1);
            errors++;
        }
        ptr++;
    }
    printf("\n-> %d errors\n", errors);
	}*/
