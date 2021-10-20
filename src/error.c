/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanett <ajeanett@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 16:51:03 by ajeanett          #+#    #+#             */
/*   Updated: 2020/10/25 15:22:17 by ajeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_e(char *str, t_all *all)
{
	if (all->map)
		free_map(all->map);
	if (all->tmp)
		free_map(all->map);
	if (all->win->img)
		mlx_destroy_image(all->win->mlx, all->win->img);
	if (all->win->win)
		mlx_destroy_window(all->win->mlx, all->win->win);
	ft_putendl_fd(ft_strjoin("Error\n", str), 2);
	exit(1);
}

void	ft_e_nofree(char *str)
{
	ft_putendl_fd(ft_strjoin("Error\n", str), 2);
	exit(1);
}

void	ft_emalloc(char *str)
{
	free(str);
	ft_putendl_fd("Error\n Not enough memory.", 2);
	exit(1);
}
