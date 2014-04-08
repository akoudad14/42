/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/08 13:35:17 by makoudad          #+#    #+#             */
/*   Updated: 2013/12/13 17:53:12 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_LS_H
# define FT_LS_H

typedef struct		s_ls
{
	char			*ls;
	size_t			ls_size;
	struct s_ls		*next;
}					t_ls;

void				ft_exist_or_not(char *directory, char c);
t_ls				*ft_ls_l(char *dir);
t_ls				*ft_ls_a(char *dir);
t_ls				*ft_ls_r(char *dir);
t_ls				*ft_ls_rec(char *dir);
t_ls				*ft_ls_t(char *dir);
t_ls				*ft_ls(char *dir);
t_ls				*ft_lst(char *ls, size_t ls_size);
void				ft_access(struct stat *buf);
t_ls				*ft_sort_lst(t_ls *new, DIR *fd);
t_ls				*ft_sort_lst_reverse(t_ls *new, DIR *fd);
t_ls				*ft_sort_lst_time(t_ls *new, char *directory, DIR *fd);
int					ft_total(char c);
int					ft_type_and_count_files(struct dirent *entry);
void				ft_replace_next(t_ls *really, t_ls *new);
void				ft_replace(t_ls *really, t_ls *new);
size_t				ft_lstlen(t_ls *count);
void				ft_uid(struct stat *buf);
void				ft_time_and_size(struct stat *buf);
void				ft_sort_lst_l(t_ls *new, char *directory);
char				*ft_road(char *road, char *directory, char *file);
int					ft_count_files(char *directory);
int					ft_strcmp_time(char *dst, char *src, char *directory);
void				ft_sort_lst_recursive(t_ls *new);
void				ft_info(t_ls *really, char *directory, char c);
t_ls				*ft_sort_lst_t_two(t_ls *new, char *directory);
t_ls				*ft_sort_lst_reverse_two(t_ls *new);
t_ls				*ft_sort_r_t(t_ls *new, char *directory);
int					ft_verif_dir(char *unknown);
int					ft_verif(t_ls *tmp3, char *tab);
int					ft_compare(char *str, char c);

#endif /* !FT_LS_H */
