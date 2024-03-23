/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:19:32 by aqiouami          #+#    #+#             */
/*   Updated: 2022/10/14 09:26:31 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((*s1 || *s2) && i < n)
	{
		if (*s1 != *s2)
			return ((unsigned char)(*s1) - (unsigned char)(*s2));
		s1++;
		s2++;
		i++;
	}
	return (0);
}
