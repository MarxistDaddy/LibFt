/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:27:40 by hamaarab          #+#    #+#             */
/*   Updated: 2025/10/18 10:24:57 by hamaarab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <limits.h>

static	int	count(int n)
{
	long	nb;
	int		count;

	nb = n;
	count = 1;
	if (n < 0)
	{
		nb = -(long)n;
		count = 2;
	}
	while (nb > 9)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*dest;
	int		len;

	len = (count(n));
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	nb = n;
	if (n < 0)
		nb = -(long)n;
	dest[len] = 0;
	while (len--)
	{
		dest[len] = nb % 10 + 48;
		nb /= 10;
	}
	if (n < 0)
		dest[0] = '-';
	return (dest);
}
