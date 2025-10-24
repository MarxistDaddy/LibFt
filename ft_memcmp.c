/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:29:03 by hamaarab          #+#    #+#             */
/*   Updated: 2025/10/23 15:43:54 by hamaarab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*sa;
	unsigned char	*sb;

	if (!n)
		return (0);
	sa = (unsigned char *)s1;
	sb = (unsigned char *)s2;
	i = 0;
	while (sa[i] == sb[i] && i < (n - 1))
		i++;
	return ((int)sa[i] - sb[i]);
}
