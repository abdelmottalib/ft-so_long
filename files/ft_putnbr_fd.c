/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <aqiouami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:12:09 by aqiouami          #+#    #+#             */
/*   Updated: 2022/12/10 11:44:03 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb = nb * -1;
		ft_putchar('-');
	}
	if (nb >= 0 && nb <= 9)
	{
		ft_putchar(nb + 48);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10 + 48));
	}
}
