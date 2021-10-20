/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanett <ajeanett@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 21:08:34 by ajeanett          #+#    #+#             */
/*   Updated: 2020/10/27 21:05:41 by ajeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		bmp_write_bitmapinfo(int fd, t_win *win)
{
	int				bitmapinfo_size;
	int				planes;
	int				index;

	bitmapinfo_size = 40;
	planes = 1;
	write(fd, &bitmapinfo_size, 4);
	write(fd, &win->x_win_size, 4);
	write(fd, &win->y_win_size, 4);
	write(fd, &planes, 2);
	write(fd, &win->bpp, 2);
	index = 0;
	while (index < 24)
	{
		write(fd, "\0", 1);
		index++;
	}
}

static void		bmp_write_header(int fd, t_win *win)
{
	int				file_size;
	int				start_image;

	file_size = 14 + 40 + (win->x_win_size * win->y_win_size) * 4;
	start_image = 14 + 40;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &start_image, 4);
}

static void		write_bmp(char **buffer, t_all *all)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	y = all->win->y_win_size;
	while (y--)
	{
		x = 0;
		while (x < all->win->x_win_size)
		{
			j = (x * (all->win->bpp / 8)) + (y * all->win->line_l);
			*(*buffer + i++) = *((char *)all->win->addr + j++);
			*(*buffer + i++) = *((char *)all->win->addr + j++);
			*(*buffer + i++) = *((char *)all->win->addr + j++);
			*(*buffer + i++) = *((char *)all->win->addr + j);
			x++;
		}
	}
}

int				bmp_create(int fd, t_win *win, t_all *all)
{
	int				y;
	int				size;
	char			*buffer;
	int				i;

	i = 0;
	size = all->win->y_win_size * all->win->x_win_size * 4;
	if (!(buffer = malloc((size))))
		ft_e("Not enough memory", all);
	while (i < size)
		buffer[i++] = 0;
	y = win->y_win_size;
	bmp_write_header(fd, win);
	bmp_write_bitmapinfo(fd, win);
	write_bmp(&buffer, all);
	write(fd, buffer, size);
	free(buffer);
	return (1);
}

void			export_bmp(t_all *all)
{
	int		fd;
	int		success;

	fd = open("Cub3D.bmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		ft_e("Failed to open export file: Cub3D.bmp", all);
	success = bmp_create(fd, all->win, all);
	close(fd);
	if (success)
	{
		ft_putendl_fd("Exported file: Cub3D.bmp", 1);
		exit(0);
	}
	else
		ft_e("Failed to export rendered image: Cub3D.bmp", all);
}
