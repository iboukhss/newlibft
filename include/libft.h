/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:34:25 by marvin            #+#    #+#             */
/*   Updated: 2024/09/24 18:51:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>

// We use ptrdiff_t instead of size_t for consistency across the API
// signed sizes are less prone to bugs.

void		*ft_memcpy(void *dst, const void *src, ptrdiff_t n);
void		*ft_memset(void *dst, int c, ptrdiff_t n);

ptrdiff_t	ft_strlen(const char *s);

int			ft_printf(const char *fmt, ...);
int			ft_dprintf(int fd, const char *fmt, ...);
int			ft_vdprintf(int fd, const char *fmt, va_list ap);

int			int_to_str(char *buf, intmax_t val, ptrdiff_t bufsize);
int			uint_to_str(char *buf, uintmax_t val, int base, ptrdiff_t bufsize);

#endif
