/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanett <ajeanett@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:51:00 by ajeanett          #+#    #+#             */
/*   Updated: 2020/10/25 13:45:24 by ajeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		init_textures(t_all *all)
{
	t_text_img img[5];

	img[0] = init_north(img[0], all);
	img[1] = init_south(img[1], all);
	img[2] = init_west(img[2], all);
	img[3] = init_east(img[3], all);
	img[4] = init_sprite(img[4], all);
	all->win->north_tx = img[0];
	all->win->south_tx = img[1];
	all->win->west_tx = img[2];
	all->win->east_tx = img[3];
	all->win->sprite_tx = img[4];
	all->win->north_tx.addr = mlx_get_data_addr(all->win->north_tx.img, &all->
		win->north_tx.bpp, &all->win->north_tx.line_l, &all->win->north_tx.en);
	all->win->south_tx.addr = mlx_get_data_addr(all->win->south_tx.img, &all->
		win->south_tx.bpp, &all->win->south_tx.line_l, &all->win->south_tx.en);
	all->win->east_tx.addr = mlx_get_data_addr(all->win->east_tx.img, &all->
		win->east_tx.bpp, &all->win->east_tx.line_l, &all->win->east_tx.en);
	all->win->west_tx.addr = mlx_get_data_addr(all->win->west_tx.img, &all->
		win->west_tx.bpp, &all->win->west_tx.line_l, &all->win->west_tx.en);
	all->win->sprite_tx.addr = mlx_get_data_addr(all->win->sprite_tx.img, &all->
	win->sprite_tx.bpp, &all->win->sprite_tx.line_l, &all->win->sprite_tx.en);
}

void		textures(t_all *all)
{
	init_textures(all);
}
