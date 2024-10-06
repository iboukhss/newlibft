/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:34:25 by marvin            #+#    #+#             */
/*   Updated: 2024/10/04 13:15:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

// All instances of `size_t` are replaced with `ptrdiff_t`, I find that signed
// sizes are easier to work with and it also makes the library more consistent.

// This is needed to pass the "4 named parameters maximum" rule.
typedef struct s_qsort
{
	void		*base;
	ptrdiff_t	size;
	int			(*comp)(const void *, const void *);
}	t_qsort;

// Core libc functions
void		*ft_memcpy(void *dst, const void *src, ptrdiff_t n);
void		*ft_memset(void *dst, int c, ptrdiff_t n);

int			ft_isdigit(int c);
int			ft_isspace(int c);

ptrdiff_t	ft_strlen(const char *s);

int			ft_printf(const char *fmt, ...);
int			ft_dprintf(int fd, const char *fmt, ...);
int			ft_vdprintf(int fd, const char *fmt, va_list ap);
int			ft_puts(const char *s);

void		ft_qsort(void *base, ptrdiff_t nmemb, ptrdiff_t size,
				int (*cmp)(const void *, const void *));

// Custom functions
int			int_parse(int *out, const char *s);
int			int_format(char *buf, intmax_t val, ptrdiff_t size);
int			uint_format(char *buf, uintmax_t val, int base, ptrdiff_t size);

#endif
