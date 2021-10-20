/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanett <ajeanett@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 19:14:07 by ajeanett          #+#    #+#             */
/*   Updated: 2020/10/26 14:51:40 by ajeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		set_current_texture(t_all *all, int texnum)
{
	if (texnum == 0)
		all->win->current = all->win->north_tx;
	else if (texnum == 1)
		all->win->current = all->win->south_tx;
	else if (texnum == 2)
		all->win->current = all->win->west_tx;
	else if (texnum == 3)
		all->win->current = all->win->east_tx;
}

int				txt_choice(t_all *all)
{
	int	texnum;

	if ((all->ray->side == 0) && all->ray->raydirx >= 0)
		texnum = 3;
	else if ((all->ray->side == 0) && all->ray->raydirx < 0)
		texnum = 2;
	else if ((all->ray->side == 1) && all->ray->raydiry < 0)
		texnum = 0;
	else
		texnum = 1;
	return (texnum);
}

void			calc_wall_hit(t_all *all, double *wallx)
{
	if (all->ray->side == 0)
		*wallx = all->plr->y + all->ray->perpwalldist * all->ray->raydiry;
	else
		*wallx = all->plr->x + all->ray->perpwalldist * all->ray->raydirx;
	*wallx -= floor((*wallx));
}

void			coord_texture(t_all *all, int *texx)
{
	if (all->ray->side == 0 && all->ray->raydirx >= 0)
		*texx = all->win->current.width - *texx - 1;
	if (all->ray->side == 1 && all->ray->raydiry < 0)
		*texx = all->win->current.width - *texx - 1;
}

void			ft_draw_text(t_all *all, int drawstart, int drawend, int x)
{
	double	wallx;
	int		texx;
	int		texy;
	double	step;
	int		text_choice;

	calc_wall_hit(all, &wallx);
	text_choice = txt_choice(all);
	set_current_texture(all, text_choice);
	texx = (int)(wallx * (double)(all->win->current.width));
	coord_texture(all, &texx);
	step = 1.0 * all->win->current.height / all->ray->line;
	all->plr->texpos = (drawstart - all->win->y_win_size / 2 +
			all->ray->line / 2) * step;
	while (drawstart < drawend)
	{
		texy = 0;
		texy = (int)all->plr->texpos & (all->win->current.height - 1);
		all->plr->texpos += step;
		all->plr->texture_pixel = get_pixel(&all->win->current, texx, texy);
		my_mlx_pixel_put(all->win, x, drawstart, all->plr->texture_pixel);
		drawstart++;
	}
}
