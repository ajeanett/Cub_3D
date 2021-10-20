/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanett <ajeanett@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 18:42:44 by ajeanett          #+#    #+#             */
/*   Updated: 2020/10/25 15:46:33 by ajeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		move_right(t_all *all)
{
	if (all->map[(int)(all->plr->y + all->plr->dirx * MOVE_SPEED)]
			[(int)all->plr->x] == '0')
		all->plr->y += all->plr->dirx * MOVE_SPEED;
	if (all->map[(int)all->plr->y][(int)(all->plr->x - all->plr->diry
				* MOVE_SPEED)] == '0')
		all->plr->x -= all->plr->diry * MOVE_SPEED;
}

static void		move_left(t_all *all)
{
	if (all->map[(int)(all->plr->y - all->plr->dirx * MOVE_SPEED)]
			[(int)all->plr->x] == '0')
		all->plr->y -= all->plr->dirx * MOVE_SPEED;
	if (all->map[(int)all->plr->y][(int)(all->plr->x + all->plr->diry
		* MOVE_SPEED)] == '0')
		all->plr->x += all->plr->diry * MOVE_SPEED;
}

static void		move_forward(t_all *all)
{
	if (all->map[(int)(all->plr->y + all->plr->diry * MOVE_SPEED)]
			[(int)all->plr->x] == '0')
		all->plr->y += all->plr->diry * MOVE_SPEED;
	if (all->map[(int)all->plr->y][(int)(all->plr->x + all->plr->dirx
		* MOVE_SPEED)] == '0')
		all->plr->x += all->plr->dirx * MOVE_SPEED;
}

static void		move_back(t_all *all)
{
	if (all->map[(int)(all->plr->y - all->plr->diry * MOVE_SPEED)]
			[(int)all->plr->x] == '0')
		all->plr->y -= all->plr->diry * MOVE_SPEED;
	if (all->map[(int)all->plr->y][(int)(all->plr->x - all->plr->dirx
		* MOVE_SPEED)] == '0')
		all->plr->x -= all->plr->dirx * MOVE_SPEED;
}

int				key_press(int key, t_all *all)
{
	if (key == 2)
		move_right(all);
	if (key == 0)
		move_left(all);
	if (key == 13)
		move_forward(all);
	if (key == 1)
		move_back(all);
	if (key == 123)
		turn_left(all);
	if (key == 124)
		turn_right(all);
	if (key == 53)
		ft_escape(all);
	ft_raycasting(all);
	return (0);
}
