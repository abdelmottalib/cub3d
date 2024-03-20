/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 08:38:20 by samini            #+#    #+#             */
/*   Updated: 2022/10/28 10:56:33 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_tools
{
	char	*line;
	char	*buf;
	char	*temp;
	ssize_t	retread;
}	t_tools;

int		ft_strlen2(char *s);
char	*ft_strdup2(char *s1);
char	*ft_get_line(char **stash);
int		ft_isline(char *s);
char	*get_next_line(int fd);
char	*ft_strjoin2(char *s1, char *s2);

#endif
