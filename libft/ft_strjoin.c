/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:19:26 by samini            #+#    #+#             */
/*   Updated: 2022/10/10 15:44:55 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		len1;
	int		len2;
	int		i;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	i = 0;
	while (s2[i])
		i++;
	len2 = i;
	s = malloc(sizeof(char) * (len1 + len2));
	if (!s)
		return (0);
	i = -1;
	while (++i < len1)
		s[i] = s1[i];
	i--;
	while (++i < len1 + len2)
		s[i] = s2[i - len1];
	s[i] = '\0';
	return (s);
}
