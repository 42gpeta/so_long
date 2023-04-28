/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:38:54 by gpeta             #+#    #+#             */
/*   Updated: 2023/04/28 20:08:58 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/** Ferme la fenêtre en arrêtant mlx_ptr et win_ptr issue de la structure créée */
int	ft_bouton_red_cross(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	return (0);
}

/** Indique le numéro du symbol appuyé + gère les mouvements */
int	ft_key_hook(int key_symbol, t_data *data)
{
	if (key_symbol == 65307)
		ft_escape_key(data);
	else if (key_symbol == XK_w)
		ft_move_up(data);
	else if (key_symbol == XK_a)
		ft_move_left(data);
	else if (key_symbol == XK_s)
		ft_move_down(data);
	else if (key_symbol == XK_d)
		ft_move_right(data);
	ft_print_informations(data);
	return (key_symbol);
}

/* Destroy window when you press 'esc' */
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
	// ft_printf("PLAYER POSITION [%d][%d]\n", data->generate.player.pos_y, data->generate.player.pos_x);
	// ft_printf("EXIT POSITION [%d][%d]\n", data->generate.player.pos_exit_y, data->generate.player.pos_exit_x);
	ft_printf("-------------\n");
	ft_printf("Number of movements : %d\n", data->generate.player.mouvement);
	if (data->generate.player.pos_y == data->generate.player.pos_exit_y
		&& data->generate.player.pos_x == data->generate.player.pos_exit_x
		&& data->generate.number_of_C == 0)
		ft_printf("\n***\nYou finish !\n***\n\n");
}

/** Indique le numéro du symbol appuyé */ // ! a supprimer
// int	ft_key_hook(t_data *data, int key_symbol)
// {
// 	printf("Key %d release\n", key_symbol);
// 	return (0);
// }