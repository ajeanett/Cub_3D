/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanett <ajeanett@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:58:04 by ajeanett          #+#    #+#             */
/*   Updated: 2020/10/25 13:45:49 by ajeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void			ft_resolution(t_all *all, char **splitted)
{
	int i;

	i = 0;
	check_splitted_res(splitted, all);
	all->g->r_x = ft_atoi(splitted[1]);
	while ((all->g->res = 1) && splitted[1][i] != '\0')
	{
		if (!ft_isdigit(splitted[1][i]))
			ft_e("Wrong resolution", all);
		i++;
	}
	i = 0;
	all->g->r_y = ft_atoi(splitted[2]);
	while ((all->g->res = 1) && splitted[2][i] != '\0')
	{
		if (!ft_isdigit(splitted[2][i]))
			ft_e("Wrong resolution", all);
		i++;
	}
	if (all->g->r_x > MAX_DISPLAY_X || all->g->r_y > MAX_DISPLAY_Y)
		mlx_get_screen_size(all->win->mlx, &all->g->r_x, &all->g->r_y);
	if (all->g->r_x < 1 || all->g->r_y < 1)
		ft_e("Wrong resolution", all);
	if (all->g->r_x && all->g->r_y)
		all->g->res = 1;
}

static void			parser4(t_all *all, char *line)
{
	if (ft_strncmp(line, "R", 1) == 0 && all->g->res == 1)
		ft_e("Wrong resolution", all);
	else if (ft_strncmp(line, "NO", 2) == 0 && all->g->north)
		ft_e("Wrong north tex", all);
	else if (ft_strncmp(line, "SO", 2) == 0 && all->g->south)
		ft_e("Wrong south tex", all);
	else if (ft_strncmp(line, "WE", 2) == 0 && all->g->west)
		ft_e("Wrong west tex", all);
	else if (ft_strncmp(line, "EA", 2) == 0 && all->g->east)
		ft_e("Wrong east tex", all);
	else if (ft_strncmp(line, "S", 1) == 0 && *(line + 1)
			!= 'O' && !all->g->sprite)
		ft_e("Wrong sprite tex", all);
	else if (ft_strncmp(line, "F", 1) == 0 && all->g->floor)
		ft_e("Wrong floor", all);
	else if (ft_strncmp(line, "C", 1) == 0 && all->g->ceiling)
		ft_e("Wrong ceiling", all);
}

static void			parser3(t_all *all, char *line, char **splitted)
{
	char	*path;

	path = get_value(line);
	if (ft_strncmp(line, "R", 1) == 0 && all->g->res == 0)
		ft_resolution(all, splitted);
	else if (ft_strncmp(line, "NO", 2) == 0 && !all->g->north)
		all->g->north = ft_strdup(path);
	else if (ft_strncmp(line, "SO", 2) == 0 && !all->g->south)
		all->g->south = ft_strdup(path);
	else if (ft_strncmp(line, "WE", 2) == 0 && !all->g->west)
		all->g->west = ft_strdup(path);
	else if (ft_strncmp(line, "EA", 2) == 0 && !all->g->east)
		all->g->east = ft_strdup(path);
	else if (ft_strncmp(line, "S", 1) == 0 && *(line + 1)
			!= 'O' && !all->g->sprite)
		all->g->sprite = ft_strdup(path);
	else if (ft_strncmp(line, "F", 1) == 0 && !all->g->floor)
		all->g->floor = ft_strdup(path);
	else if (ft_strncmp(line, "C", 1) == 0 && !all->g->ceiling)
		all->g->ceiling = ft_strdup(path);
	else
		parser4(all, line);
}

int					parser2(t_all *all, char *line)
{
	char	**splitted;

	if (!(splitted = ft_split(line, ' ')))
	{
		ft_clear_splitted(splitted);
		ft_e("Invalid map", all);
	}
	parser3(all, line, splitted);
	ft_clear_splitted(splitted);
	return (0);
}

void				ft_parse_map(t_all *all, char **map)
{
	t_point	pos;
	t_g		g;

	if (!(all->plr->spr = malloc(sizeof(t_spr) * (all->plr->spr_buffer + 1))))
		ft_e("Not enough memory", all);
	ft_bzero(&pos, sizeof(t_point));
	ft_bzero(&g, sizeof(t_g));
	all->g = &g;
	all->plr->sp_count = 0;
	while (map[pos.y])
	{
		pos.x = 0;
		count_sprites(all, map[pos.y], pos.y, map);
		parser2(all, map[pos.y]);
		pos.y++;
	}
	color_ceiling(all);
	color_floor(all);
	check_map(all, all->tmp);
	make_new_window(all);
}
