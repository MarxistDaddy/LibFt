/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamaarab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 17:40:01 by hamaarab          #+#    #+#             */
/*   Updated: 2025/10/23 14:47:33 by hamaarab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_len(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static size_t	word_count(char const *str, char c)
{
	size_t	i;
	size_t	len;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		len = word_len(&str[i], c);
		if (len)
			count++;
		i += len;
	}
	return (count);
}

static char	*ft_strldup(char const *str, int len)
{
	size_t	i;
	char	*dest;

	i = 0;
	while (str[i])
		i++;
	dest = malloc(len + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] && len--)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

static	int	make_split(char **dest, const char *s, char c, size_t words)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s && i < words)
	{
		while (*s && *s == c)
			s++;
		len = word_len(s, c);
		if (len)
		{
			dest[i] = ft_strldup(s, len);
			if (!dest[i])
			{
				while (i--)
					free(dest[i]);
				return (0);
			}
			i++;
		}
		s += len;
	}
	dest[i] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**dest;

	words = word_count(s, c);
	dest = malloc(sizeof(char *) * (words + 1));
	if (!dest)
		return (NULL);
	if (!make_split(dest, s, c, words))
	{
		free(dest);
		return (NULL);
	}
	return (dest);
}
