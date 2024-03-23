/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqiouami <aqiouami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:11:05 by aqiouami          #+#    #+#             */
/*   Updated: 2023/01/02 08:53:24 by aqiouami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define DIMEN 32
# include "./get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <stdbool.h>
# include <fcntl.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

typedef struct s_data
{
	int		column;
	int		row;
	char	**ptr;
	char	**visited_ptr;
	int		w;
	int		flag;
	int		h;
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
	int		check_x;
	int		check_y;
	int		x_collec;
	int		y_collec;
	void	*img_p;
	void	*img_c;
	void	*img_1;
	void	*imga_1;
	void	*imga_2;
	int		x_enemy;
	int		y_enemy;
	void	*img_e;
	int		count;
	int		x_cond;
	int		d_cond;
}t_data;

typedef struct s_map_vars
{
	int	i;
	int	j;

}t_map_vars;

char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
void	check_errors(char **ptr, int fd_map);
char	**double_ptr(int count);
int		count_lines(int fd);
void	parssing(char *str);
int		number_of_instances(char *str, char letter);
void	error(void);
char	**ft_split(char const *s, char c);
void	ft_putnbr(int n);
void	ft_putchar(int c);
void	check_er(char **av, t_data *data);
void	check_file(char **av);
int		count_lines(int fd);
char	**double_ptr(int count);
void	check_validity(char **ptr, int count, t_data *data);
int		number_of_instances(char *str, char letter);
void	coord_p(t_data *data, int i, int j);
void	condition_map(t_data *data, int i, int j, int flag);
void	map_spec(t_data *data, int flag);
int		key_hook(int keycode, t_data *data);
void	move_w(t_data *data);
void	move_a(t_data *data);
void	move_s(t_data *data);
void	move_d(t_data *data);
int		check_c(t_data *data);
void	render_map(t_data *data, int flag);
int		ft_close(void);
void	reset(t_data *data);
void	error(void);
int		check_path(t_data *data, int y, int x);
int		check_path_collec(t_data *data, int y, int x);
void	collec_path(t_data *data);
void	coord_a(t_data *data, int i, int j);
void	ft_clear(char **ptr);
void	ft_free(t_data *data);
void	ft_destroy(t_data *data);
#endif
