/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 04:26:59 by marvin            #+#    #+#             */
/*   Updated: 2024/09/23 18:43:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "arena.h"

# include <stddef.h>

typedef struct s_vector
{
	void		*data;
	ptrdiff_t	size;
	ptrdiff_t	len;
	ptrdiff_t	cap;
}	t_vector;

void	*vector_new(t_arena *a, ptrdiff_t elem_count, ptrdiff_t elem_size);
void	*vector_dup(t_arena *a, void *vecptr);
void	vector_grow(t_arena *a, void *vecptr);
void	vector_push(t_arena *a, void *vecptr, void *elem);

#endif
