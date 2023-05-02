/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:01:40 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/02 20:32:18 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ************************************************************************** */
/*							      	 DEFINE							      */
/* ************************************************************************** */

# define WINDOW_WIDHT 600
# define WINDOW_HEIGHT 300
# define ECART_XPM 65
# define WINDOW_WIDHT_MAX 2560	// (X ; largeur)
# define WINDOW_HEIGHT_MAX 1440 // (Y ; longeur)

/*
1920 x 1080 :
- 1920 pixel in each row (largeur)
- 1080 rows (hauteur)

x = widht = largeur
y = height = hauteur

*/

/* COLORS */
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define BLUE_PIXEL 0x0000FF
# define WHITE_PIXEL 0xFFFFFF
// Format : 0xTTRRGGBB
// R = red ; G = green ; B = blue ; T = transparency 

/**** INCLUDE A supprimer ****/ // ! a supprimer
# include <stdio.h>

/* ************************************************************************** */
/*							      	 INCLUDE							      */
/* ************************************************************************** */

# include "X11/keysym.h"
# include "X11/X.h"
# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include "get_next_line.h"

/* ************************************************************************** */
/*							      	 STRUCTURE							      */
/* ************************************************************************** */

typedef struct s_player
{
	int		y;
	int		x;
	int		nb_move;
	char	*move;
}	t_player;

typedef struct s_exit
{
	int	y;
	int	x;
}	t_exit;

typedef struct s_generate
{
	int			fd;
	void		*mlx_img0;
	void		*mlx_img1;
	void		*mlx_imgc;
	void		*mlx_imge;
	void		*mlx_imgp;
	char		**str_tab;
	char		**str_map_pathfinding;
	int			number_of_c;
	int			number_of_c_pathfinding;
	t_player	man;
	t_exit		exit;
}	t_generate;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	char	*relative_path;
	int		w;
	int		h;
}	t_img;

typedef struct s_data
{
	char		*filename;
	int			ac;
	void		*mlx_p;
	void		*win_p;
	char		*path_xpm0;
	char		*path_xpm1;
	char		*path_xpmc;
	char		*path_xpme;
	char		*path_xpmp;
	int			row_size_map;
	int			colomn_size_map;
	int			row_size_win;
	int			colomn_size_win;
	char		*str_map;
	t_img		img;
	t_generate	gen;
}	t_data;

/* ************************************************************************** */
/*							      	 FUNCTIONS							      */
/* ************************************************************************** */

/*************
control_string_map.c
*************/

void	ft_map_control_extention(t_data *data, char *filename_main, int ac);
void	ft_map_check_extention(t_data *data);

/*************
error_message.c
*************/

void	ft_message_error(char *message, t_data *data);
void	ft_destroy(t_data *data);

/*************
event.c
*************/

int		render(t_data *data);
int		ft_bouton_red_cross(t_data *data);
int		ft_key_hook(int key_symbol, t_data *data);
void	ft_escape_key(t_data *data);
void	ft_print_informations(t_data *data);

/*************
main.c // ! a supprimer
*************/

void	print_map(t_data *data);
void	player_position(t_data *data);
void	print_map_pathfinding(t_data *data, char *name);
void	print_nb_of_c_pathfinding(t_data *data, char *time, int i);

/*************
map_check_paraneters.c
*************/
void	ft_check_surrounded_by_one_top(t_data *data);
void	ft_check_surrounded_by_one_bottom(t_data *data);
void	ft_check_surrounded_by_one_left(t_data *data);
void	ft_check_surrounded_by_one_right(t_data *data);

/*************
map_check.c
*************/

void	ft_nb_presence(t_data *data, int nb_e, int nb_c, int nb_p);
void	ft_check_content(t_data *data);
void	ft_check_map_is_an_rectangle(t_data *data);
void	ft_check_surrounded_by_one(t_data *data); // ? v4
void	ft_parsing(t_data *data);

/*************
move_parameters.c
*************/

void	ft_move_man_up(t_data *data, int y, int x, char letter);
void	ft_move_man_down(t_data *data, int y, int x, char letter);
void	ft_move_man_left(t_data *data, int y, int x, char letter);
void	ft_move_man_right(t_data *data, int y, int x, char letter);

/*************
move.c
*************/

void	ft_move_up(t_data *data);
void	ft_move_down(t_data *data);
void	ft_move_left(t_data *data);
void	ft_move_right(t_data *data);
void	ft_move_exit(t_data *data);

/*************
pathfinding_utils.c
*************/

void	ft_is_collectible1(t_data *data, int y, int x);
void	ft_is_collectible2(t_data *data, int y, int x);

/*************
pathfinding.c
*************/

void	ft_pathfinding_move(t_data *data, int y, int x);
void	ft_pathfinding_flood(t_data *data, int y, int x);
void	ft_pathfinding_check(t_data *data);

/*************
so_long.c
*************/

void	ft_init(t_data *data);
void	ft_start(t_data *data, char *argv, int ac);
void	ft_mlx(t_data *data);
void	ft_stop(t_data *data);

/*************
string_map.c
*************/

void	ft_check_string_map(t_data *data);
void	ft_generate_string_map_tab(t_data *data);
void	ft_generate_string_map(t_data *data);

/*************
xpm.c
*************/
void	ft_xpm_to_img(t_data *data);
void	ft_put_img(t_data *data, char *img, int w, int h);
void	ft_img_configuration(t_data *data, int y, int x);
void	ft_display_xpm(t_data *data);

#endif
