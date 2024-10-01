/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:20:04 by marvin            #+#    #+#             */
/*   Updated: 2024/10/01 23:33:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pribuf.h"

static int	handle_modifier(t_pribuf *pb, int mod, va_list ap)
{
	if (mod == '%')
		return (append_byte(pb, '%'));
	else if (mod == 'c')
		return (append_byte(pb, va_arg(ap, int)));
	else if (mod == 's')
		return (append_str(pb, va_arg(ap, char *)));
	else if (mod == 'd' || mod == 'i')
		return (append_int(pb, va_arg(ap, int)));
	else if (mod == 'u')
		return (append_uint(pb, va_arg(ap, unsigned int)));
	else if (mod == 'p')
		return (append_hex(pb, va_arg(ap, uintptr_t)));
	else if (mod == 'x')
		return (append_hex(pb, va_arg(ap, unsigned int)));
	else if (mod == 'b')
		return (append_bin(pb, va_arg(ap, unsigned int)));
	else if (mod == 'o')
		return (append_oct(pb, va_arg(ap, unsigned int)));
	else if (mod == 't')
		return (append_pdiff(pb, va_arg(ap, ptrdiff_t)));
	else if (mod == 'z')
		return (append_size(pb, va_arg(ap, size_t)));
	return (-1);
}

int	ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	t_pribuf	pb;

	pribuf_init(&pb, fd, PRIBUF_SIZE);
	while (*fmt != '\0')
	{
		if (*fmt == '%' && *(fmt + 1) != '\0')
		{
			++fmt;
			if (handle_modifier(&pb, *fmt, ap) == -1)
				return (-1);
		}
		else
		{
			if (append_byte(&pb, *fmt) == -1)
				return (-1);
		}
		++fmt;
	}
	if (pribuf_flush(&pb) == -1)
		return (-1);
	return (pb.written);
}
