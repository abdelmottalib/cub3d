/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samini <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:39:59 by samini            #+#    #+#             */
/*   Updated: 2022/10/16 09:38:23 by samini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static int	ft_sizecount(long n)
{
	int	i;

	i = 1;
	while (n / 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_init(int n, long *nbr, int *neg)
{
	*neg = 0;
	if (n < 0)
	{
		*nbr *= -1;
		*neg = 1;
	}
}

char	*ft_itoa(int n)
{
	char	*p;
	int		size;
	int		neg;
	int		i;
	long	nbr;

	nbr = n;
	ft_init(n, &nbr, &neg);
	size = ft_sizecount(nbr);
	p = malloc(sizeof(char) * (size + neg + 1));
	if (!p)
		return (0);
	i = 0;
	if (neg)
		p[0] = '-';
	while (i < size)
	{
		p[size - i -1 + neg] = '0' + nbr % 10;
		nbr = nbr / 10;
		i++;
	}
	p[i + neg] = '\0';
	return (p);
}
