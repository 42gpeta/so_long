/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:38:54 by gpeta             #+#    #+#             */
/*   Updated: 2023/03/21 16:47:54 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** Ferme la fenêtre en arrêtant mlx_ptr et win_ptr issue de la structure créée */
int	ft_close_s_keypress(int key_symbol, t_data *data)
{
	if (key_symbol == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL; // fermeture de la fenêtre
		// printf("Key press : %d (touche 'esc') ... APPUYER SUR 'Ctrl + C' !\n", key_symbol); // a supprimer
	}
	return (0);
}

int	ft_bouton_red_cross(t_data *data) // voir si on peut combiner dans ft_close_bt_esc
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL; // fermeture de la fenêtre
	// printf("Crose apply ... APPUYER SUR 'Ctrl + C' !\n"); // a supprimer
	return (0);
}

/** Indique le numéro du symbol appuyé */
// int	ft_close_release(int key_symbol)
// {
// 	printf("Key %d release\n", key_symbol);
// 	return (0);
// }

int	ft_close_release(int key_symbol)
{
	// i = 0;	
	if (key_symbol == 119)
	{
		printf("Letter W | Key %d\n", key_symbol);
		// i++;
	}
	else if (key_symbol == 97)
	{
		printf("Letter A | Key %d\n", key_symbol);
		// i++;
	}
	else if (key_symbol == 115)
	{
		printf("Letter S | Key %d\n", key_symbol);
		// i++;
	}
	else if (key_symbol == 100)
	{
		printf("Letter D | Key %d\n", key_symbol);
		// i++;
	}
	else
		printf("Key %d\n", key_symbol);
	// printf("------------------\nCOMPTEUR MVT : %d\n------------------\n", i);
	return (key_symbol);
}

// int	ft_mouvement_s_keypress(int key_sumbol, t_data *data)
// {
// 	if (key_symbol == )
// }

int	ft_no_event(void *data)
{
	return (0);
}

// int	ft_keypress_mouvement()