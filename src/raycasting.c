/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanett <ajeanett@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 17:36:44 by ajeanett          #+#    #+#             */
/*   Updated: 2020/10/26 14:04:43 by ajeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ray_direction(t_all *all, int x, t_point *map)
{
	all->plr->camerax = 2 * x / (double)all->win->x_win_size - 1;
	all->ray->raydirx = all->plr->dirx + all->plr->planex * all->plr->camerax;
	all->ray->raydiry = all->plr->diry + all->plr->planey * all->plr->camerax;
	map->x = (int)all->plr->x;
	map->y = (int)all->plr->y;
	if (all->ray->raydiry == 0)
		all->ray->deltadistx = 0;
	else
		all->ray->deltadistx = (all->ray->raydirx == 0) ? 0 : \
		fabs(1 / all->ray->raydirx);
	if (all->ray->raydirx == 0)
		all->ray->deltadisty = 0;
	else
		all->ray->deltadisty = (all->ray->raydirx == 0) ? 0 : \
		fabs(1 / all->ray->raydiry);
}

void		step_n_side(t_all *all, t_point *map)
{
	if (all->ray->raydirx < 0)
	{
		all->ray->stepx = -1;
		all->ray->sidedistx = (all->plr->x - map->x) * all->ray->deltadistx;
	}
	else
	{
		all->ray->stepx = 1;
		all->ray->sidedistx = (map->x + 1.0 - all->plr->x) *
			all->ray->deltadistx;
	}
	if (all->ray->raydiry < 0)
	{
		all->ray->stepy = -1;
		all->ray->sidedisty = (all->plr->y - map->y) * all->ray->deltadisty;
	}
	else
	{
		all->ray->stepy = 1;
		all->ray->sidedisty = (map->y + 1.0 - all->plr->y) *
			all->ray->deltadisty;
	}
}

void		calculate_distance(t_all *all, t_point *map)
{
	all->ray->hit = 0;
	while (all->ray->hit == 0)
	{
		check_raycasting(all, *map);
		if (all->ray->sidedistx < all->ray->sidedisty)
		{
			all->ray->sidedistx += all->ray->deltadistx;
			map->x += all->ray->stepx;
			all->ray->side = 0;
		}
		else
		{
			all->ray->sidedisty += all->ray->deltadisty;
			map->y += all->ray->stepy;
			all->ray->side = 1;
		}
		if (all->map[map->y][map->x] == '1')
			all->ray->hit = 1;
	}
	if (all->ray->side == 0)
		all->ray->perpwalldist = (map->x - all->plr->x + \
		(1 - all->ray->stepx) / 2) / all->ray->raydirx;
	else
		all->ray->perpwalldist = (map->y - all->plr->y + \
		(1 - all->ray->stepy) / 2) / all->ray->raydiry;
}

void		calc_vert_line(t_all *all, int x, int *drawstart, int *drawend)
{
	*drawstart = 0;
	*drawend = 0;
	if (!all->ray->perpwalldist)
		ft_e("Invalid map.", all);
	all->plr->zbuffer[x] = all->ray->perpwalldist;
	all->ray->line = all->win->y_win_size / all->ray->perpwalldist;
	*drawstart = -all->ray->line / 2 + all->win->y_win_size / 2;
	if (*drawstart < 0)
		*drawstart = 0;
	*drawend = all->ray->line / 2 + all->win->y_win_size / 2;
	if (*drawend >= all->win->y_win_size)
		*drawend = all->win->y_win_size - 1;
}

void		ft_raycasting(t_all *all)
{
	t_point	map;
	int		x;

	x = -1;
	if (!(all->plr->zbuffer = malloc(sizeof(double) *
		(all->win->x_win_size + 1))))
		ft_e("Not enough memory", all);
	ft_bzero(&map, sizeof(t_point));
	while (++x < all->win->x_win_size)
	{
		ray_direction(all, x, &map);
		step_n_side(all, &map);
		calculate_distance(all, &map);
		calc_vert_line(all, x, &all->plr->drawstart, &all->plr->drawend);
		ft_draw_text(all, all->plr->drawstart, all->plr->drawend, x);
		ft_draw_sky(all, all->plr->drawstart, all->plr->drawend, x);
	}
	ft_sprite(all);
	if (all->save == 1)
		export_bmp(all);
	mlx_put_image_to_window(all->win->mlx, all->win->win, all->win->img, 0, 0);
}
