/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanett <ajeanett@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 17:54:13 by ajeanett          #+#    #+#             */
/*   Updated: 2020/10/25 21:15:32 by ajeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			get_pixel(t_text_img *img, int x, int y)
{
	int		*addr;
	int		color;

	addr = (void *)img->addr + (y * img->line_l + x * \
		(img->bpp / 8));
	color = *(int*)addr;
	return (color);
}

void		my_mlx_pixel_put(t_win *win, int x, int y, int color)
{
	char	*dst;

	dst = win->addr + (y * win->line_l + x * (win->bpp / 8));
	*(unsigned int*)dst = color;
}

int			ft_exit(t_all *all)
{
	if (all->map)
		free_map(all->map);
	if (all->tmp)
		free_map(all->map);
	if (all->win->img)
		mlx_destroy_image(all->win->mlx, all->win->img);
	if (all->win->win)
		mlx_destroy_window(all->win->mlx, all->win->win);
	ft_putendl_fd(("Thanks for playing!"), 2);
	exit(0);
	return (0);
}
