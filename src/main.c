/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanett <ajeanett@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 11:26:49 by ajeanett          #+#    #+#             */
/*   Updated: 2020/10/26 15:05:52 by ajeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		check_name(char *argv)
{
	char	*ext;

	ext = ft_strrchr(argv, '.');
	if (ext == NULL)
		ft_e_nofree("Wrong file extension");
	if (ft_strcmp(ext, ".cub") == 0)
		return ;
	else
		ft_e_nofree("Wrong file extension");
}

void		initialize(t_plr *plr)
{
	plr->camerax = 0;
	plr->count = 0;
	plr->dirx = 0;
	plr->diry = 0;
	plr->drawend = 0;
	plr->olddirx = 0;
	plr->oldplanex = 0;
	plr->planex = 0;
	plr->planey = 0;
	plr->sp_count = 0;
	plr->x = 0;
	plr->y = 0;
	plr->spr_buffer = 0;
	plr->texpos = 0;
	plr->texture_pixel = 0;
}

void		initialize_ray(t_ray *ray)
{
	ray->deltadistx = 0;
	ray->deltadisty = 0;
	ray->hit = 0;
	ray->line = 0;
	ray->perpwalldist = 0;
	ray->raydirx = 0;
	ray->raydiry = 0;
	ray->side = 0;
	ray->sidedistx = 0;
	ray->sidedisty = 0;
	ray->stepx = 0;
	ray->stepy = 0;
}

int			start_game(char *argv, t_all *all)
{
	t_win	win;
	t_plr	plr;
	t_ray	ray;

	all->map = ft_read_map(argv);
	all->tmp = ft_read_map(argv);
	initialize(&plr);
	initialize_ray(&ray);
	ft_init_player(all->map, &plr);
	all->plr = &plr;
	all->win = &win;
	all->ray = &ray;
	all->win->mlx = mlx_init();
	ft_parse_map(all, all->map);
	textures(all);
	ft_raycasting(all);
	mlx_do_sync(win.mlx);
	mlx_hook(win.win, 2, (1L << 0), &key_press, all);
	mlx_hook(win.win, 17, (1L << 17), ft_exit, all);
	mlx_loop(win.mlx);
	return (0);
}

int			main(int argc, char **argv)
{
	t_all	all;

	all.save = 0;
	if (argc == 1)
		ft_e_nofree("I need a map");
	if (argc == 3)
		all.save = find_save(argv[2]);
	if (argc == 2 || argc == 3)
	{
		check_name(argv[1]);
		start_game(argv[1], &all);
	}
	if (argc > 3)
		ft_e_nofree("Too many arguments.");
	return (0);
}
