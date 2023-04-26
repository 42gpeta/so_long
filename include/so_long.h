/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:01:40 by gpeta             #+#    #+#             */
/*   Updated: 2023/04/26 17:22:51 by gpeta            ###   ########.fr       */
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
#include "ft_printf.h"



/* ************************************************************************** */
/*							      	 STRUCTURE							      */
/* ************************************************************************** */

typedef struct s_player
{
	int	pos_y;
	int	pos_x;
	int	pos_exit_y; // ! utile ?
	int	pos_exit_x; // ! utile ?
	// static int	mouvement;
	int	mouvement;
}	t_player;



	/* map_utils.c */ /* map_check.c */
typedef struct s_map
{
	char	*up; // ! utile ?
	char	*down; // ! utile ?
	char	*left; // ! utile ?
	char	*right; // ! utile ?
}	t_map;


typedef struct s_generate
{
	int			fd;
	void		*mlx_img0;
	void		*mlx_img1;
	void		*mlx_imgC;
	void		*mlx_imgE;
	void		*mlx_imgP;
	char		*string_map_ber; 
	char		**string_map_ber_tab;
	char		**string_map_pathfinding;
	int			number_of_C;
	int			number_of_C_pathfinding;
	t_map		map;
	t_player	player;
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
	int		win_widht; // ! test
	int		win_height; // ! test
}	t_img;

	/* pixel_tils.c */
typedef struct s_rect
{
	int		x;
	int		y;
	int		width;
	int		height;
	int		color;
}	t_rect;

/* Events */ /* map_utils.c */
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
	char		*string_map; // colecte la map dans 1 ligne
	t_img		img;
	t_generate	generate;
}	t_data;


/* ************************************************************************** */
/*							      	 FUNCTIONS							      */
/* ************************************************************************** */

/*************
event_utils.c
*************/

// int	ft_close_s_keypress(int key_symbol, t_data *data);
int	ft_bouton_red_cross(t_data *data);
// int	ft_key_hook(int key_symbol); // ? v1
// int	ft_key_hook(int key_symbol, t_data *data); // ? v2
// int	ft_key_hook(int key_symbol, t_data *data, t_generate *generate); // ? v3
int	ft_key_hook(int key_symbol, t_data *data); // ? v4
int	ft_no_event(void *data);

/*************
error_message.c
*************/

// void	ft_message_error(char *message); // ? v1
// void	ft_message_error(char *message, t_data *data, t_generate *generate); // ? v2
// void	ft_message_error(char *message, t_data *data, t_generate *generate); // ? v3
// void	ft_message_error(char *message, t_data *data, t_generate *generate); // ? v4
void	ft_message_error(char *message, t_data *data); // ? v5


/*************
pixel.c
*************/

int	render(t_data *data);
int	render_rect(t_img *img, t_rect rect);
void	render_background(t_img *img, int color);
// int	render_no_action(t_data *data); // ? v1
// int	render_no_action(t_data *data, t_generate *generate); // ? v1
int	render_no_action(t_data *data); // ? v2

/*************
pixel_utils.c
*************/

void	img_pix_put(t_img *img, int x, int y, int color);
int	color_map_2(unsigned char *data,int bpp,int sl,int w,int h,int endian, int type);

/*************
map_utils.c
*************/

// char	*ft_map_control_extention(char *filename, char *filename_main); // ? v1
// char	*ft_map_control_extention(t_data *data, char *filename_main); // ? v2
void	ft_map_control_extention(t_data *data, char *filename_main); // ? v3

// int	ft_map_check_extention(char *filename, char *filename_main); // ? v1
// int	ft_map_check_extention(t_data *data, char *filename_main); // ? v2
void	ft_map_check_extention(t_data *data, char *filename_main); // ? v3

// char	*ft_generate_string_map(char *file_ber); // ? v1
// char	*ft_generate_string_map(char *file_ber, t_data *data); // ? v2
// char	*ft_generate_string_map(char *file_ber, t_data *data); // ? v3
// void	ft_generate_string_map(t_data *data, t_generate *generate); // ? v4
void	ft_generate_string_map(t_data *data); // ? v5

void	ft_check_string_map(t_data *data);

// void	ft_generate_string_map_tab(t_data *data, t_generate *generate); // ? v1
void	ft_generate_string_map_tab(t_data *data); // ? v2


// void	ft_generate_path_file(t_data *data, t_generate *generate); // ? v1
void	ft_generate_path_file(t_data *data); // ? v2

// void	ft_generate_xpm(t_data *data); // ? v1
// void	ft_generate_xpm(t_data *data, t_generate *generate); // ? v2
void	ft_generate_xpm(t_data *data); // ? v3


/*************
map_check.c
*************/

// void	ft_check_content(t_generate *generate, t_data *data); // ? v1
void	ft_check_content(t_data *data); // ? v2

void	ft_letter_presence(t_data *data, int letter_E, int letter_C, int letter_P); // ! non utilisée

// void	ft_check_map_is_an_rectangle(t_data *data, t_generate *s_generate); // ? v1
void	ft_check_map_is_an_rectangle(t_data *data); // ? v2


// void	ft_check_surrounded_by_one(t_generate *generate, t_data *data); // ? v1
void	ft_check_surrounded_by_one(t_data *data); // ? v4

void	ft_parsing(t_data *data, int letter);


void	ft_check_possible_exit();


/*************
map_check_paraneters.c
*************/
// void	ft_check_surrounded_by_one_up(t_generate *generate, t_data *data); // ? v1
void	ft_check_surrounded_by_one_up(t_data *data); // ? v2

// void	ft_check_surrounded_by_one_down(t_generate *generate, t_data *data); // ? v1
void	ft_check_surrounded_by_one_down(t_data *data); // ? v2

// void	ft_check_surrounded_by_one_left(t_generate *generate, t_data *data); // ? v1
void	ft_check_surrounded_by_one_left(t_data *data); // ? v2

// void	ft_check_surrounded_by_one_right(t_generate *generate, t_data *data); // ? v1
void	ft_check_surrounded_by_one_right(t_data *data); // ? v2


/*************
move.c
*************/

// void	ft_move_up(t_data *data, t_generate *generate); // ? v1
void	ft_move_up(t_data *data); // ? v2
// void	ft_move_down(t_data *data, t_generate *generate); // ? v1
void	ft_move_down(t_data *data); // ? v2
// void	ft_move_left(t_data *data, t_generate *generate); // ? v1
void	ft_move_left(t_data *data); // ? v2
// void	ft_move_right(t_data *data, t_generate *generate); // ? v1
void	ft_move_right(t_data *data); // ? v2
// void    ft_move_exit(t_data *data); // ! non utilisé v1
void    ft_move_exit(t_data *data, int move); // ? v2

/*************
pathfinding.c
*************/

void    ft_flood_fill(t_data *data);
void    ft_pathfinding_flood(t_data *data, int y, int x);
void    ft_pathfinding_flood_y(t_data *data, int y, int x);
void    ft_pathfinding_flood_x(t_data *data, int y, int x);
void    ft_pathfinding_check(t_data *data);


#endif
