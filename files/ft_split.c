/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 08:18:44 by aqiouami          #+#    #+#             */
/*   Updated: 2022/10/16 08:19:05 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

static size_t	word_count(char *str, char c)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
			k++;
		while (str[i] != c && str[i])
			i++;
	}
	return (k);
}

static char	**error_handling(char **str, int len)
{
	int	i;

	i = 0;
	while (i <= len)
		free (str[i++]);
	free (str);
	str = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	size_t	w;
	char	**str;

	i = 0;
	w = 0;
	if (!s)
		return (NULL);
	str = ft_calloc(word_count((char *)s, c) + 1, sizeof(char *));
	if (!str)
		return (NULL);
	while (w < (word_count((char *)s, c)))
	{
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[i] != c && s[i])
			i++;
		str[w++] = ft_substr(s, j, i - j);
		if (!str)
			return (error_handling(str, i));
	}
	return (str);
}
