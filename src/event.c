/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:38:54 by gpeta             #+#    #+#             */
/*   Updated: 2023/04/28 17:19:32 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** Ferme la fenêtre en arrêtant mlx_ptr et win_ptr issue de la structure créée */
int	ft_bouton_red_cross(t_data *data) // voir si on peut combiner dans ft_close_bt_esc
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	return (0);
}

/** Indique le numéro du symbol appuyé + gère les mouvements */
int	ft_key_hook(t_data *data, int key_symbol) // ? v4
{
		// ft_escape_key(data);
	if (key_symbol == 65307)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	else if (key_symbol == XK_w)
	{
		ft_move_up(data);
		data->generate.player.mouvement++;
	}
	else if (key_symbol == XK_a)
	{
		ft_move_left(data);
		data->generate.player.mouvement++;
	}
	else if (key_symbol == XK_s)
	{
		ft_move_down(data);
		data->generate.player.mouvement++;
	}
	else if (key_symbol == XK_d)
	{
		ft_move_right(data);
		data->generate.player.mouvement++;
	}
	ft_print_informations(data);
	return (key_symbol);
}
		// printf("Letter ESC | Key %d\n", key_symbol); // ! a supprimer
		// printf("Letter W | Key %d\n", key_symbol); // ! a supprimer
		// printf("Letter A | Key %d\n", key_symbol); // ! a supprimer
		// printf("Letter S | Key %d\n", key_symbol); // ! a supprimer
		// printf("Letter D | Key %d\n", key_symbol); // ! a supprimer

void	ft_escape_key(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
}

int	render_no_action(t_data *data)
{
	if (data->win_ptr != NULL)
		ft_generate_xpm(data);
	return (0);
}

void	ft_print_informations(t_data *data)
{
	// printf("------------------\nCOMPTEUR MVT : %d\nCOLLECTIBLES : %d\nPLAYER POSITION [%d][%d]\n",
	// data->generate.player.mouvement, data->generate.number_of_C, data->generate.player.pos_y, data->generate.player.pos_x);
	// printf("EXIT POSITION [%d][%d]\n", data->generate.player.pos_exit_y, data->generate.player.pos_exit_x);

	// data->generate.player.mouvement++;

	ft_printf("------------------\nCOMPTEUR MVT : %d\n", data->generate.player.mouvement);
	ft_printf("COLLECTIBLES restant : %d\n", data->generate.number_of_C);
	ft_printf("PLAYER POSITION [%d][%d]\n", data->generate.player.pos_y, data->generate.player.pos_x);
	ft_printf("EXIT POSITION [%d][%d]\n", data->generate.player.pos_exit_y, data->generate.player.pos_exit_x);
	if (data->generate.player.pos_y == data->generate.player.pos_exit_y
		&& data->generate.player.pos_x == data->generate.player.pos_exit_x
		&& data->generate.number_of_C == 0)
		ft_printf("You finish !\n");
}

/** Indique le numéro du symbol appuyé */ // ! a supprimer
// int	ft_key_hook(int key_symbol)
// {
// 	printf("Key %d release\n", key_symbol);
// 	return (0);
// }