/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makoudad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 10:59:05 by makoudad          #+#    #+#             */
/*   Updated: 2014/04/18 16:05:00 by makoudad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		MALLOC_H
# define	MALLOC_H

# include <stdlib.h>

typedef struct			s_block
{
	void				*data;
	void				*last;
	size_t				size;
	struct s_block		*next;
}						t_block;

void					free(void *ptr);
void					*malloc(size_t size);
void					*realloc(void *ptr, size_t size);
void					show_alloc_mem();
void					show_block(t_block *tiny, t_block *small, t_block *l);
void					list_ptr(void *data, size_t size, int flag);
void					add_block_small(t_block **list, void *data,
										size_t size, size_t pg);
void					add_block_tiny(t_block **list, void *data,
										size_t size, size_t pg);
void					ft_print(t_block *move);

#endif
