/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:38:54 by gpeta             #+#    #+#             */
/*   Updated: 2023/04/27 15:22:58 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** Ferme la fenêtre en arrêtant mlx_ptr et win_ptr issue de la structure créée */
int	ft_bouton_red_cross(t_data *data) // voir si on peut combiner dans ft_close_bt_esc
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL; // fermeture de la fenêtre
	return (0);
}

/** Indique le numéro du symbol appuyé + gère les mouvements */
int	ft_key_hook(int key_symbol, t_data *data) // ? v4
{
	static long long int i = 0;	

	if (key_symbol == 65307)
	{
		printf("Letter ESC | Key %d\n", key_symbol);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL; // fermeture de la fenêtre
	}
	else if (key_symbol == XK_w)
	{
		printf("Letter W | Key %d\n", key_symbol);
		ft_move_up(data);
		// i++;
		data->generate.player.mouvement++;
	}
	else if (key_symbol == XK_a)
	{
		printf("Letter A | Key %d\n", key_symbol);
		ft_move_left(data);
		// i++;
		data->generate.player.mouvement++;
	}
	else if (key_symbol == XK_s)
	{
		printf("Letter S | Key %d\n", key_symbol);
		ft_move_down(data);
		// i++;
		data->generate.player.mouvement++;
	}
	else if (key_symbol == XK_d)
	{
		printf("Letter D | Key %d\n", key_symbol);
		ft_move_right(data);
		// i++;
		data->generate.player.mouvement++;
	}
	else
		printf("Key %d\n", key_symbol);
	// printf("------------------\nCOMPTEUR MVT : %lld\nCOLLECTIBLES : %d\nPLAYER POSITION [%d][%d]\n", i, data->generate.number_of_C, data->generate.player.pos_y, data->generate.player.pos_x);
	printf("------------------\nCOMPTEUR MVT : %d\nCOLLECTIBLES : %d\nPLAYER POSITION [%d][%d]\n", data->generate.player.mouvement, data->generate.number_of_C, data->generate.player.pos_y, data->generate.player.pos_x);
	printf("EXIT POSITION [%d][%d]\n", data->generate.player.pos_exit_y, data->generate.player.pos_exit_x);
	if (data->generate.player.pos_y == data->generate.player.pos_exit_y && data->generate.player.pos_x == data->generate.player.pos_exit_x && data->generate.number_of_C == 0)
		printf("You finish !\n");
	return (key_symbol);
}

int	ft_no_event(void *data)
{
	return (0);
}

int	render_no_action(t_data *data)
{
	if (data->win_ptr != NULL)
		ft_generate_xpm(data);
	return (0);
}
/** Indique le numéro du symbol appuyé */ // ! a supprimer
// int	ft_key_hook(int key_symbol)
// {
// 	printf("Key %d release\n", key_symbol);
// 	return (0);
// }