/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:01:40 by gpeta             #+#    #+#             */
/*   Updated: 2023/03/22 15:58:10 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/**** DEFINE ****/
// # define WINDOW_WIDHT 600
// # define WINDOW_HEIGHT 300
# define WINDOW_WIDHT 600	// (X ; largeur)
# define WINDOW_HEIGHT 300 // (Y ; longeur)

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





/**** STRUCTURE ****/

/* Image/Pixel (42 doc) */ // non retenu
// typedef struct s_data
// {
// 	void	*img;
// }	t_data;

/* Image/Pixel (aurelienbrabant) */

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

/* Events */
typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	// void	*img_reading;
	t_img	img;
	
}	t_data;


/**** FUNCTIONS ****/

/* event_utils.c */

// void	ft_close_bt_esc(int key_symbol, t_vars *data);
int	ft_close_s_keypress(int key_symbol, t_data *data);
int	ft_close_release(int key_symbol);
// int	ft_close_release(int key_symbol, int i);
int	ft_bouton_red_cross(t_data *data);
int	ft_no_event(void *data);

/* error_message.c */

void	ft_message_error_mlx_init(char *message);

/* pixel.c */

int	render(t_data *data);
int	render_rect(t_img *img, t_rect rect);
void	render_background(t_img *img, int color);
int	render_no_action(t_data *data);

/* pixel_utils.c */

void	img_pix_put(t_img *img, int x, int y, int color);
int	color_map_2(unsigned char *data,int bpp,int sl,int w,int h,int endian, int type);

/* map.c */

char	*ft_map_control_extention(char *filename, char *filename_main);
int	ft_map_check_extention(char *filename, char *filename_main);

#endif
