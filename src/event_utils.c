/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:38:54 by gpeta             #+#    #+#             */
/*   Updated: 2023/04/11 13:09:04 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	ft_close_s_keypress(int key_symbol, t_data *data) // implémenter dans ft_key_hook
// {
// 	if (key_symbol == XK_Escape)
// 	{
// 		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
// 		data->win_ptr = NULL; // fermeture de la fenêtre
// 		// printf("Key press : %d (touche 'esc') ... APPUYER SUR 'Ctrl + C' !\n", key_symbol); // ! a supprimer
// 	}
// 	return (0);
// }

/** Ferme la fenêtre en arrêtant mlx_ptr et win_ptr issue de la structure créée */
int	ft_bouton_red_cross(t_data *data) // voir si on peut combiner dans ft_close_bt_esc
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL; // fermeture de la fenêtre
	// printf("Crose apply ... APPUYER SUR 'Ctrl + C' !\n"); // ! a supprimer
	return (0);
}

/** Indique le numéro du symbol appuyé */
// int	ft_key_hook(int key_symbol)
// {
// 	printf("Key %d release\n", key_symbol);
// 	return (0);
// }

/** Indique le numéro du symbol appuyé + gère les mouvements */
int	ft_key_hook(int key_symbol, t_data *data, t_generate *generate) // ? v3
{
	static long long int i = 0;	

	// if (key_symbol == XK_Escape)
	if (key_symbol == 65307)
	{
		printf("Letter ESC | Key %d\n", key_symbol);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL; // fermeture de la fenêtre
	}
	else if (key_symbol == XK_w)
	{
		// TODO ajouter les fonctions lié aux déplacements
		printf("Letter W | Key %d\n", key_symbol);
		ft_move_up(data, generate);

		i++;
	}
	else if (key_symbol == XK_a)
	{
		// TODO ajouter les fonctions lié aux déplacements
		printf("Letter A | Key %d\n", key_symbol);
		ft_move_left(data, generate);
		i++;
	}
	else if (key_symbol == XK_s)
	{
		// TODO ajouter les fonctions lié aux déplacements
		printf("Letter S | Key %d\n", key_symbol);
		ft_move_down(data, generate);
		i++;
	}
	else if (key_symbol == XK_d)
	{
		// TODO ajouter les fonctions lié aux déplacements
		printf("Letter D | Key %d\n", key_symbol);
		ft_move_right(data, generate);
		i++;
	}
	else
		printf("Key %d\n", key_symbol);
	printf("------------------\nCOMPTEUR MVT : %lld\nCOLLECTIBLES : %d\n", i, data->generate.number_of_C);
	return (key_symbol);
}

// int	ft_key_hook(int key_symbol, t_data *data) // ? v2
// {
// 	static long long int i = 0;
//
// 	if (key_symbol == XK_Escape)
// 	{
// 		printf("Letter ESC | Key %d\n", key_symbol);
// 		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
// 		data->win_ptr = NULL; // fermeture de la fenêtre
// 	}
// 	else if (key_symbol == XK_w)
// 		// TODO ajouter les fonctions lié aux déplacements
// 	else if (key_symbol == 97)
// 		// TODO ajouter les fonctions lié aux déplacements
// 	else if (key_symbol == 115)
// 		// TODO ajouter les fonctions lié aux déplacements
// 	else if (key_symbol == 100)
// 		// TODO ajouter les fonctions lié aux déplacements
// 		printf("Key W, A, S or D : %d\n", key_symbol);
// 	if ()
// 	printf("------------------\nCOMPTEUR MVT : %lld\n", i);
// 	return (key_symbol);
// }


int	ft_no_event(void *data)
{
	return (0);
}
