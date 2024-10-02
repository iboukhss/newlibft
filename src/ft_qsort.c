/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 23:35:36 by marvin            #+#    #+#             */
/*   Updated: 2024/10/02 16:13:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
#include <unistd.h>

// NOTE: This is probably where a scratch arena would have been useful?
static void	swap(void *a, void *b, ptrdiff_t size)
{
	void	*tmp;

	tmp = malloc(size);
	if (tmp == NULL)
	{
		write(STDERR_FILENO, "Error: Failed to allocate memory\n", 33);
		exit(EXIT_FAILURE);
	}
	ft_memcpy(tmp, a, size);
	ft_memcpy(a, b, size);
	ft_memcpy(b, tmp, size);
	free(tmp);
}

static int	partition(t_qsort *q, int low, int high)
{
	char	*basep;
	char	*pivot;
	char	*current;
	int		i;
	int		j;

	basep = (char *)q->base;
	pivot = basep + (high * q->size);
	i = low - 1;
	j = low;
	while (j < high)
	{
		current = basep + (j * q->size);
		if (q->comp(current, pivot) < 0)
		{
			++i;
			swap(basep + (i * q->size), current, q->size);
		}
		++j;
	}
	swap(basep + (i + 1) * q->size, pivot, q->size);
	return (i + 1);
}

// NOTE: pi stands for pivot index.
static void	quicksort_internal(t_qsort *q, int low, int high)
{
	int	pi;

	if (low >= high)
		return ;
	pi = partition(q, low, high);
	quicksort_internal(q, low, pi - 1);
	quicksort_internal(q, pi + 1, high);
}

void	ft_qsort(void *base, ptrdiff_t nmemb, ptrdiff_t size,
			int (*cmp)(const void *, const void *))
{
	t_qsort	q;

	q.base = base;
	q.size = size;
	q.comp = cmp;
	quicksort_internal(&q, 0, nmemb - 1);
}
