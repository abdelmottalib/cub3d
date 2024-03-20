/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:03:18 by samini            #+#    #+#             */
/*   Updated: 2022/10/10 18:53:48 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "stddef.h"

static size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_retnull(void)
{
	char	*s1;

	s1 = malloc(sizeof(char));
	if (!s1)
		return (0);
	*s1 = '\0';
	return (s1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s1;

	i = start;
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_retnull());
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	s1 = malloc(sizeof(char) * (len + 1));
	if (!s1)
		return (0);
	while (i < len + (size_t)start)
	{
		s1[i - (size_t)start] = s[i];
		i++;
	}
	s1[i - (size_t)start] = '\0';
	return (s1);
}
