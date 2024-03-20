/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:09:27 by samini            #+#    #+#             */
/*   Updated: 2022/10/10 17:49:16 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static int	ft_checkset(const char s, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_retnull(void)
{
	char	*s;

	s = malloc(sizeof(char));
	if (!s)
		return (0);
	s[0] = '\0';
	return (s);
}

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	ft_finalres(char *s, const char *s1, int end, int start)
{
	int	i;

	i = 0;
	while (i <= end - start)
	{
		s[i] = s1[start + i];
		i++;
	}
	s[i] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	int		i;
	int		check;
	int		start;
	int		end;

	if (!s1)
		return (0);
	i = -1;
	check = ft_checkset(s1[i + 1], set);
	while (s1[++i] && check)
		check = ft_checkset(s1[i + 1], set);
	start = i;
	i = ft_strlen(s1);
	check = ft_checkset(s1[i -1], set);
	while (s1[--i] && check)
		check = ft_checkset(s1[i -1], set);
	end = i;
	if (end < start)
		return (ft_retnull());
	s = malloc(sizeof(char) * (end - start + 2));
	if (!s)
		return (0);
	ft_finalres((char *)s, s1, end, start);
	return (s);
}
