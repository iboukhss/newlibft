/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:53:49 by marvin            #+#    #+#             */
/*   Updated: 2024/09/24 19:17:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// From man ascii(7)
//
// Oct   Dec   Hex   Char
// ──────────────────────────────────────────────
// 007   7     07    BEL '\a' (bell)
// 010   8     08    BS  '\b' (backspace)
// 011   9     09    HT  '\t' (horizontal tab)
// 012   10    0A    LF  '\n' (new line)
// 013   11    0B    VT  '\v' (vertical tab)
// 014   12    0C    FF  '\f' (form feed)
// 015   13    0D    CR  '\r' (carriage ret)

int	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}
