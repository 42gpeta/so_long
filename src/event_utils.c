/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:38:54 by gpeta             #+#    #+#             */
/*   Updated: 2023/03/14 13:44:20 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../lib/libmlx/mlx.h"
#include "../lib/libmlx/mlx_int.h"

/** Ferme la fenêtre en arrêtant mlx_ptr et win_ptr issue de la structure créée */
int	ft_close(int key_symbol, t_vars *vars)
{
	if (key_symbol == XK_Escape)
	{
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		printf("Key press : %d (touche 'esc') ... APPUYER SUR 'Ctrl + C' !\n", key_symbol); // a supprimer
	}
	return (0);
}

int	ft_close3(t_vars *vars)
{
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	printf("Crose apply ... APPUYER SUR 'Ctrl + C' !\n"); // a supprimer
	return (0);
}

/** Indique le numéro du symbol appuyé */
int	ft_close2(int key_symbol, void *vars)
{
	printf("Key %d release\n", key_symbol);
	return (0);
}