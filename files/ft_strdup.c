/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 08:15:40 by aqiouami          #+#    #+#             */
/*   Updated: 2022/10/16 08:15:46 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	char	*start;
	int		i;
	int		n;

	i = 0;
	n = ft_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * (n + 1));
	start = ptr;
	if (!ptr)
		return (NULL);
	while (*s1)
		*ptr++ = *s1++;
	*ptr = '\0';
	return (start);
}
