/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanett <ajeanett@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 18:00:31 by ajeanett          #+#    #+#             */
/*   Updated: 2020/10/26 13:13:47 by ajeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char				**ft_clear_splitted(char **str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

void				check_splitted_res(char **splitted, t_all *all)
{
	if (!splitted[0])
		ft_e("Wrong resolution", all);
	if (!splitted[1])
		ft_e("Wrong resolution", all);
	if (!splitted[2])
		ft_e("Wrong resolution", all);
	if (splitted[3])
		ft_e("Wrong resolution", all);
}

void				make_new_window(t_all *all)
{
	if (!(all->save))
		all->win->win = mlx_new_window(all->win->mlx,\
			all->g->r_x, all->g->r_y, "cub3D");
	all->win->img = mlx_new_image(all->win->mlx, all->g->r_x, all->g->r_y);
	all->win->addr = mlx_get_data_addr(all->win->img, \
		&all->win->bpp, &all->win->line_l, &all->win->en);
	all->win->x_win_size = all->g->r_x;
	all->win->y_win_size = all->g->r_y;
}

void				free_map(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		tmp[i] = NULL;
		i++;
	}
}

void				check_raycasting(t_all *all, t_point map)
{
	if ((all->map[map.y][map.x] != '1') &&
		(all->map[map.y][map.x] != '2')
		&& (all->map[map.y][map.x] != '0'))
		ft_e("Invalid map", all);
}
