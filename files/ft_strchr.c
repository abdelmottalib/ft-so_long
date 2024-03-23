/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:17:48 by aqiouami          #+#    #+#             */
/*   Updated: 2022/10/14 11:20:16 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (!c && !*s)
		return ((char *)s);
	return (0);
}
