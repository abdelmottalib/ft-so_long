/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <aqiouami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 09:52:39 by aqiouami          #+#    #+#             */
/*   Updated: 2023/01/02 09:20:44 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	map_spec(t_data *data, int flag)
{
	int	i;
	int	j;

	i = 0;
	data->img_1 = mlx_xpm_file_to_image(data->mlx, "w.xpm", &data->w, &data->h);
	data->img_p = mlx_xpm_file_to_image(data->mlx, "p.xpm", &data->w, &data->h);
	data->img_c = mlx_xpm_file_to_image(data->mlx, "c.xpm", &data->w, &data->h);
	data->img_e = mlx_xpm_file_to_image(data->mlx, "e.xpm", &data->w, &data->h);
	data->imga_1 = mlx_xpm_file_to_image(data->mlx, "a1.xpm", \
	&data->w, &data->h);
	data->imga_2 = mlx_xpm_file_to_image(data->mlx, "a2.xpm", \
	&data->w, &data->h);
	if (data->img_1 == NULL || data->img_p == NULL || data->imga_2 == NULL \
		|| data->img_c == NULL || data->img_e == NULL || data->imga_1 == NULL)
		error();
	while (i < data->column)
	{
		j = 0;
		while (j < data->row)
		{
			condition_map(data, i, j, flag);
			j++;
		}
		i++;
	}
}

void	condition_map(t_data *data, int i, int j, int flag)
{
	if (data->ptr[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
		data->img_1, j * 32, i * 32);
	if (data->ptr[i][j] == 'P')
	{
		if (flag == 0)
			coord_p(data, i, j);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img_p, \
		data->x * 32, data->y * 32);
	}
	if (data->ptr[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
		data->img_c, j * 32, i * 32);
	if (data->ptr[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, \
		data->img_e, j * 32, i * 32);
	if (data->ptr[i][j] == 'A')
	{
		if (flag == 0)
			coord_a(data, i, j);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->imga_1, \
		data->x_enemy * 32, data->y_enemy * 32);
	}
}

void	coord_p(t_data *data, int i, int j)
{
	data->check_x = j;
	data->check_y = i;
	data->x = j;
	data->y = i;
}

void	coord_a(t_data *data, int i, int j)
{
	data->x_enemy = j;
	data->y_enemy = i;
}

void	render_map(t_data *data, int flag)
{
	char	*o;

	mlx_clear_window(data->mlx, data->mlx_win);
	map_spec(data, 1);
	o = ft_itoa(data->count);
	if (flag == 1)
	{
		mlx_string_put(data->mlx, data->mlx_win, 5, 5, 0x00FF0000, \
		o);
	}
	free (o);
}
