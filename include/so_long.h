/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:01:40 by gpeta             #+#    #+#             */
/*   Updated: 2023/03/14 18:14:12 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/**** DEFINE ****/
# define WINDOW_WIDHT 500
# define WINDOW_HEIGHT 500

// x = widht = largeur
// y = height = hauteur

/**** INCLUDE A supprimer ****/
# include <stdio.h>

/**** INCLUDE ****/
#include "X11/keysym.h"
#include "X11/X.h"
#include "mlx.h"
#include "libft.h"
#include <stdlib.h>





/**** STRUCTURE ****/

/* Events */
typedef struct s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_vars;

/* Image/Pixel */
typedef struct s_data
{
	void	*img;
}	t_data;

/**** FUNCTIONS ****/

/* event_utils.c */

// void	ft_close_bt_esc(int key_symbol, t_vars *vars);
int	ft_close_keypress(int key_symbol, t_vars *vars);
int	ft_close_release(int key_symbol);
int	ft_close_red_cross(t_vars *vars);
int	ft_no_event(void *vars);

/* error_message.c */

void	ft_message_error_mlx_init(char *message);



#endif
