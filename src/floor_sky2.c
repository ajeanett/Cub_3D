/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_sky2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanett <ajeanett@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 14:19:48 by ajeanett          #+#    #+#             */
/*   Updated: 2020/10/25 17:38:57 by ajeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_draw_sky(t_all *all, int drawstart, int drawend, int x)
{
	int		y;
	int		i;

	y = drawend + 1;
	i = 0;
	while (y < all->win->y_win_size)
	{
		my_mlx_pixel_put(all->win, x, y, all->win->floor_clr);
		y++;
	}
	while (i < drawstart)
	{
		my_mlx_pixel_put(all->win, x, i, all->win->ceiling_clr);
		i++;
	}
}

int			ft_search(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
		if (str[i++] == ',')
			count++;
	return (count);
}

int			ft_check_digit(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (((str[i] < '0') || (str[i] > '9')) && (str[i] != 32)
			&& (str[i] != 44))
			count++;
		i++;
	}
	return (count);
}
