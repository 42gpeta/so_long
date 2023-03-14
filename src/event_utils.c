/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:38:54 by gpeta             #+#    #+#             */
/*   Updated: 2023/03/14 14:39:30 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../lib/libmlx/mlx.h"
#include "../lib/libmlx/mlx_int.h"

/** Ferme la fenêtre en arrêtant mlx_ptr et win_ptr issue de la structure créée */
int	ft_close_bt_esc(int key_symbol, t_vars *vars)
{
	if (key_symbol == XK_Escape)
	{
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		printf("Key press : %d (touche 'esc') ... APPUYER SUR 'Ctrl + C' !\n", key_symbol); // a supprimer
	}
	return (0);
}

int	ft_close_red_cross(t_vars *vars) // voir si on peut combiner dans ft_close_bt_esc
{
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	printf("Crose apply ... APPUYER SUR 'Ctrl + C' !\n"); // a supprimer
	return (0);
}

/** Indique le numéro du symbol appuyé */
int	ft_close_with_release(int key_symbol)
{
	printf("Key %d release\n", key_symbol);
	return (0);
}