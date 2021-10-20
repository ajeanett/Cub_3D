/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanett <ajeanett@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 16:32:05 by ajeanett          #+#    #+#             */
/*   Updated: 2020/10/26 15:10:27 by ajeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void			draw_sprite(t_spr spr, t_all *all)
{
	int			i;
	int			y;

	i = spr.drawstartx;
	while (i < spr.drawendx)
	{
		spr.texx = (int)(256 * (i - (-spr.sprw / 2 + spr.sprscrx))
		* all->win->sprite_tx.width / spr.sprw) / 256;
		if (spr.transformy > 0 && i > 0 && i < all->win->x_win_size
			&& spr.transformy < all->plr->zbuffer[i])
		{
			y = spr.drawstarty - 1;
			while (++y < spr.drawendy)
			{
				spr.d = (y) * 256 - all->win->y_win_size * 128 + spr.sprh * 128;
				spr.texy = ((spr.d * all->win->sprite_tx.height) / spr.sprh
				/ 256);
				spr.spr_pixel = get_pixel(&all->win->sprite_tx,
					spr.texx, spr.texy);
				if (spr.spr_pixel != INVISIBLE_COLOR)
					my_mlx_pixel_put(all->win, i, y, spr.spr_pixel);
			}
		}
		i++;
	}
}

static void			calculate_dist_spr(t_spr *spr, t_plr *plr, int *i,
					t_all *all)
{
	spr[*i].sprx = spr[plr->spr_order[*i]].x - plr->x;
	spr[*i].spry = spr[plr->spr_order[*i]].y - plr->y;
	spr[*i].invdet = 1.0 / (plr->planex * plr->diry - plr->dirx * plr->planey);
	spr[*i].transformx = spr[*i].invdet * (plr->diry * spr[*i].sprx
			- plr->dirx * spr[*i].spry);
	spr[*i].transformy = spr[*i].invdet * (-plr->planey * spr[*i].sprx
			+ plr->planex * spr[*i].spry);
	spr[*i].sprscrx = (int)((all->win->x_win_size / 2) * (1 + spr[*i].transformx
			/ spr[*i].transformy));
}

static void			calc_vert_start_end(t_spr *spr, int *i, t_all *all)
{
	spr[*i].sprh = abs((int)(all->win->y_win_size / (spr[*i].transformy)));
	spr[*i].drawstarty = -spr[*i].sprh / 2 + all->win->y_win_size / 2;
	if (spr[*i].drawstarty < 0)
		spr[*i].drawstarty = 0;
	spr[*i].drawendy = spr[*i].sprh / 2 + all->win->y_win_size / 2;
	if (spr[*i].drawendy >= all->win->y_win_size)
		spr[*i].drawendy = all->win->y_win_size - 1;
}

static void			calc_horiz_start_end(t_spr *spr, int *i, t_all *all)
{
	spr[*i].sprw = abs((int)(all->win->y_win_size / (spr[*i].transformy)));
	spr[*i].drawstartx = -spr[*i].sprw / 2 + spr[*i].sprscrx;
	if (spr[*i].drawstartx < 0)
		spr[*i].drawstartx = 0;
	spr[*i].drawendx = spr[*i].sprw / 2 + spr[*i].sprscrx;
	if (spr[*i].drawendx >= all->win->x_win_size)
		spr[*i].drawendx = all->win->x_win_size - 1;
}

void				calc_sprite(t_all *all)
{
	int			i;
	t_spr		*spr;
	t_plr		*plr;

	spr = all->plr->spr;
	plr = all->plr;
	i = 0;
	while (i < plr->sp_count)
	{
		calculate_dist_spr(spr, plr, &i, all);
		calc_vert_start_end(spr, &i, all);
		calc_horiz_start_end(spr, &i, all);
		draw_sprite(spr[i], all);
		i++;
	}
	if (all->plr->spr_order)
		free(all->plr->spr_order);
	if (all->plr->zbuffer)
		free(all->plr->zbuffer);
}
