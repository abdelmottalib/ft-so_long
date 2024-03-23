/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:27:48 by aqiouami          #+#    #+#             */
/*   Updated: 2022/10/20 09:30:45 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*point;
	int		multi;

	point = (char *)malloc(size * count);
	multi = size * count;
	if (!point)
		return (NULL);
	ft_bzero(point, multi);
	return (point);
}
