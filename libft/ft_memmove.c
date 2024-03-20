/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:10:27 by samini            #+#    #+#             */
/*   Updated: 2022/10/08 18:32:46 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stddef.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == 0 && src == 0)
		return (0);
	i = 0;
	if (src < dst)
	{
		while (i < len)
		{
			*((char *)dst + len - i -1) = *((char *)src + len - i -1);
			i++;
		}
		return (dst);
	}
	while (i < len)
	{
		*((char *)dst + i) = *((char *)src + i);
		i++;
	}
	return (dst);
}
