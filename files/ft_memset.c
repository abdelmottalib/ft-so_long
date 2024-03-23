/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:57:58 by aqiouami          #+#    #+#             */
/*   Updated: 2022/10/14 11:46:21 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*point;
	size_t			i;

	i = 0;
	point = (unsigned char *)s;
	if (n < 0)
		return (NULL);
	while (i < n)
	{
		*point++ = (unsigned char) c;
		i++;
	}
	return (s);
}
