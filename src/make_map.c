/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanett <ajeanett@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 21:25:30 by ajeanett          #+#    #+#             */
/*   Updated: 2020/10/25 13:45:37 by ajeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		**ft_make_map(t_list **head, int amount)
{
	t_list		*tmp;
	char		**map;
	int			i;

	i = 0;
	tmp = *head;
	map = ft_calloc(amount + 1, sizeof(char *));
	if (!map)
		ft_e_nofree("Not enough memory for map");
	while (tmp)
	{
		map[i] = ft_strdup(tmp->content);
		i++;
		tmp = tmp->next;
	}
	i = 0;
	ft_lstclear(head, &free);
	return (map);
}

char		**ft_read_map(char *av1)
{
	char		*str;
	t_list		*head;
	int			amount;
	const int	fd = open(av1, O_RDONLY);

	str = NULL;
	head = NULL;
	amount = 0;
	if (fd < 0)
		ft_e_nofree("Invalid file");
	while (get_next_line(fd, &str) > 0)
	{
		ft_lstadd_back(&head, ft_lstnew(str));
		amount++;
		str = NULL;
	}
	close(fd);
	ft_lstadd_back(&head, ft_lstnew(str));
	amount++;
	return (ft_make_map(&head, amount));
}
