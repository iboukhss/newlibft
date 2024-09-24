/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 22:12:59 by marvin            #+#    #+#             */
/*   Updated: 2024/09/24 02:58:03 by marvin           ###   ########.fr       */
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
	char	*buf;

	if (a->pos + size > a->end)
	{
		write(STDERR_FILENO, "Error: Arena out of memory\n", 27);
		exit(EXIT_FAILURE);
	}
	buf = a->pos;
	ft_memset(buf, 0, size);
	a->pos += size;
	return (buf);
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
