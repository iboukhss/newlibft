/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strv_to_intv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:53:17 by iboukhss          #+#    #+#             */
/*   Updated: 2024/09/26 11:57:36 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

#include "arena.h"
#include "libft.h"

t_intv	*strv_to_intv(t_arena *perm, t_arena scratch, t_strv *sv)
{
	int		i;
	int		n;
	int		err;
	t_intv	*iv;

	i = 0;
	iv = vector_new(&scratch, 1, sizeof(*(iv->data)));
	while (i < sv->len)
	{
		err = str_to_int(&n, sv->data[i]);
		if (err)
			break ;
		vector_push(&scratch, iv, &n);
		++i;
	}
	return (vector_dup(perm, iv));
}
