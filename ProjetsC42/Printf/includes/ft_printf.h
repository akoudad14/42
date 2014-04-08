/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 15:06:00 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/22 11:17:38 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FT_PRINTF_H
# define	FT_PRINTF_H

typedef struct			s_print
{
	char				*str;
	int					i;
	struct s_print		*next;
}						t_print;

int			ft_printf(const char *format, ...);
void		ft_putchar(char c);
void		ft_putstr(char const *s);
void		ft_putnbr(int n);
char		*ft_itoa(int n);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
char		*ft_strcpy(char *s1, const char *s2);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strnew(size_t size);
void		ft_putendl(char const *s);
t_print		*ft_do(char const *format, t_print *print, int i);
t_print		*ft_lst_print(char *str, int i);
int			ft_comp(char c);
char		*ft_without(char const *format, char *tmp);
t_print		*ft_arg(t_print *pf, va_list ap);
void		ft_putnnbr(int n);
char		*ft_toa(unsigned int n, char *base);
char		*ft_stoa(unsigned long n, char *base);
char		*ft_ltoa(size_t n, char *base);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_printfc(char c);
char		*ft_printfp(void *p);
void		ft_printfn(t_print *pf, int *nbr);

#endif   /* FT_PRINTF_H */
