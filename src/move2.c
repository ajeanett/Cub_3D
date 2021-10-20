/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanett <ajeanett@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 19:10:15 by ajeanett          #+#    #+#             */
/*   Updated: 2020/10/25 15:48:53 by ajeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		turn_right(t_all *all)
{
	all->plr->olddirx = all->plr->dirx;
	all->plr->dirx = all->plr->dirx * cos(ROT_SPEED) -
		all->plr->diry * sin(ROT_SPEED);
	all->plr->diry = all->plr->olddirx * sin(ROT_SPEED) +
		all->plr->diry * cos(ROT_SPEED);
	all->plr->oldplanex = all->plr->planex;
	all->plr->planex = all->plr->planex * cos(ROT_SPEED) -
		all->plr->planey * sin(ROT_SPEED);
	all->plr->planey = all->plr->oldplanex * sin(ROT_SPEED) +
		all->plr->planey * cos(ROT_SPEED);
}

void		turn_left(t_all *all)
{
	all->plr->olddirx = all->plr->dirx;
	all->plr->dirx = all->plr->dirx * cos(-ROT_SPEED) -
		all->plr->diry * sin(-ROT_SPEED);
	all->plr->diry = all->plr->olddirx * sin(-ROT_SPEED) +
		all->plr->diry * cos(-ROT_SPEED);
	all->plr->oldplanex = all->plr->planex;
	all->plr->planex = all->plr->planex * cos(-ROT_SPEED) -
		all->plr->planey * sin(-ROT_SPEED);
	all->plr->planey = all->plr->oldplanex * sin(-ROT_SPEED) +
		all->plr->planey * cos(-ROT_SPEED);
}

void		ft_escape(t_all *all)
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
}
