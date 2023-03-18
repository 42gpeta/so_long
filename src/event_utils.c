/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:38:54 by gpeta             #+#    #+#             */
/*   Updated: 2023/03/17 16:06:33 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** Ferme la fenêtre en arrêtant mlx_ptr et win_ptr issue de la structure créée */
int	ft_close_keypress(int key_symbol, t_data *data)
{
	if (key_symbol == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL; // fermeture de la fenêtre
		// printf("Key press : %d (touche 'esc') ... APPUYER SUR 'Ctrl + C' !\n", key_symbol); // a supprimer
	}
	return (0);
}

int	ft_close_red_cross(t_data *data) // voir si on peut combiner dans ft_close_bt_esc
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL; // fermeture de la fenêtre
	// printf("Crose apply ... APPUYER SUR 'Ctrl + C' !\n"); // a supprimer
	return (0);
}

/** Indique le numéro du symbol appuyé */
int	ft_close_release(int key_symbol)
{
	printf("Key %d release\n", key_symbol);
	return (0);
}

int	ft_no_event(void *data)
{
	return (0);
}