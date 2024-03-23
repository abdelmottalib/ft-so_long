/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <aqiouami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 09:55:12 by aqiouami          #+#    #+#             */
/*   Updated: 2023/01/02 08:39:23 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 13)
		move_w(data);
	if (keycode == 0)
		move_a(data);
	if (keycode == 1)
		move_s(data);
	if (keycode == 2)
		move_d(data);
	return (0);
}

void	move_w(t_data *data)
{
	if (data->ptr[data->y - 1][data->x] == 'E' && check_c(data) != 0)
		exit(0);
	if (data->ptr[data->y - 1][data->x] != '1' &&
			data->ptr[data->y - 1][data->x] != 'E')
	{
		data->y -= 1;
		data->count++;
		if (data->flag == 0)
		{
			ft_putnbr(data->count);
			ft_putchar('\n');
		}
	}
	if (data->ptr[data->y][data->x] == 'C')
		data->ptr[data->y][data->x] = '0';
	if (data->x == data->x_enemy && data->y == data->y_enemy)
	{
		write(1, "you lose\n", 10);
		exit(0);
	}
}

void	move_a(t_data *data)
{
	if (data->ptr[data->y][data->x - 1] == 'E' && check_c(data) != 0)
		exit(0);
	if (data->ptr[data->y][data->x - 1] != '1' &&
			data->ptr[data->y][data->x - 1] != 'E')
	{
		data->x -= 1;
		data->count++;
		if (data->flag == 0)
		{
			ft_putnbr(data->count);
			ft_putchar('\n');
		}
	}
	if (data->ptr[data->y][data->x] == 'C')
		data->ptr[data->y][data->x] = '0';
	if (data->x == data->x_enemy && data->y == data->y_enemy)
	{
		write(1, "you lose\n", 10);
		exit(0);
	}
}

void	move_s(t_data *data)
{
	if (data->ptr[data->y + 1][data->x] == 'E' && check_c(data) != 0)
		exit(0);
	if (data->ptr[data->y + 1][data->x] != '1' &&
			data->ptr[data->y + 1][data->x] != 'E')
	{
		data->y += 1;
		data->count++;
		if (data->flag == 0)
		{
			ft_putnbr(data->count);
			ft_putchar('\n');
		}
	}
	if (data->ptr[data->y][data->x] == 'C')
		data->ptr[data->y][data->x] = '0';
	if (data->x == data->x_enemy && data->y == data->y_enemy)
	{
		write(1, "you lose\n", 10);
		exit(0);
	}
}

void	move_d(t_data *data)
{
	if (data->ptr[data->y][data->x + 1] == 'E' && check_c(data) != 0)
		exit(0);
	if (data->ptr[data->y][data->x + 1] != '1' &&
			data->ptr[data->y][data->x + 1] != 'E')
	{
		data->x += 1;
		data->count++;
		if (data->flag == 0)
		{
			ft_putnbr(data->count);
			ft_putchar('\n');
		}
	}
	if (data->ptr[data->y][data->x] == 'C')
		data->ptr[data->y][data->x] = '0';
	if (data->x == data->x_enemy && data->y == data->y_enemy)
	{
		write(1, "you lose\n", 10);
		exit(0);
	}
}
