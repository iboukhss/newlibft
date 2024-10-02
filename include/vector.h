/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 04:26:59 by marvin            #+#    #+#             */
/*   Updated: 2024/10/03 01:29:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "arena.h"

// Generic vector type
typedef struct s_vector
{
	void		*data;
	ptrdiff_t	size;
	ptrdiff_t	len;
	ptrdiff_t	cap;
}	t_vector;

// Some common vector types

// String vector type
typedef struct s_strv
{
	char		**data;
	ptrdiff_t	size;
	ptrdiff_t	len;
	ptrdiff_t	cap;
}	t_strv;

// Integer vector type
typedef struct s_intv
{
	int			*data;
	ptrdiff_t	size;
	ptrdiff_t	len;
	ptrdiff_t	cap;
}	t_intv;

// Generic vector functions
void	*vector_new(t_arena *a, ptrdiff_t elem_count, ptrdiff_t elem_size);

void	vector_init(t_arena *a, void *vecptr, ptrdiff_t elem_count,
			ptrdiff_t elem_size);

void	vector_grow(t_arena *a, void *vecptr);
void	vector_push(t_arena *a, void *vecptr, const void *elem);

// String vector functions
t_strv	*strv_dup(t_arena *a, char **strs);
t_strv	*strv_ndup(t_arena *a, char **strs, ptrdiff_t n);

t_strv	*strv_split(t_arena *a, const char *s, int delim);

// Integer vector functions
int		intv_parse(t_arena *a, t_intv *outv, t_strv *sv);

#endif
