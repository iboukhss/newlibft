/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intv_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 00:25:49 by marvin            #+#    #+#             */
/*   Updated: 2024/10/02 23:00:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

#include "libft.h"

int	intv_parse(t_arena *a, t_intv *outv, t_strv *sv)
{
	ptrdiff_t	i;
	int			num;
	int			err;

	i = 0;
	vector_init(a, outv, sv->len, sizeof(int));
	while (i < sv->len)
	{
		err = int_parse(&num, sv->data[i]);
		if (err)
			return (err);
		vector_push(a, outv, &num);
		++i;
	}
	return (0);
}
