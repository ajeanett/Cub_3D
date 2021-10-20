/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_sky.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanett <ajeanett@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 15:40:09 by ajeanett          #+#    #+#             */
/*   Updated: 2020/10/25 21:41:34 by ajeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		check_rgb_ceiling(int red, int green, int blue, t_all *all)
{
	if ((red > 255) || (green > 255) || (blue > 255))
		ft_e("Wrong ceiling color", all);
	if ((red < 0) || (green < 0) || (blue < 0))
		ft_e("Wrong ceiling color", all);
}

static void		check_rgb_floor(int red, int green, int blue, t_all *all)
{
	if ((red > 255) || (green > 255) || (blue > 255))
		ft_e("Wrong floor color", all);
	if ((red < 0) || (green < 0) || (blue < 0))
		ft_e("Wrong floor color", all);
}

static void		check_tmp(char **tmp, t_all *all)
{
	if (!tmp[0])
		ft_e("Wrong color numbers", all);
	if (!tmp[1])
		ft_e("Wrong color numbers", all);
	if (!tmp[2])
		ft_e("Wrong color numbers", all);
}

void			color_ceiling(t_all *all)
{
	int		red;
	int		green;
	int		blue;
	char	**tmp;

	if (!all->g->ceiling)
		ft_e("Wrong ceiling color", all);
	if (ft_search(all->g->ceiling) != 2)
		ft_e("Wrong ceiling color", all);
	if (ft_check_digit(all->g->ceiling) > 0)
		ft_e("Wrong ceiling color", all);
	if (!(tmp = ft_split(all->g->ceiling, ',')))
		ft_e("Wrong ceiling color", all);
	check_tmp(tmp, all);
	red = ft_atoi(tmp[0]);
	green = ft_atoi(tmp[1]);
	blue = ft_atoi(tmp[2]);
	if (tmp[3])
		ft_e("Wrong ceiling color numbers", all);
	check_rgb_ceiling(red, green, blue, all);
	all->win->ceiling_clr = blue + (green << 8) + (red << 16);
	ft_clear_splitted(tmp);
	if (all->g->ceiling)
		free(all->g->ceiling);
}

void			color_floor(t_all *all)
{
	int		red;
	int		green;
	int		blue;
	char	**tmp;

	if (!all->g->floor)
		ft_e("Wrong floor color", all);
	if (ft_search(all->g->floor) != 2)
		ft_e("Wrong floor color", all);
	if (ft_check_digit(all->g->floor) > 0)
		ft_e("Wrong floor color", all);
	if (!(tmp = ft_split(all->g->floor, ',')))
		ft_e("Wrong floor color", all);
	check_tmp(tmp, all);
	red = ft_atoi(tmp[0]);
	green = ft_atoi(tmp[1]);
	blue = ft_atoi(tmp[2]);
	if (tmp[3])
		ft_e("Wrong floor color numbers", all);
	check_rgb_floor(red, green, blue, all);
	all->win->floor_clr = blue + (green << 8) + (red << 16);
	ft_clear_splitted(tmp);
	if (all->g->floor)
		free(all->g->floor);
}
