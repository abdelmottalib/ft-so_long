/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <aqiouami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:05:53 by aqiouami          #+#    #+#             */
/*   Updated: 2023/01/02 09:28:58 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	game_loop_helper(t_data *data)
{
	if (data->ptr[data->y_enemy][data->x_enemy] == '1')
	{
		if (data->d_cond == 0)
		{
			data->d_cond = 1;
			data->x_enemy += 1;
		}
		else
		{
			data->d_cond = 0;
			data->x_enemy--;
		}
	}
}

int	game_loop(t_data *data)
{
	render_map(data, 0);
	if (data->x_cond == 7)
	{
		data->x_cond = 0;
		if (data->d_cond == 0)
			data->x_enemy--;
		else
			data->x_enemy++;
		game_loop_helper(data);
		if (data->x_enemy == data->x && data->y_enemy == data->y)
		{
			write(1, "you lose\n", 10);
			exit(0);
		}
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imga_2, \
		data->x_enemy * DIMEN, data->y_enemy * DIMEN);
	}
	data->x_cond++;
	return (0);
}

void	ft_clear(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	ptr = NULL;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		error();
	data.x_cond = 0;
	data.flag = 0;
	data.d_cond = 0;
	data.count = 0;
	check_er(av, &data);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, data.row * DIMEN, \
	data.column * DIMEN, "so_long");
	mlx_hook(data.mlx_win, 17, 0, ft_close, NULL);
	map_spec(&data, 0);
	if (check_path(&data, data.check_y, data.check_x) == 0)
		error();
	collec_path(&data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_hook, &data);
	mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_loop(data.mlx);
	ft_clear(data.ptr);
	ft_destroy(&data);
	ft_clear(data.visited_ptr);
	return (0);
}
