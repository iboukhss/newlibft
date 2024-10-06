/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scratch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:35:10 by marvin            #+#    #+#             */
/*   Updated: 2024/10/04 12:36:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

#include <stdlib.h>
#include <unistd.h>

void	scratch_init(t_arena *a, ptrdiff_t size)
{
	a->beg = malloc(size);
	if (a == NULL)
	{
		write(STDERR_FILENO, "Error: Failed to allocate memory\n", 33);
		exit(EXIT_FAILURE);
	}
	a->end = a->beg + size;
	a->pos = a->beg;
}

void	scratch_release(t_arena *a)
{
	free(a->beg);
}
