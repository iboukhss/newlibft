/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:34:25 by marvin            #+#    #+#             */
/*   Updated: 2024/09/24 02:43:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

// We use ptrdiff_t instead of size_t for consistency across the API
// signed sizes are less prone to bugs.

void		*ft_memcpy(void *dst, const void *src, ptrdiff_t n);
void		*ft_memset(void *dst, int c, ptrdiff_t n);

ptrdiff_t	ft_strlen(const char *s);

#endif
