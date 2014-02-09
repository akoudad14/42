/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh3.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <makoudad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 19:19:49 by makoudad          #+#    #+#             */
/*   Updated: 2014/02/09 16:48:15 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SH3_H
# define	SH3_H

# define	MAX_KEY_LEN					6
# define	P_LEN						4

# define	KEY_ENTER(buf)				ft_is_key_enter(buf)
# define	KEY_CTRL_D(buf)				ft_is_key_ctrl_d(buf)
# define	KEY_DEL_LEFT(buf)			ft_is_key_del_left(buf)
# define	KEY_DEL_RIGHT(buf)			ft_is_key_del_right(buf)
# define	KEY_ARROW_UP(buf)			ft_is_key_arrow_up(buf)
# define	KEY_ARROW_DOWN(buf)			ft_is_key_arrow_down(buf)
# define	KEY_ARROW_LEFT(buf)			ft_is_key_arrow_left(buf)
# define	KEY_ARROW_RIGHT(buf)		ft_is_key_arrow_right(buf)
# define	KEY_OPT_ARROW_UP(buf)		ft_is_key_opt_arrow_up(buf)
# define	KEY_OPT_ARROW_DOWN(buf)		ft_is_key_opt_arrow_down(buf)
# define	KEY_OPT_ARROW_LEFT(buf)		ft_is_key_opt_arrow_left(buf)
# define	KEY_OPT_ARROW_RIGHT(buf)	ft_is_key_opt_arrow_right(buf)
# define	KEY_CTRL_A(buf)				ft_is_key_ctrl_a(buf)
# define	KEY_CTRL_E(buf)				ft_is_key_ctrl_e(buf)
# define	KEY_CTRL_U(buf)				ft_is_key_ctrl_u(buf)
# define	KEY_CTRL_I(buf)				ft_is_key_ctrl_i(buf)
# define	KEY_CTRL_H(buf)				ft_is_key_ctrl_h(buf)
# define	KEY_CTRL_R(buf)				ft_is_key_ctrl_r(buf)
# define	KEY_CTRL_T(buf)				ft_is_key_ctrl_t(buf)
# define	KEY_CTRL_F(buf)				ft_is_key_ctrl_f(buf)
# define	KEY_CTRL_G(buf)				ft_is_key_ctrl_g(buf)

# include	<term.h>

typedef struct		s_sl
{
	char			c;
	struct s_sl		*next;
	struct s_sl		*prev;
}					t_sl;

typedef struct		s_hl
{
	t_sl			*hist;
	struct s_hl		*next;
	struct s_hl		*prev;
}					t_hl;

typedef struct		s_save
{
	int				cursor_l;
	int				cursor_hl;
	int				co;
	t_sl			*copy;
}					t_save;

typedef struct		s_env
{
	char			**env;
	char			**envc;
}					t_env;

/*
** In file ft_exe.c
*/

int			ft_executable(char *line, char **env);

/*
** In file main.c
*/

void		ft_check(char *line, t_env *e, int i);
int			ft_check_spe(char *line);

/*
** In file ft_special.c
*/

t_env		*ft_check_special(char *line, t_env *e, int n);

/*
** In file ft_direct.c
*/

int			ft_direct(char *line, t_env *e);

/*
** In file ft_env.c
*/

void		ft_env(char *line, char **env);
char		**ft_setenv(char *line, char **env);
char		**ft_unsetenv(char *line, char **env);

/*
** In file ft_check_env_and_signal.c
*/

int			ft_check_env_and_signal(char **env);

/*
** In file ft_right.c
*/

int			ft_right(char *line, t_env *e);

/*
** In file ft_left.c
*/

int			ft_left(char *line, t_env *e);

/*
** In file ft_pipe.c
*/
int			ft_pipe(char *line, t_env *e);

/*
** In file ft_check_exe.c
*/

char		*ft_check_exe(char *s, char *path);

/*
** In file ft_builtin.c
*/

t_env		*ft_cd(char *line, t_env *e);
void		ft_pwd(char *line);

/*
** In file ft_exit.c
*/

int			ft_check_exit(char *line);

/*
** In file change_terminal_mode.c
*/

int			ft_init_terminal_mode(struct termios tattr);
int			ft_default_terminal_mode(struct termios tattr);

/*
** In file save_final_list.c
*/

int			ft_save_line(t_hl **hlist, char **line);
int			ft_putc(int c);

/*
** In file do_line.c
*/

int			ft_do_line(char **line, t_sl *list);

/*
** In files is_key*.c
*/

int			ft_is_key_ctrl_d(char *buf);
int			ft_is_key_arrow_left(char *buf);
int			ft_is_key_arrow_right(char *buf);
int			ft_is_key_arrow_down(char *buf);
int			ft_is_key_arrow_up(char *buf);
int			ft_is_key_opt_arrow_left(char *buf);
int			ft_is_key_opt_arrow_right(char *buf);
int			ft_is_key_ctrl_a(char *buf);
int			ft_is_key_ctrl_e(char *buf);
int			ft_is_key_opt_arrow_up(char *buf);
int			ft_is_key_opt_arrow_down(char *buf);
int			ft_is_key_ctrl_u(char *buf);
int			ft_is_key_ctrl_i(char *buf);
int			ft_is_key_ctrl_h(char *buf);
int			ft_is_key_ctrl_r(char *buf);
int			ft_is_key_ctrl_t(char *buf);
int			ft_is_key_ctrl_f(char *buf);
int			ft_is_key_ctrl_g(char *buf);
int			ft_is_key_enter(char *buf);
int			ft_is_key_del_right(char *buf);
int			ft_is_key_del_left(char *buf);

/*
** In file ft_len.c
*/

int			ft_slist_len(t_sl *list);
int			ft_hlist_len(t_hl *hlist);

/*
** In file ft_list_put_elem.c
*/

t_sl		*ft_list_new_elem(char c);
int			ft_list_put_elem(char c, t_sl **list, int cursor);

/*
** In file fast_cursor_move.c
*/

int			ft_fast_move(char *buf, t_sl **list, int *cursor);

/*
** In file ft_change_line.c
*/

int			ft_change_line(char *buf, t_sl **list, int *cursor, int co);

/*
** In file ft_historic.c
*/

t_sl		*ft_listdup(t_sl *list);
int			ft_historic(char *buf, t_sl **list, t_save *save, t_hl **hlist);
int			ft_put_in_hist(t_hl **hlist, t_sl *list);

/*
** In file ft_list_del.c
*/

void		ft_list_del_elem(t_sl **list, int cursor);

/*
** In file ft_print.c
*/

int			ft_print(t_sl *list, t_save *save, int old_line);

/*
** In file ft_cut_copy_or_paste.c
*/

int			ft_cut_copy_or_paste(char *buf, t_sl **list, t_save *save);

#endif	/* !SH3_H */
