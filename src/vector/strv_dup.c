/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strv_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 21:20:10 by marvin            #+#    #+#             */
/*   Updated: 2024/10/01 13:16:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "arena.h"

// Dupicates a null terminated array of strings.
t_strv	*strv_dup(t_arena *a, char **strs)
{
	t_strv		*sv;
	char		*s;
	ptrdiff_t	i;

	i = 0;
	sv = vec_new(a, 1, sizeof(char *));
	while (strs[i] != NULL)
	{
		s = arena_strdup(a, strs[i]);
		vec_push(a, sv, &s);
		++i;
	}
	return (sv);
}
