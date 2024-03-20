/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 08:39:11 by samini            #+#    #+#             */
/*   Updated: 2022/10/27 17:43:42 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen2(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup2(char *s1)
{
	char	*s;
	int		len;
	int		i;

	if (!s1)
		return (0);
	len = ft_strlen2(s1);
	s = malloc(sizeof(char) * (len + 1));
	if (!s)
		return (0);
	i = 0;
	while (i < len)
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*s;
	int		len1;
	int		len2;
	int		i;

	len1 = 0;
	if (s1)
		len1 = ft_strlen2(s1);
	len2 = ft_strlen2(s2);
	s = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!s)
		return (0);
	i = 0;
	while (i < len1)
	{
		s[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		s[i] = s2[i - len1];
		i++;
	}
	s[i] = '\0';
	return (s);
}

int	ft_isline(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	if (s[i] == '\n')
		return (1);
	return (0);
}

char	*ft_get_line(char **stash)
{
	char	*str;
	int		len;
	int		i;
	char	*s;

	len = 0;
	s = *stash;
	while (s[len] && s[len] != '\n')
		len++;
	if (s[len] == '\n')
		len++;
	if (s[len] == '\0')
	{
		str = s;
		*stash = 0;
		return (str);
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < len)
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}
