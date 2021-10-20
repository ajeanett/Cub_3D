/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanett <ajeanett@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:58:04 by ajeanett          #+#    #+#             */
/*   Updated: 2020/10/26 12:28:14 by ajeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char			*get_value(char *line)
{
	while (*line && !(*line == '\f' || *line == '\t' || *line == ' ' ||
					*line == '\n' || *line == '\r' || *line == '\v'))
		line++;
	while (*line && (*line == '\f' || *line == '\t' || *line == ' ' ||
					*line == '\n' || *line == '\r' || *line == '\v'))
		line++;
	return (line);
}

void			set_sprite(t_all *all, int x, int y, int i)
{
	all->plr->spr[i - 1].x = x + 0.5;
	all->plr->spr[i - 1].y = y + 0.5;
}

void			count_sprites(t_all *all, char *line, int y, char **map)
{
	int	x;

	x = 0;
	while (line[x] != '\0')
	{
		if (all->g->res && all->g->north && all->g->south && all->g->west
			&& all->g->east && all->g->sprite && all->g->floor
			&& all->g->ceiling)
			if ((line[x] == '2') && (((line[x + 1]) == '0')
				|| ((line[x + 1]) == '1') || ((line[x + 1]) == '2')))
			{
				if (!(map[y + 1]))
					ft_e("Sprite corrupted", all);
				all->plr->sp_count++;
				set_sprite(all, x, y, all->plr->sp_count);
			}
		x++;
	}
}

static void		floodfill(char **map, int x, int y, t_all *all)
{
	if ((map[y][x] != '0') && (map[y][x] != '1') \
		&& (map[y][x] != '2') && (map[y][x] != 'W') && (map[y][x] != 'N') \
		&& (map[y][x] != 'S') && (map[y][x] != 'E') && (map[y][x] != '#'))
	{
		y = 0;
		ft_e("map corrupted\n", all);
	}
	if ((map[y][x] == '1') || (map[y][x] == '#'))
		return ;
	if ((map[y][x] == '0') || (map[y][x] == '2')
		|| (map[y][x] == 'N') || (map[y][x] == 'S')
		|| (map[y][x] == 'W') || (map[y][x] == 'E'))
	{
		map[y][x] = '#';
		floodfill(map, x + 1, y, all);
		floodfill(map, x, y + 1, all);
		floodfill(map, x - 1, y, all);
		floodfill(map, x, y - 1, all);
	}
}

void			check_map(t_all *all, char **tmp)
{
	int		x;
	int		y;

	x = (int)all->plr->x;
	y = (int)all->plr->y;
	check_param(all);
	if (!(tmp[y + 1]))
		ft_e("Wrong player. SEG FAULT! No. It`s a joke^_^", all);
	map_verification(tmp, all);
	floodfill(tmp, x + 1, y, all);
	y = 0;
	if (tmp)
		free_map(tmp);
}
