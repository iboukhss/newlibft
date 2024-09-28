/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:13:15 by marvin            #+#    #+#             */
/*   Updated: 2024/09/26 21:18:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARENA_H
# define ARENA_H

# define ARENA_SIZE 1048576	// 1 MB

# include <stddef.h>

typedef struct s_arena
{
	char	*beg;
	char	*end;
	char	*pos;
}	t_arena;

t_arena	*arena_new(ptrdiff_t size);
void	*arena_alloc(t_arena *a, ptrdiff_t size);
void	arena_reset(t_arena *a);
void	arena_release(t_arena *a);

char	*arena_strdup(t_arena *a, const char *s);
char	*arena_strndup(t_arena *a, const char *s, ptrdiff_t n);

#endif
