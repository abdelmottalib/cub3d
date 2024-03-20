/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:49:32 by samini            #+#    #+#             */
/*   Updated: 2022/10/28 09:30:41 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_clean_stash(char *st)
{
	char	*stash;
	int		i;

	i = 0;
	stash = NULL;
	if (!st)
		return (NULL);
	while (st[i] && st[i] != '\n')
		i++;
	stash = ft_strdup2(st + i + 1);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	t_tools		x;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (!ft_isline(stash))
	{
		x.buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!x.buf)
			return (NULL);
		x.retread = read(fd, x.buf, BUFFER_SIZE);
		if (x.retread == 0)
			return (free(x.buf), x.temp = stash, stash = 0, x.temp);
		if (x.retread == -1)
			return (free(x.buf), NULL);
		x.buf[x.retread] = '\0';
		x.temp = stash;
		stash = ft_strjoin2(stash, x.buf);
		free(x.temp);
		free(x.buf);
	}
	x.line = ft_get_line(&stash);
	x.temp = stash;
	stash = ft_clean_stash(stash);
	return (free(x.temp), x.line);
}
