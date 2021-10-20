/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanett <ajeanett@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 15:00:55 by ajeanett          #+#    #+#             */
/*   Updated: 2020/10/26 12:46:43 by ajeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		direction(t_plr *plr, int player)
{
	if (player == 'N' || player == 'S')
	{
		if (player == 'N')
		{
			plr->diry = -1;
			plr->planex = 0.66;
		}
		else
		{
			plr->diry = 1;
			plr->planex = -0.66;
		}
	}
	if (player == 'W' || player == 'E')
	{
		plr->dirx = (player == 'W') ? -1 : 1;
		plr->planey = (player == 'W') ? -0.66 : 0.66;
	}
}

static void		ft_set_player(t_plr *plr, int x, int y)
{
	plr->x = x + 0.5;
	plr->y = y + 0.5;
}

void			ft_init_player(char **map, t_plr *plr)
{
	t_point pos;

	ft_bzero(&pos, sizeof(t_point));
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			if (ft_strchr("NSWE", map[pos.y][pos.x]) && (((map[pos.y]
				[pos.x + 1]) == '0') || ((map[pos.y][pos.x + 1]) == '1')
				|| ((map[pos.y][pos.x + 1]) == '2')))
			{
				ft_set_player(plr, pos.x, pos.y);
				direction(plr, map[pos.y][pos.x]);
				map[pos.y][pos.x] = '0';
			}
			if ((map[pos.y][pos.x] == '2') && (((map[pos.y][pos.x + 1]) == '0')
	|| ((map[pos.y][pos.x + 1]) == '1') || ((map[pos.y][pos.x + 1]) == '2')))
				plr->spr_buffer++;
			pos.x++;
		}
		pos.y++;
	}
}
