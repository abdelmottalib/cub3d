/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 19:44:32 by samini            #+#    #+#             */
/*   Updated: 2022/10/10 15:38:18 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	len1 = 0;
	len2 = 0;
	j = -1;
	while (dst[++j])
		len1++;
	i = -1;
	while (src[++i])
		len2++;
	if (dstsize == 0 || dstsize <= len1)
		return (len2 + dstsize);
	i = 0;
	while (src[i] && i < dstsize - 1 - j)
	{
		dst[j + i] = src[i];
		i++;
	}
	dst[j + i] = '\0';
	return (len1 + len2);
}
