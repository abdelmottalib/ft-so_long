/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sbstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 08:52:07 by aqiouami          #+#    #+#             */
/*   Updated: 2022/10/14 13:08:11 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"
//if start > slen it will auto return str[i] = '\0';
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	unsigned int	slen;

	i = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (len > slen)
		len = slen;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (i < len && start < slen && s[start])
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
