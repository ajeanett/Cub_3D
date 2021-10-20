/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanett <ajeanett@42.ru>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 19:40:11 by ajeanett          #+#    #+#             */
/*   Updated: 2020/05/30 16:09:32 by ajeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		m;
	int		index;

	index = 0;
	m = 0;
	while (src[m] != '\0')
	{
		m = m + 1;
	}
	dest = (char*)malloc(sizeof(*src) * (m + 1));
	if (!dest)
		return (NULL);
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}
