/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 13:27:22 by aqiouami          #+#    #+#             */
/*   Updated: 2022/10/14 16:14:52 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

static int	lenn(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	nb;

	nb = n;
	len = lenn(nb) - 1;
	str = ft_calloc(len + 2, sizeof(char));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
	{
		free(str);
		return (ft_strdup("0"));
	}
	while (nb > 0)
	{
		str[len--] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
