/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:01:40 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/01 18:22:47 by gpeta            ###   ########.fr       */
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
#define RED_PIXEL 0xFF0000
#define GREEN_PIXEL 0xFF00
#define BLUE_PIXEL 0x0000FF
#define WHITE_PIXEL 0xFFFFFF
// Format : 0xTTRRGGBB
// R = red ; G = green ; B = blue ; T = transparency 

/**** INCLUDE A supprimer ****/ // ! a supprimer
# include <stdio.h>

/* ************************************************************************** */
/*							      	 INCLUDE							      */
/* ************************************************************************** */

#include "X11/keysym.h"
#include "X11/X.h"
#include "mlx.h"
#include "libft.h"
#include <stdlib.h>
#include "get_next_line.h"
// #include "ft_printf.h"



/* ************************************************************************** */
/*							      	 STRUCTURE							      */
/* ************************************************************************** */

typedef struct s_player
{
	int		y;
	int		x;
	int		pos_exit_y;
	int		pos_exit_x;
	int		nb_move;
	char	*move;
}	t_player;

typedef struct s_exit // ! non uilisée
{
	int	y;
	int	x;
}	t_exit;

typedef struct s_generate
{
	int			fd;
	void		*mlx_img0;
	void		*mlx_img1;
	void		*mlx_imgC;
	void		*mlx_imgE;
	void		*mlx_imgP;
	char		**str_tab; // str_map_ber_tab
	char		**str_map_pathfinding;
	int			number_of_C;
	int			number_of_C_pathfinding;
	t_player	man;
	t_exit		exit;
}	t_generate;


	/* pixel.c */
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	char	*relative_path;
	int		widht;
	int		height;
}	t_img;


/* Events */ /* str_map.c */
typedef struct s_data
{
	char		*filename;
	void		*mlx_ptr;
	void		*win_ptr;
	char		*path_xpm0;
	char		*path_xpm1;
	char		*path_xpmC;
	char		*path_xpmE;
	char		*path_xpmP;
	int			row_size_map;
	int			colomn_size_map;
	int			row_size_win;
	int			colomn_size_win;
	int			offset_y;
	int			offset_x;
	char		*str_map; // colecte la map dans 1 ligne
	t_img		img;
	t_generate	gen;
}	t_data;


/* ************************************************************************** */
/*							      	 FUNCTIONS							      */
/* ************************************************************************** */

/*************
event.c
*************/

int		ft_bouton_red_cross(t_data *data);
int		ft_key_hook(int key_symbol, t_data *data);
void	ft_escape_key(t_data *data);
int		render_no_action(t_data *data); // ? v2
void	ft_print_informations(t_data *data);

/*************
error_message.c
*************/

void	ft_message_error(char *message, t_data *data);


/*************
pixel.c
*************/

int	render(t_data *data);
// int	render_rect(t_img *img, t_rect rect);
void	render_background(t_img *img, int color);

/*************
pixel_utils.c
*************/

void	img_pix_put(t_img *img, int x, int y, int color);
int	color_map_2(unsigned char *data,int bpp,int sl,int w,int h,int endian, int type);

/*************
str_map.c
*************/

void	ft_generate_string_map(t_data *data); // ? v5
void	ft_check_string_map(t_data *data);
void	ft_generate_string_map_tab(t_data *data); // ? v2
void	ft_generate_path_file(t_data *data); // ? v2
void	ft_generate_xpm(t_data *data); // ? v3

/*************
control_string_map.c
*************/

void	ft_map_control_extention(t_data *data, char *filename_main); // ? v3
void	ft_map_check_extention(t_data *data, char *filename_main); // ? v3




/*************
map_check.c
*************/

void	ft_check_content(t_data *data); // ? v2
void	ft_nb_presence(t_data *data, int nb_e, int nb_c, int nb_p);
void	ft_check_map_is_an_rectangle(t_data *data); // ? v2
void	ft_check_surrounded_by_one(t_data *data); // ? v4


void	ft_check_possible_exit();


/*************
map_check_paraneters.c
*************/
void	ft_check_surrounded_by_one_up(t_data *data); // ? v2
void	ft_check_surrounded_by_one_bottom(t_data *data); // ? v2
void	ft_check_surrounded_by_one_left(t_data *data); // ? v2
void	ft_check_surrounded_by_one_right(t_data *data); // ? v2


/*************
move.c
*************/

void	ft_move_up(t_data *data); // ? v2
void	ft_move_down(t_data *data); // ? v2
void	ft_move_left(t_data *data); // ? v2
void	ft_move_right(t_data *data); // ? v2
// void	ft_move_man(t_data *data, int y, int x, char letter);
void    ft_move_exit(t_data *data);

/*************
move_parameters.c
*************/

void	ft_move_man_up(t_data *data, int y, int x, char letter);
void	ft_move_man_down(t_data *data, int y, int x, char letter);
void	ft_move_man_left(t_data *data, int y, int x, char letter);
void	ft_move_man_right(t_data *data, int y, int x, char letter);

/*************
pathfinding.c
*************/

void	ft_parsing(t_data *data, int letter);
void    ft_pathfinding_flood(t_data *data, int y, int x);
void    ft_pathfinding_check(t_data *data);
void    ft_is_collectible1(t_data *data, int y, int x);
void    ft_is_collectible2(t_data *data, int y, int x);

/*************
so_long.c
*************/

void	ft_init(t_data *data);
void	ft_start(t_data *data, char *argv);
void	ft_mlx(t_data *data);
void	ft_stop(t_data *data);
void	ft_put_img_to_win(t_data *data, int y, int x);
void	ft_put_img(t_data *data, char *img, int w, int h);





void print_map_pathfinding(t_data * data, char *name); // ! a supprimer
void print_map(t_data * data); // ! a supprimer
void player_position(t_data *data); // ! a supprimer
void number_of_C_pathfinding(t_data *data, char *time, int i); // ! a supprimer

#endif
