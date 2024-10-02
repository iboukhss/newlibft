/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strv_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 00:14:12 by marvin            #+#    #+#             */
/*   Updated: 2024/10/02 23:00:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_strv	*strv_split(t_arena *a, const char *s, int delim)
{
	t_strv		*sv;
	const char	*beg;
	char		*dup;

	sv = vector_new(a, 1, sizeof(char *));
	while (*s)
	{
		while (*s == delim)
			++s;
		if (*s == '\0')
			break ;
		beg = s;
		while (*s && *s != delim)
			++s;
		dup = arena_strndup(a, beg, s - beg);
		vector_push(a, sv, &dup);
	}
	return (sv);
}
