/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:13:15 by marvin            #+#    #+#             */
/*   Updated: 2024/10/06 21:41:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

# define ARENA_SIZE 1048576		// 1 MB

# include <stddef.h>

// Arena with 3 pointers, arguably 2 pointers could be sufficient.
typedef struct s_arena
{
	char	*beg;
	char	*end;
	char	*pos;
}	t_arena;

// Allocator handle to pass around a permanent and temporary (scratch) arena
// to functions.
typedef struct s_alloc
{
	t_arena	*perm;
	t_arena	temp;
}	t_alloc;

// Allocator handle for arenas.
void	allocator_init(t_alloc *handle, ptrdiff_t arena_size);
void	allocator_destroy(t_alloc handle);

// This is our replacement for malloc().
void	*arena_alloc(t_arena *a, ptrdiff_t size);

// Constructors and destructors.
t_arena	*arena_new(ptrdiff_t size);
void	arena_release(t_arena *a);

void	scratch_init(t_arena *a, ptrdiff_t arena_size);
void	scratch_release(t_arena *a);

void	arena_reset(t_arena *a);

// Strings?
char	*arena_strdup(t_arena *a, const char *s);
char	*arena_strndup(t_arena *a, const char *s, ptrdiff_t n);

#endif
