/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verification.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanett <ajeanett@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 14:13:06 by ajeanett          #+#    #+#             */
/*   Updated: 2020/10/25 17:44:42 by ajeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			check_param(t_all *all)
{
	if (!all->g->res)
		ft_e("No resolution", all);
}

static void		check_player(int c, t_all *all, int x, int y)
{
	if (ft_strchr("NSWE", c))
	{
		all->plr->count++;
		all->tmp[y][x] = '0';
	}
	if (all->plr->count > 1)
		ft_e("Invalid map", all);
}

static void		map_final(char **map, int y, t_all *all)
{
	int		x;
	int		j;

	x = 0;
	j = 0;
	while (map[j])
		j++;
	j--;
	y = y - 1;
	while (j >= y)
	{
		x = 0;
		while (map[j][x])
		{
			if (!(ft_strchr("012 NSWE\0", map[j][x])))
				ft_e("Wrong map", all);
			check_player(map[j][x], all, x, j);
			x++;
		}
		j--;
	}
}

void			map_verification(char **map, t_all *all)
{
	int		first_line;
	int		y;
	int		x;

	y = -1;
	while (map[++y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_strchr("012 NSWE", map[y][x]))
			{
				first_line = 1;
				x++;
			}
			else
			{
				first_line = 0;
				break ;
			}
		}
		if (first_line == 1)
			map_final(map, y, all);
	}
}
