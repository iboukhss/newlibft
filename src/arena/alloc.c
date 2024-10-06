/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:36:32 by marvin            #+#    #+#             */
/*   Updated: 2024/10/06 21:38:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arena.h"

// These functions abstract the creation of the permanent and temporary arenas
// for convenience. Not sure if this is a good decision.

void	allocator_init(t_alloc *handle, ptrdiff_t arena_size)
{
	handle->perm = arena_new(arena_size);
	scratch_init(&handle->temp, arena_size);
}

void	allocator_destroy(t_alloc handle)
{
	arena_release(handle.perm);
	scratch_release(&handle.temp);
}
