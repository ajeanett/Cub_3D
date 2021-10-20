/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_save.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanett <ajeanett@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:24:13 by ajeanett          #+#    #+#             */
/*   Updated: 2020/10/25 13:44:58 by ajeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if ((unsigned char)s1[i] != (unsigned char)s2[i])
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

int		find_save(char *str)
{
	int		save_found;

	save_found = 0;
	if (ft_strcmp(str, "--save") == 0)
	{
		save_found = 1;
	}
	else
		ft_e_nofree(ft_strjoin("Wrong argument: ", str));
	return (save_found);
}
