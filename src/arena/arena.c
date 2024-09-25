/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:12:59 by marvin            #+#    #+#             */
/*   Updated: 2024/09/25 17:17:15 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"
#include "libft.h"

#include <stdlib.h>
#include <unistd.h>

t_arena	*arena_new(ptrdiff_t size)
{
	t_arena	*a;

	a = malloc(sizeof(*a));
	if (a == NULL)
	{
		write(STDERR_FILENO, "Error: Failed to allocate memory\n", 33);
		exit(EXIT_FAILURE);
	}
	a->beg = malloc(size);
	if (a->beg == NULL)
	{
		write(STDERR_FILENO, "Error: Failed to allocate memory\n", 33);
		free(a);
		exit(EXIT_FAILURE);
	}
	a->end = a->beg + size;
	a->pos = a->beg;
	return (a);
}

// Newly allocated memory is zeroed out by default for convenience
void	*arena_alloc(t_arena *a, ptrdiff_t size)
{
	ptrdiff_t	align;
	ptrdiff_t	extra;
	ptrdiff_t	padding;
	void		*mem;

	align = sizeof(void *);
	extra = (uintptr_t)a->pos % align;
	if (extra == 0)
		padding = 0;
	else
		padding = align - extra;
	if (a->pos + padding + size > a->end)
	{
		write(STDERR_FILENO, "Error: Arena out of memory\n", 27);
		exit(EXIT_FAILURE);
	}
	mem = a->pos + padding;
	ft_memset(a->pos, 0, padding + size);
	a->pos += padding + size;
	return (mem);
}

void	arena_reset(t_arena *a)
{
	a->pos = a->beg;
}

void	arena_free(t_arena *a)
{
	free(a->beg);
	free(a);
}
