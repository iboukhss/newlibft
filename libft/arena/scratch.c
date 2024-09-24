/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scratch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 02:11:31 by marvin            #+#    #+#             */
/*   Updated: 2024/09/24 03:52:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

#include <stdlib.h>
#include <unistd.h>

void	scratch_init(t_arena *a, ptrdiff_t size)
{
	a->beg = malloc(size);
	if (a->beg == NULL)
	{
		write(STDERR_FILENO, "Error: Failed to allocate memory\n", 33);
		exit(EXIT_FAILURE);
	}
	a->end = a->beg + size;
	a->pos = a->beg;
}

void	scratch_free(t_arena *a)
{
	free(a->beg);
}
