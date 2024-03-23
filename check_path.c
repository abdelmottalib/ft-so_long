/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <aqiouami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:01:12 by aqiouami          #+#    #+#             */
/*   Updated: 2023/01/02 08:36:08 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	check_path(t_data *data, int y, int x)
{
	if (data->ptr[y][x] == 'E')
		return (true);
	else if (data->ptr[y][x] == '1' || data->ptr[y][x] == 'A' ||
	data->visited_ptr[y][x] == '1')
		return (false);
	data->visited_ptr[y][x] = '1';
	if (check_path(data, y + 1, x) == true)
		return (true);
	if (check_path(data, y - 1, x) == true)
		return (true);
	if (check_path(data, y, x + 1) == true)
		return (true);
	if (check_path(data, y, x - 1) == true)
		return (true);
	return (false);
}

int	check_path_collec(t_data *data, int y, int x)
{
	if (data->ptr[y][x] == 'P')
		return (1);
	else if (data->ptr[y][x] == '1' || data->ptr[y][x] == 'A' ||
	data->visited_ptr[y][x] == '1' ||
	data->ptr[y][x] == 'E')
		return (0);
	data->visited_ptr[y][x] = '1';
	return (check_path_collec(data, y + 1, x) || \
	check_path_collec(data, y - 1, x) || \
	check_path_collec(data, y, x + 1) || check_path_collec(data, y, x - 1));
}

void	collec_path(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->ptr[i])
	{
		j = 0;
		while (data->ptr[i][j])
		{
			if (data->ptr[i][j] == 'C')
			{
				reset(data);
				if (check_path_collec(data, i, j) == 0)
					error();
			}
			j++;
		}
		i++;
	}
}
