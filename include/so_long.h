/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:01:40 by gpeta             #+#    #+#             */
/*   Updated: 2023/03/29 16:26:42 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/**** DEFINE ****/
// # define WINDOW_WIDHT 600
// # define WINDOW_HEIGHT 300
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

/**** INCLUDE A supprimer ****/
# include <stdio.h>

/**** INCLUDE ****/
#include "X11/keysym.h"
#include "X11/X.h"
#include "mlx.h"
#include "libft.h"
#include <stdlib.h>
#include "get_next_line.h"
#include "ft_printf.h"





/**** STRUCTURE ****/

	/* map.c */
typedef struct s_generate
{
	void	*mlx_img0;
	void	*mlx_img1;
	void	*mlx_imgC;
	void	*mlx_imgE;
	void	*mlx_imgP;
	char	*string_map_ber;
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
	int		img_widht;
	int		img_height;
	int		window_widht; // ! test
	int		window_height; // ! test
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

/* Events */ /* map.c */
typedef struct s_data
{
	char	*filename;
	void	*mlx_ptr;
	void	*win_ptr;
	char	*file_xpm0;
	char	*file_xpm1;
	char	*file_xpmC;
	char	*file_xpmE;
	char	*file_xpmP;
	int		row_size;
	int		colomn_size;
	char	*string_map;
	t_img	img;
}	t_data;


/**** FUNCTIONS ****/

/* event_utils.c */

// int	ft_close_s_keypress(int key_symbol, t_data *data);
int	ft_bouton_red_cross(t_data *data);
int	ft_key_hook(int key_symbol, t_data *data);
// int	ft_key_hook(int key_symbol);
int	ft_no_event(void *data);

/* error_message.c */

void	ft_message_error(char *message);

/* pixel.c */

int	render(t_data *data);
int	render_rect(t_img *img, t_rect rect);
void	render_background(t_img *img, int color);
int	render_no_action(t_data *data);

/* pixel_utils.c */

void	img_pix_put(t_img *img, int x, int y, int color);
int	color_map_2(unsigned char *data,int bpp,int sl,int w,int h,int endian, int type);

/* map.c */

// char	*ft_map_control_extention(char *filename, char *filename_main); // ? v1
char	*ft_map_control_extention(t_data *data, char *filename_main); // ? v2

// int	ft_map_check_extention(char *filename, char *filename_main); // ? v1
int	ft_map_check_extention(t_data *data, char *filename_main); // ? v2

// char	*ft_generate_string_map(char *file_ber); // ? v1
// char	*ft_generate_string_map(char *file_ber, t_data *data); // ? v2
// char	*ft_generate_string_map(char *file_ber, t_data *data); // ? v3
char	*ft_generate_string_map(t_data *data); // ? v4

// void	ft_generate_xpm(t_data *data); // ? v1
void	ft_generate_xpm(t_data *data, t_generate *generate); // ? v2

#endif
