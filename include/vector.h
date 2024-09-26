/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 04:26:59 by marvin            #+#    #+#             */
/*   Updated: 2024/09/26 11:56:07 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "arena.h"

# include <stddef.h>

// Generic vector type
typedef struct s_vector
{
	void		*data;
	ptrdiff_t	size;
	ptrdiff_t	len;
	ptrdiff_t	cap;
}	t_vector;

// Some common vector types
typedef struct s_strv
{
	char		**data;
	ptrdiff_t	size;
	ptrdiff_t	len;
	ptrdiff_t	cap;
}	t_strv;

typedef struct s_intv
{
	int			*data;
	ptrdiff_t	size;
	ptrdiff_t	len;
	ptrdiff_t	cap;
}	t_intv;

void	*vector_new(t_arena *a, ptrdiff_t elem_count, ptrdiff_t elem_size);
void	*vector_dup(t_arena *a, void *vecptr);
void	vector_grow(t_arena *a, void *vecptr);
void	vector_push(t_arena *a, void *vecptr, void *elem);

t_strv	*split_str(t_arena *perm, t_arena scratch, const char *s);
t_intv	*strv_to_intv(t_arena *perm, t_arena scratch, t_strv *sv);

#endif
