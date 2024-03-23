/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <aqiouami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 09:56:07 by aqiouami          #+#    #+#             */
/*   Updated: 2023/01/02 08:36:57 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_c(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->ptr[i])
	{
		j = 0;
		while (data->ptr[j])
		{
			if (data->ptr[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
