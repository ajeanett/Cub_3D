/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tex2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanett <ajeanett@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:51:36 by ajeanett          #+#    #+#             */
/*   Updated: 2020/10/25 13:45:28 by ajeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_text_img	init_north(t_text_img img, t_all *all)
{
	if (!(img.img = mlx_xpm_file_to_image(all->win->mlx, all->g->north,
	&img.width, &img.height)))
		ft_e("Wrong north texture", all);
	if (all->g->north)
		free(all->g->north);
	return (img);
}

t_text_img	init_south(t_text_img img, t_all *all)
{
	if (!(img.img = mlx_xpm_file_to_image(all->win->mlx, all->g->south,
	&img.width, &img.height)))
		ft_e("Wrong south texture", all);
	if (all->g->south)
		free(all->g->south);
	return (img);
}

t_text_img	init_west(t_text_img img, t_all *all)
{
	if (!(img.img = mlx_xpm_file_to_image(all->win->mlx, all->g->west,
	&img.width, &img.height)))
		ft_e("Wrong west texture", all);
	if (all->g->west)
		free(all->g->west);
	return (img);
}

t_text_img	init_east(t_text_img img, t_all *all)
{
	if (!(img.img = mlx_xpm_file_to_image(all->win->mlx, all->g->east,
	&img.width, &img.height)))
		ft_e("Wrong east texture", all);
	if (all->g->east)
		free(all->g->east);
	return (img);
}

t_text_img	init_sprite(t_text_img img, t_all *all)
{
	if (!(img.img = mlx_xpm_file_to_image(all->win->mlx, all->g->sprite,
	&img.width, &img.height)))
		ft_e("Wrong sprite texture", all);
	if (all->g->sprite)
		free(all->g->sprite);
	return (img);
}
