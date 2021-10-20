/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeanett <ajeanett@21-school.ru>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 17:31:53 by ajeanett          #+#    #+#             */
/*   Updated: 2020/10/26 14:00:33 by ajeanett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "../minilibx_mms/mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"
# include <fcntl.h>

# define MOVE_SPEED 0.1
# define ROT_SPEED 0.1
# define MAX_DISPLAY_X 2560
# define MAX_DISPLAY_Y 1440
# define MIN_DISPLAY_X 50
# define MIN_DISPLAY_Y 50
# define INVISIBLE_COLOR 0x980088

typedef struct	s_text_img
{
	int			width;
	int			height;
	int			bpp;
	int			line_l;
	int			en;
	void		*img;
	char		*addr;
}				t_text_img;

typedef	struct	s_spr
{
	double		x;
	double		y;
	int			texture;
	double		spritedist;
	double		sprx;
	double		spry;
	double		invdet;
	double		transformx;
	double		transformy;
	int			sprscrx;
	int			sprh;
	int			drawstarty;
	int			drawendy;
	int			sprw;
	int			drawstartx;
	int			drawendx;
	int			stripe;
	int			texx;
	int			d;
	int			texy;
	int			spr_pixel;
}				t_spr;

typedef struct	s_win
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*addr;
	int			line_l;
	int			bpp;
	int			en;
	int			x_win_size;
	int			y_win_size;
	t_text_img	north_tx;
	t_text_img	south_tx;
	t_text_img	east_tx;
	t_text_img	west_tx;
	t_text_img	sprite_tx;
	t_text_img	current;
	int			floor_clr;
	int			ceiling_clr;
}				t_win;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_plr
{
	double		x;
	double		y;
	double		dirx;
	double		olddirx;
	double		diry;
	double		planex;
	double		oldplanex;
	double		planey;
	double		camerax;
	int			sp_count;
	int			spr_buffer;
	double		*zbuffer;
	int			*spr_order;
	t_spr		*spr;
	int			drawstart;
	int			drawend;
	int			count;
	double		texpos;
	int			texture_pixel;
}				t_plr;

typedef struct	s_ray
{
	double		deltadistx;
	double		deltadisty;
	double		sidedistx;
	double		sidedisty;
	double		perpwalldist;
	double		raydirx;
	double		raydiry;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			line;
}				t_ray;

typedef struct	s_g
{
	char		*east;
	char		*west;
	char		*north;
	char		*south;
	char		*sprite;
	char		*ceiling;
	char		*floor;
	int			res;
	int			r_x;
	int			r_y;
}				t_g;

typedef struct	s_all
{
	t_win		*win;
	t_plr		*plr;
	t_ray		*ray;
	char		**map;
	char		**tmp;
	t_g			*g;
	int			save;
}				t_all;

void			ft_raycasting(t_all *all);
int				key_press(int key, t_all *all);
void			turn_right(t_all *all);
void			turn_left(t_all *all);
void			my_mlx_pixel_put(t_win *win, int x, int y, int color);
void			ft_parse_map(t_all *all, char **map);
void			textures(t_all *all);
t_text_img		init_north(t_text_img img, t_all *all);
t_text_img		init_south(t_text_img img, t_all *all);
t_text_img		init_west(t_text_img img, t_all *all);
t_text_img		init_east(t_text_img img, t_all *all);
t_text_img		init_sprite(t_text_img img, t_all *all);
void			ft_draw_text(t_all *all, int drawstart, int drawend, int x);
void			ft_draw_sky(t_all *all, int drawstart, int drawend, int x);
char			**ft_clear_splitted(char **str);
void			color_ceiling(t_all *all);
void			color_floor(t_all *all);
char			**ft_split_str(char const *s, const char *delimiters);
void			check_splitted_res(char **splitted, t_all *all);
void			ft_sprite(t_all *all);
void			calc_sprite(t_all *all);
int				get_pixel(t_text_img *img, int x, int y);
void			my_mlx_pixel_put(t_win *win, int x, int y, int color);
void			ft_e(char *str, t_all *all);
void			ft_e_nofree(char *str);
int				find_save(char *str);
void			export_bmp(t_all *all);
int				ft_strcmp(const char *s1, const char *s2);
void			check_param(t_all *all);
void			map_verification(char **map, t_all *all);
void			ft_init_player(char **map, t_plr *plr);
void			free_map(char **tmp);
void			make_new_window(t_all *all);
char			*get_value(char *line);
void			count_sprites(t_all *all, char *line, int y, char **map);
void			check_map(t_all *all, char **tmp);
void			make_new_window(t_all *all);
int				ft_exit();
char			**ft_read_map(char *av1);
char			**ft_make_map(t_list **head, int amount);
void			ft_escape(t_all *all);
int				ft_search(char *str);
int				ft_check_digit(char *str);
void			check_walls(char **map, int y, int x, t_all *all);
void			check_raycasting(t_all *all, t_point map);

#endif
