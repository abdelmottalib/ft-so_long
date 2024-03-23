/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <aqiouami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 09:57:51 by aqiouami          #+#    #+#             */
/*   Updated: 2023/01/02 08:36:42 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(void)
{
	write(2, "error\n", 6);
	exit(1);
}

void	reset(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->column)
	{
		ft_bzero(data->visited_ptr[i], data->row);
		i++;
	}
}

int	ft_close(void)
{
	exit(1);
	return (0);
}

void	ft_destroy(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img_1);
	mlx_destroy_image(data->mlx, data->img_c);
	mlx_destroy_image(data->mlx, data->img_e);
	mlx_destroy_image(data->mlx, data->img_p);
	mlx_destroy_image(data->mlx, data->imga_2);
	mlx_destroy_window(data->mlx, data->mlx_win);
}
