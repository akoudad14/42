/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/09 18:38:19 by makoudad          #+#    #+#             */
/*   Updated: 2014/05/09 18:38:21 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_was_eating(t_sh **sh, int s_l, int s_r)
{
	(*(*sh)->stick)[s_l] = -1;
	(*(*sh)->stick)[s_r] = -1;
	(*(*sh)->life)[(*sh)->id] = time(NULL);
	(*(*sh)->type)[(*sh)->id] = R;
}

void	ft_was_thinking(t_sh **sh, int s_l, int s_r)
{
	int		sl_val;
	int		sr_val;
	int		id;

	id = (*sh)->id;
	sl_val = (*(*sh)->stick)[s_l];
	sr_val = (*(*sh)->stick)[s_r];
	if (id != sl_val && id != sr_val)
		(*(*sh)->type)[id] = W;
	else if ((id == sl_val && sr_val == -1
				&& (*(*sh)->life)[(id - 1 + 7) % 7] >= (*(*sh)->life)[id])
			|| (id == sr_val && sl_val == -1
				&& (*(*sh)->life)[(id + 1) % 7] >= (*(*sh)->life)[id]))
	{
		(*(*sh)->stick)[s_l] = id;
		(*(*sh)->stick)[s_r] = id;
		(*(*sh)->type)[id] = E;
	}
	else
		(*(*sh)->type)[id] = W;
}

void	ft_was_resting(t_sh **sh, int s_l, int s_r)
{
	int		id;

	id = (*sh)->id;
	if ((*(*sh)->type)[(id - 1 + 7) % 7] == R
		&& (*(*sh)->type)[(id + 1) % 7] == R)
	{
		(*(*sh)->stick)[s_l] = id;
		(*(*sh)->stick)[s_r] = id;
		(*(*sh)->type)[id] = E;
		return ;
	}
	if ((*(*sh)->type)[(id - 1 + 7) % 7] != E
		&& (*(*sh)->life)[(id - 1 + 7) % 7] >= (*(*sh)->life)[id])
	{
		(*(*sh)->stick)[s_r] = id;
		(*(*sh)->type)[id] = T;
	}
	if ((*(*sh)->type)[(id + 1) % 7] != E
		&& (*(*sh)->life)[(id + 1) % 7] >= (*(*sh)->life)[id])
	{
		(*(*sh)->stick)[s_l] = id;
		(*(*sh)->type)[id] = (*(*sh)->type)[id] == T ? E : T;
	}
	if ((*(*sh)->type)[id] == R)
		(*(*sh)->type)[id] = W;
}

void	ft_was_waiting2(t_sh **sh, int s_l, int s_r)
{
	int		sl_val;
	int		sr_val;
	int		id;

	id = (*sh)->id;
	sl_val = (*(*sh)->stick)[s_l];
	sr_val = (*(*sh)->stick)[s_r];
	if (sr_val == -1 && (*(*sh)->life)[(id - 1 + 7) % 7] >= (*(*sh)->life)[id])
	{
		(*(*sh)->stick)[s_r] = id;
		(*(*sh)->type)[id] = T;
	}
	if (sl_val == -1 && (*(*sh)->life)[(id + 1) % 7] >= (*(*sh)->life)[id])
	{
		(*(*sh)->stick)[s_l] = id;
		(*(*sh)->type)[id] = (*(*sh)->type)[id] == T ? E : T;
	}
}

void	ft_was_waiting(t_sh **sh, int s_l, int s_r)
{
	int		sl_val;
	int		sr_val;
	int		id;

	id = (*sh)->id;
	sl_val = (*(*sh)->stick)[s_l];
	sr_val = (*(*sh)->stick)[s_r];
	if ((id == sl_val && sr_val == -1
			&& (*(*sh)->life)[(id - 1 + 7) % 7] >= (*(*sh)->life)[id])
		|| (id == sr_val && sl_val == -1
			&& (*(*sh)->life)[(id + 1) % 7] >= (*(*sh)->life)[id]))
	{
		(*(*sh)->stick)[s_l] = id;
		(*(*sh)->stick)[s_r] = id;
		(*(*sh)->type)[id] = E;
		return ;
	}
	else if ((id == sl_val && sr_val == -1) || (id == sr_val && sl_val == -1))
		return ;
	else if ((*(*sh)->life)[(id - 1 + 7) % 7] < (*(*sh)->life)[id]
			&& (*(*sh)->life)[(id + 1) % 7] < (*(*sh)->life)[id])
		return ;
	ft_was_waiting2(sh, s_l, s_r);
}
