/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <aqiouami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 09:09:48 by aqiouami          #+#    #+#             */
/*   Updated: 2023/01/02 09:54:11 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	check_er(char **av, t_data *data)
{
	int		fd_map;
	char	*line;
	int		i;

	i = 0;
	check_file(av);
	fd_map = open(av[1], O_RDONLY);
	if (fd_map == -1)
		error();
	data->column = count_lines(fd_map);
	close(fd_map);
	fd_map = open(av[1], O_RDONLY);
	data->ptr = double_ptr(data->column);
	data->visited_ptr = double_ptr(data->column);
	line = get_next_line(fd_map);
	while (line)
	{
		data->visited_ptr[i] = ft_calloc(ft_strlen(line), 1);
		data->ptr[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd_map);
	}
	close(fd_map);
	check_validity(data->ptr, data->column, data);
}

void	check_file(char **av)
{
	int	len;

	len = ft_strlen(av[1]) - 4;
	if (ft_strncmp(av[1] + len, ".ber", 4) != 0)
		error();
}

int	count_lines(int fd)
{
	char	line[8];
	int		i;
	int		count;
	int		read_count;

	i = 0;
	count = 0;
	read_count = 1;
	while (read_count > 0)
	{
		read_count = read(fd, line, 7);
		line[read_count] = '\0';
		count += number_of_instances(line, '\n');
		i++;
		if (ft_strlen(line) != 7)
			break ;
	}
	return (count);
}

char	**double_ptr(int count)
{
	char	**ptr;

	ptr = ft_calloc(count + 1, sizeof(char *));
	if (!ptr)
		return (NULL);
	return (ptr);
}

void	check_validity(char **ptr, int count, t_data *data)
{
	int			i;
	int			j;
	static int	e;
	static int	p;
	static int	c;

	data->row = ft_strlen(ptr[0]) - 1;
	i = 1;
	j = 0;
	if (number_of_instances(ptr[count - 2], '1') == data->row)
		error();
	if (number_of_instances(ptr[0], '1') != data->row || \
		number_of_instances(ptr[count - 1], '1') != data->row)
		error();
	while (i < count)
	{
		if (ptr[i][0] != '1' || ptr[i][data->row - 1] != '1')
			error();
		e += number_of_instances(ptr[i], 'E');
		p += number_of_instances(ptr[i], 'P');
		c += number_of_instances(ptr[i], 'C');
		i++;
	}
	if (e > 1 || p > 1 || c == 0 || data->row == data->column)
		error();
}
