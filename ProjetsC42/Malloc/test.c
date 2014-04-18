/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 11:00:57 by makoudad          #+#    #+#             */
/*   Updated: 2014/04/18 17:19:09 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/malloc.h"
#include "libft/includes/libft.h"
#include <stdio.h>
int main()
{
	char	*str0;
	char	*str01;
	char	*str;
	char	*str1;
	char	*str2;
	char	*str3;
	int		i;

	str0 = (char *)malloc(sizeof(char) * (2));
	i = -1;
	while (++i < 1)
		str0[i] = 'd';
	str0[i] = '\0';
printf("str0 = %p\n", str0);
	ft_putendl(str0);
	str01 = (char *)malloc(sizeof(char) * (8000000000 + 1));
	i = -1;
	while (++i < 8)
		str01[i] = 'c';
	str01[i] = '\0';
printf("str01 = %p\n", str01);
	ft_putendl(str01);
	str = (char *)malloc(sizeof(char) * (500 + 1));
	i = -1;
	while (++i < 50)
		str[i] = 'a';
	str[i] = '\0';
printf("str = %p\n", str);
	ft_putendl(str);
	str = (char *)realloc(str, sizeof(char) * (600 + 1));
	i = -1;
	while (++i < 600)
		str[i] = 'o';
	str[i] = '\0';
printf("str = %p\n", str);
	ft_putendl(str);
	str1 = (char *)malloc(sizeof(char) * (60 + 1));
	i = -1;
	while (++i < 60)
		str1[i] = 'b';
	str1[i] = '\0';
printf("str1 = %p\n", str1);
	ft_putendl(str1);
	str2 = (char *)malloc(sizeof(char) * (60 + 1));
	i = -1;
	while (++i < 60)
		str2[i] = 'e';
	str2[i] = '\0';
printf("str2 = %p\n", str2);
	ft_putendl(str2);
	str3 = (char *)malloc(sizeof(char) * (500 + 1));
	i = -1;
	while (++i < 500)
		str3[i] = 'f';
	str3[i] = '\0';
printf("str3 = %p\n", str3);
	ft_putendl(str3);
//	free(str01);
	free(str);
printf("str0 = %p\n", str0);
printf("str01 = %p\n", str01);
printf("str = %p\n", str);
printf("str1 = %p\n", str1);
printf("str2 = %p\n", str2);
printf("str3 = %p\n", str3);
	ft_putendl(str3);
	str3[0] = 'a';
	ft_putendl(str3);
	show_alloc_mem();
	return (0);
}
