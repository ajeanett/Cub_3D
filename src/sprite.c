/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanett <ajeanett@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:25:02 by ajeanett          #+#    #+#             */
/*   Updated: 2020/10/26 15:03:39 by ajeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			sort_sprite(t_all *all)
{
	t_spr		*spr;
	int			i;
	int			temp;
	double		temp2;

	spr = all->plr->spr;
	i = 0;
	while (i < all->plr->sp_count - 1)
	{
		if (spr[i].spritedist < spr[i + 1].spritedist)
		{
			temp2 = spr[i + 1].spritedist;
			spr[i + 1].spritedist = spr[i].spritedist;
			spr[i].spritedist = temp2;
			temp = all->plr->spr_order[i + 1];
			all->plr->spr_order[i + 1] = all->plr->spr_order[i];
			all->plr->spr_order[i] = temp;
			i = 0;
		}
		else
			i++;
	}
}

void			sprite_distance(t_all *all)
{
	int			i;

	i = 0;
	if (!(all->plr->spr_order = malloc(sizeof(double) *
		(all->plr->sp_count + 1))))
		ft_e("Not enough memory.", all);
	while (i < all->plr->sp_count)
	{
		all->plr->spr_order[i] = i;
		all->plr->spr[i].spritedist = (all->plr->x - all->plr->spr[i].x) *
		(all->plr->x - all->plr->spr[i].x) + (all->plr->y - all->plr->spr[i].y)
		* (all->plr->y - all->plr->spr[i].y);
		i++;
	}
	all->plr->spr_order[i] = i;
}

void			ft_sprite(t_all *all)
{
	sprite_distance(all);
	sort_sprite(all);
	calc_sprite(all);
}
