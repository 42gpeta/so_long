/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:01:40 by gpeta             #+#    #+#             */
/*   Updated: 2023/03/10 17:13:09 by gpeta            ###   ########.fr       */
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




/**** STRUCTURE ****/

/* Events */
typedef struct s_vars
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_vars;


/**** FUNCTIONS ****/

int	ft_close(int key_symbol, t_vars *vars);
int	ft_close2(int key_symbol, void *vars);


#endif
