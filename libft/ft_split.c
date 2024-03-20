/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <samini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:43:33 by samini            #+#    #+#             */
/*   Updated: 2023/06/19 09:50:03 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	ft_arraycount(char const *s, char c)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	ft_strlenc(char *p, char c)
{
	int	i;

	i = 0;
	while (p[i] && p[i] != c)
		i++;
	return (i);
}

static char	*ft_word(char *s, char c)
{
	char	*word;
	int		len;
	int		i;

	i = 0;
	len = ft_strlenc(s, c);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (0);
	while (i < len)
	{
		word[i] = *s;
		s++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	ft_cleanup(char ***result, int size)
{
	char	**res;
	int		i;

	res = *result;
	i = 0;
	while (i < size)
	{
		if (res[i])
			i++;
		else
			break ;
	}
	if (i == size)
		return ;
	i = 0;
	while (i < size)
	{
		free(res[i]);
		i++;
	}
	free(res);
	res = NULL;
	return (printf("Error\nCouldn't allocate memory,\n"), exit(1));
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		size;
	int		i;
	char	*p;

	if (!s)
		return (0);
	i = 0;
	p = (char *) s;
	size = ft_arraycount(s, c);
	result = malloc(sizeof(char *) * (size + 1));
	if (!result)
		return (0);
	while (i < size)
	{
		while (*p && *p == c)
			p++;
		if (*p)
			result[i++] = ft_word(p, c);
		while (*p && *p != c)
			p++;
	}
	result[i] = 0;
	ft_cleanup(&result, size);
	return (result);
}
