/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:50:24 by iboukhss          #+#    #+#             */
/*   Updated: 2024/09/26 11:51:20 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

#include "arena.h"
#include "libft.h"

t_strv	*split_str(t_arena *perm, t_arena scratch, const char *s)
{
	t_strv		*sv;
	const char	*end;
	char		*str;

	sv = vector_new(&scratch, 1, sizeof(*(sv->data)));
	while (*s)
	{
		while(ft_isspace(*s))
			++s;
		if (*s == '\0')
			break ;
		end = s;
		while (*end && !ft_isspace(*end))
			++end;
		str = arena_strndup(perm, s, end - s);
		vector_push(&scratch, sv, &str);
		s = end;
	}
	return (vector_dup(perm, sv));
}
